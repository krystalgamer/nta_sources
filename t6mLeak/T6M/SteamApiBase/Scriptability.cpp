#include "STDInc.h"
struct ScriptParseTreeEntry
{
	RawFile rawfile;
	std::string name;
	std::string buffer;
};
struct ScriptHandle
{
	std::string name;
	std::string function;
	bool loaded;
	int handle;
	int handleLoaded;
};
std::vector<ScriptHandle> scriptHandles;
std::map<std::string, ScriptParseTreeEntry> scripParseTreePool;
Hook::Stomp g_ShutdownGame_hook;
Hook::Call loadGameType_hook;
Hook::Call loadGameTypeScript_hook;
DWORD RunCmdSync(const char* cmd, const char* workingDir, char* cmdline)
{
	DWORD result = -1;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcessA(cmd, cmdline, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, workingDir, &si, &pi))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		GetExitCodeProcess(pi.hProcess, &result);
	}

	return result;
}
// Kinda ugly, but that's the most efficient way for now.
void CompileGSCFile(const char* rel, const char* file, std::string &buffer)
{
	buffer.clear();

	std::string compiler = hString::va("%s/UserData/Scriptability/Compiler.exe", FileIO::GetCurrentDir());
	std::string workingDir = hString::va("%s/UserData/Scriptability/", FileIO::GetCurrentDir());
	std::string cmdLine = hString::va("compile \"%s\" \"%s\" temp.dat", rel, file);

	RunCmdSync(compiler.data(), workingDir.data(), (char*)cmdLine.data());

	std::basic_string<unsigned char> _buffer;
	if (FileIO::ReadFileIntoBuffer("UserData/Scriptability/temp.dat", _buffer))
	{
		buffer.append(_buffer.begin(), _buffer.end());
		FileIO::DeleteFile("UserData/Scriptability/temp.dat");
	}
}
XAssetHeader Scr_LoadScriptInternal_Stub(XAssetType type, const char *name, bool errorIfMissing, int waitTime)
{
	XAssetHeader header;
	if (scripParseTreePool.find(name) != scripParseTreePool.end())
	{
		header.rawfile = &scripParseTreePool[name].rawfile;
	}
	else if (Addresses::FS_FileExists(name))
	{
		scripParseTreePool[name] = ScriptParseTreeEntry();
		ScriptParseTreeEntry* entry = &scripParseTreePool[name];
		entry->name = name;
		entry->rawfile.Name = entry->name.data();
		entry->rawfile.Length = Addresses::FS_ReadFile(name, (void**)&entry->rawfile.Buffer);
		entry->buffer.clear();
		entry->buffer.append(entry->rawfile.Buffer, entry->rawfile.Length);

		Addresses::FS_FreeFile(entry->rawfile.Buffer);

		// Determine if GSC is compiled
		if (*(DWORD*)entry->rawfile.Buffer != 0x43534780)
		{
			Addresses::Com_Printf(hString::va("Script '%s' is not compiled. Compiling...\n", entry->name.data()));

			FILE* fp = 0;
			char file[256] = { 0 };
			Addresses::FS_GetFileOsPath(name, file);

			CompileGSCFile(name, file, entry->buffer);

			if (entry->buffer.size() < 4 || *(DWORD*)entry->buffer.data() != 0x43534780)
			{
				std::string message = entry->buffer;
				scripParseTreePool.clear();

				Addresses::Com_Error(ERR_SERVERDISCONNECT, "Script compile error!\n\nFailed to compile '%s'\n%s\n", name, message.data());
			}
		}
		entry->rawfile.Buffer = entry->buffer.data();
		header.rawfile = &entry->rawfile;
	}
	else
	{
		header = Addresses::DB_FindXAssetHeader(type, name, errorIfMissing, waitTime);
	}
	return header;
}
std::vector<std::string> GetScriptList()
{
	std::vector<std::string> scriptList;
	const char* searchPath = (Global::Game::Type == GAME_TYPE_MP ? "scripts/mp/" : "scripts/zm/");

	// Game specific
	Addresses::FS_VectoredListFiles(searchPath, "gsc", FS_LIST_PURE_ONLY, scriptList, true);
	Addresses::FS_VectoredListFiles(searchPath, "csc", FS_LIST_PURE_ONLY, scriptList, true);

	// Both, ZM and MP
	Addresses::FS_VectoredListFiles("scripts/", "gsc", FS_LIST_PURE_ONLY, scriptList, true);
	Addresses::FS_VectoredListFiles("scripts/", "csc", FS_LIST_PURE_ONLY, scriptList, true);

	// TODO: Add support mods using fs_game and probably mods in sub folders
	return scriptList;
}
void LoadCustomScripts()
{
	std::vector<std::string> scriptList = GetScriptList();

	Addresses::Com_Printf(hString::va("Loading scripts (%d):\n", scriptList.size()));

	if (scriptHandles.size() > 0) scriptHandles.clear();

	for (auto script : scriptList)
	{
		const char* entry = script.data();
		if (strlen(entry) < 5 || entry[strlen(entry) - 4] != '.')
		{
			continue;
		}
		else
		{
			char* entryPtr = (char*)entry;
			entryPtr[strlen(entryPtr) - 4] = 0;
		}

		scriptHandles.push_back(ScriptHandle());
		ScriptHandle* handle = &scriptHandles[scriptHandles.size() - 1];

		handle->name = entry;
		handle->function = "init";

		if (Addresses::Scr_LoadScriptInternal(SCRIPTINSTANCE_SERVER, handle->name.data()))
		{
			handle->handle = Addresses::GScr_LoadScriptAndLabel(SCRIPTINSTANCE_SERVER, handle->name.data(), handle->function.data(), &handle->handleLoaded, true);

			// Load main function, if init doesn't exist
			if (!handle->handleLoaded)
			{
				handle->function = "main";
				handle->handle = Addresses::GScr_LoadScriptAndLabel(SCRIPTINSTANCE_SERVER, handle->name.data(), handle->function.data(), &handle->handleLoaded, true);
			}

			handle->loaded = true;
			Addresses::Com_Printf(hString::va("Script '%s' loaded\n", handle->name.data()));
		}
		else
		{
			handle->loaded = false;
			Addresses::Com_Printf(hString::va("Failed to load script '%s'\n", handle->name.data()));
		}
	}
}
void RunCustomScripts()
{
	Addresses::Com_Printf("Executing script threads:");
	for (unsigned int i = 0; i < scriptHandles.size(); i++)
	{
		ScriptHandle* scriptHandle = &scriptHandles[i];

		// Skip non-loaded scripts
		if (!scriptHandle->loaded) continue;

		// Execute handle if found
		if (scriptHandle->handleLoaded)
		{
			int threadhandle = Addresses::Scr_ExecThread(SCRIPTINSTANCE_SERVER, scriptHandle->handle, 0);
			Addresses::Scr_FreeThread(SCRIPTINSTANCE_SERVER, threadhandle);
			Addresses::Com_Printf(hString::va("Executed '%s::%s'\n", scriptHandle->name.data(), scriptHandle->function.data()));
		}
		else
		{
			Addresses::Com_Printf(hString::va("Failed to execute '%s::%s'\n", scriptHandle->name.data(), scriptHandle->function.data()));
		}
	}
}
void __declspec(naked) LoadGameTypeScript_Stub()
{
	LoadCustomScripts();
	__asm jmp loadGameTypeScript_hook._Original
}
void __declspec(naked) LoadGameType_Stub()
{
	RunCustomScripts();
	__asm jmp loadGameType_hook._Original
}
void G_ShutdownGame_Stub(int freeScripts)
{
	//if (freeScripts)
	scripParseTreePool.clear();

	g_ShutdownGame_hook.ReleaseHook();
	Addresses::G_ShutdownGame(freeScripts);
	g_ShutdownGame_hook.InstallHook();
}
void Script::Initialize()
{
	// Allow raw script loading
	QCALL(Addresses::scriptParseTreeLoad1_loc, Scr_LoadScriptInternal_Stub, QPATCH_CALL);
	QCALL(Addresses::scriptParseTreeLoad2_loc, Scr_LoadScriptInternal_Stub, QPATCH_CALL);
	QCALL(Addresses::scriptParseTreeLoad3_loc, Scr_LoadScriptInternal_Stub, QPATCH_CALL);
	QCALL(Addresses::scriptParseTreeLoad4_loc, Scr_LoadScriptInternal_Stub, QPATCH_CALL);

	// Allow precaching after game initialization
	QNOP(Addresses::precacheInitCheck1_loc, 6);
	QNOP(Addresses::precacheInitCheck2_loc, 6);//exceeeded limit of
	QNOP(Addresses::precacheInitCheck3_loc, 6);

	// Load custom scripts
	loadGameTypeScript_hook.Initialize(Addresses::loadGameTypeScript_loc, LoadGameTypeScript_Stub);
	loadGameTypeScript_hook.InstallHook();

	// Execute custom scripts
	loadGameType_hook.Initialize(Addresses::loadGameType_loc, LoadGameType_Stub);
	loadGameType_hook.InstallHook();

	// Clear scriptpool on game shutdown
	g_ShutdownGame_hook.Initialize((DWORD)Addresses::G_ShutdownGame, G_ShutdownGame_Stub);
	g_ShutdownGame_hook.InstallHook();

	// Patch script error handler
	*(BYTE*)Addresses::scriptErrorParam_loc = ERR_SERVERDISCONNECT;

	//Allow loading gsc and csc from data/scripts folder :D
	*(const char**)Addresses::FS_BaseGameFolderName = "data";	//Crash on Loading a game sometimes
}