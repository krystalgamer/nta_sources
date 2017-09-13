#include "STDInc.h"
Hook::Stomp MainPatchFunctions::HKS_MaterialHook;
Hook::Stomp MainPatchFunctions::HKS_StringHook;
Hook::Stomp MainPatchFunctions::HKS_RawfileHook;
Hook::Stomp MainPatchFunctions::ScriptParseHook;
Hook::Stomp MainPatchFunctions::LoadCustomWeaponAsset;


void __declspec(naked) MainPatchFunctions::XAssetStub(ScriptParseTree** scriptParseTree)
{
	__asm
	{
		push esi;
		_emit 0x8B;
		_emit 0x74;
		_emit 0x24;
		_emit 0x08;
		mov eax, [esi];
		push eax;
		mov eax, 0x30;
		call Addresses::DB_AddXAssetLoc;
		add esp, 4;
		mov[esi], eax;
		pop esi;
		retn;
	}
}
const char* MainPatchFunctions::HKS_ReturnString(const char* Name)
{
	//Log::Info("HKS_ReturnString", Name);
	if (!strcmp(Name, "PLATFORM_SYSTEM_LINK_GAMES_CAPS"))
		return "LAN Servers";
	if (!strcmp(Name, "PLATFORM_SYSTEM_LINK_CAPS"))
		return "Offline mode";
	if (!strcmp(Name, "MENU_CREATE_GAME_CAPS"))
		return "Create game";
	if (!strcmp(Name, "MENU_JOIN_GAME_CAPS"))
		return "Join LAN";
	if (!strcmp(Name, "PLATFORM_XBOXLIVE_INSTR"))
		return "Online mode";
	if (!strcmp(Name, "MENU_MULTIPLAYER_CAPS"))
		return "Multiplayer";
	if (!strcmp(Name, "MENU_LEAGUE_PLAY_CAPS"))
		return "^8UnusedItem";
	if (!strcmp(Name, "MENU_SINGLEPLAYER_CAPS"))
		return "Singleplayer";
	if (!strcmp(Name, "MENU_ZOMBIE_CAPS"))
		return "Zombiemode";
	if (!strcmp(Name, "MENU_QUIT_CAPS"))
		return "Quit";
	if (!strcmp(Name, "MENU_OPTIONS_CAPS"))
		return "Sys options";
	if (!strcmp(Name, "MENU_CUSTOMGAMES_CAPS"))
		return "Custom game";
	if (!strcmp(Name, "MENU_INGAMESTORE"))
		return "^8UnusedItem";
	if (!strcmp(Name, "MENU_MESSAGE_OF_THE_DAY"))
		return "A Message from the Sonsored Team:";
	if (!strcmp(Name, "MENU_MATCHMAKING_CAPS"))
		return "Matchmaking";
	if (!strcmp(Name, "MENU_THEATER_CAPS"))
		return "Theater";
	if (!strcmp(Name, "MENU_BARRACKS_CAPS"))
		return "Barracks";
	if (!strcmp(Name, "MENU_COD_TV_CAPS"))
		return "Shared media";
	if (!strcmp(Name, "MPUI_FIND_MATCH_CAPS"))
		return "Find match";
	if (!strcmp(Name, "MENU_CREATE_A_CLASS_CAPS"))
		return "Create a class";
	if (!strcmp(Name, "MENU_SCORE_STREAKS_CAPS"))
		return "Scorestreaks";
	if (!strcmp(Name, "MENU_LIVESTREAMING_CAPS"))
		return "Live stream";
	if (!strcmp(Name, "MPUI_START_MATCH_CAPS"))
		return "Start match";
	if (!strcmp(Name, "MPUI_SETUP_GAME_CAPS"))
		return "Setup game";
	if (!strcmp(Name, "MENU_SETUP_BOTS_CAPS"))
		return "Setup bots";
	if (!strcmp(Name, "CUSTOM_GAME_RECORDING_CAPS"))
		return "Game recording";
	if (!strcmp(Name, "MPUI_END_GAME_CAPS"))
		return "End game";
	if (!strcmp(Name, "MPUI_LOBBY_LEADERBOARD_CAPS"))
		return "Lobby leaderboard";
	if (!strcmp(Name, "MP_MATCH_STARTING_IN"))
		return "^1Match starting in";
	if (!strcmp(Name, "PLATFORM_STEAM_OFFLINE"))
		return "Sonsored is currently in offline mode.";
	if (!strcmp(Name, "MPUI_CHOOSE_CLASS_BUTTON_CAPS"))
		return "Choose class";
	if (!strcmp(Name, "MENU_END_GAME_CAPS"))
		return "End game";
	if (!strcmp(Name, "MENU_TWITCH_LOGIN"))
		return "Sonsored Login";
	if (!strcmp(Name, "ZMUI_MAP_CAPS"))
		return "Map";
	if (!strcmp(Name, "ZMUI_DIFFICULTY_CAPS"))
		return "Difficulty";
	if (!strcmp(Name, "ZMUI_DIFFICULTY_EASY_CAPS"))
		return "Easy";
	if (!strcmp(Name, "ZMUI_DIFFICULTY_NORMAL_CAPS"))
		return "Normal";
	if (!strcmp(Name, "ZMUI_DIFFICULTY_HARD_CAPS"))
		return "Hard";
	if (!strcmp(Name, "MENU_PLAYERS_ONLINE"))
	{
		if (!Global::Game::Offline)
		{
			
			return hString::va("%i Online",Global::Variables::Onlines);
		}
		return "Offline";
	}
	if (!strcmp(Name, "MENU_CONNECTING_DW"))
		return "Connecting to Sonsored Server";
	if (!strcmp(Name, "PLATFORM_GETTING_STEAM_TICKET"))
		return "Fetching steam Ticket";
	if (!strcmp(Name, "MENU_BACK"))
		return "to go Back";
	if (!strcmp(Name, "EXE_AWAITINGCHALLENGE"))
		return "Awaiting Challenge";
	if (!strcmp(Name, "EXE_AWAITINGGAMESTATE"))
		return "Waiting for Game State";
	if (!strcmp(Name, "EXE_AWAITINGCONNECTION"))
		return "Waiting for Connections";
	if (!strcmp(Name, "EXE_AWAITINGHOST"))
		return "Waiting for Host";
	if (!strcmp(Name, "EXE_AWAITINGTEXTURES"))
		return "Loading Textures";
	if (!strcmp(Name, "EXE_UPLOADINGSTATS"))
		return "Uploading Stats to Server";
	if (!strcmp(Name, "EXE_SYNCHRONIZING"))
		return "Reading Server Sync Buffer";
	if (!strcmp(Name, "EXE_LOADING_CLIP"))
		return "Loading Clip";
	if (!strcmp(Name, "EXE_LOADING_FILM"))
		return "Loading Film";



	LocalizeEntry* LocalEntry = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_LOCALIZE_ENTRY, Name, true, -1).localize;
	if (LocalEntry)
		return LocalEntry->value;
	return 0;
}
bool MainPatchFunctions::HKS_RegisterMaterial(const char *Name, Material **Out)
{
	//Log::Info("DB_FindXAssetHeader", Name);
	if (Global::Game::Type == GameType::GAME_TYPE_MP)
	{
		if (!strcmp(Name, "menu_mp_soldiers"))
		{
			*Out = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, "lui_bkg", true, -1).material;
			return true;
		}
	}
	else
	{
		if (!strcmp(Name, "lui_bkg_zm_sun"))
		{
			Material* a1 = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, "lui_bkg_zm_sun", true, -1).material;
			Material* a2 = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, "menu_zm_cac_backing", true, -1).material;
			
			//*(DWORD*)((*(DWORD*)((*(DWORD*)((DWORD)a1->textureTable->image->basemap.a1 + 88)) + 12)) + 0xAC) = /*308*//*426*//*894*/894;




			//convert to void*
			//void* a3 = (void*)((DWORD)a1->textureTable->image->basemap.a1 + 88);
			//void* a4 = (void*)((DWORD)a2->textureTable->image->basemap.a1 + 88);
			//memcpy(a3, a4, 4);




			//void* a3 = (void*)((*(DWORD*)((DWORD)a1->textureTable->image->basemap.a1 + 88)) + 12);
			//void* a4 = (void*)((*(DWORD*)((DWORD)a2->textureTable->image->basemap.a1 + 88)) + 12);
			//memcpy(a3, a4, 4);



			//GfxImage* a3 = *(GfxImage**)a2->textureTable->image;
			//InGameConsole::Log(a3->name);


			//DWORD a = (DWORD)a1->textureTable->image->basemap.a1 + 88;
			//DWORD b = *(DWORD*)a;
			//DWORD c = b + 12;
			//DWORD d = *(DWORD*)c;
			//DWORD e = d + 0xAC;
			//*(DWORD*)e = 308;
			//InGameConsole::Log(hString::va("Material location = %lx", e));





			//check if this is in GfxImage  and yhea   d3dbasetexture is not pointered so gfximage is  0x42 + the own size    try to find this shit out so i only need to use  GfxImage->..... = ...
			//*(DWORD*)((*(DWORD*)((*(DWORD*)((DWORD)a1->textureTable->image->basemap.a1 + 88)) + 12)) + 0xAC) = /*308*/426;
			


			*Out = a1;
			//*Out = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, "menu_zm_cac_backing", true, -1).material;
			return true;
		}
	}
	// Return the requested texture.
	*Out = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, Name, true, -1).material;
	return true;
}
void* MainPatchFunctions::HKS_LoadRawfile(const char *Filename)
{
	//Log::Info("HKS_LoadRawfile", Filename);

	RawFile *Result = nullptr;
	char FilePath[256];

	// Lowercase to make it easier for check.
	for (size_t i = 0; i < strlen(Filename) + 1; i++)
		FilePath[i] = tolower(Filename[i]);

	// If the path contains 'Nemexis' then we'll load it from disk.
	if (strstr(FilePath, "Sonsored"))
	{
		FILE *F = NULL;

		// Open the requested file or die.
		F = fopen(Filename, "rb");
		if (F == NULL) return Result;

		// As the file exists, create our result.
		Result = new RawFile;
		Result->Name;
		Result->Length = 0;
		Result->Buffer = nullptr;

		// Get filesize.
		fseek(F, 0, SEEK_END);
		Result->Length = ftell(F);
		rewind(F);

		// Allocate the buffer in memory.
		// As we don't have a file management system in this DLL
		// there will be some memory leaks =(
		Result->Buffer = (const char *)GlobalAlloc(GPTR, Result->Length);

		// Read and close the file.
		fread((void *)Result->Buffer, 1, Result->Length, F);
		fclose(F);
	}
	else
	{
		Result = (RawFile*)Addresses::DB_FindXAssetHeader(ASSET_TYPE_RAWFILE, Filename, 0, 0).data;
	}
	return Result;
}
void MainPatchFunctions::Load_ScriptParseTreeAsset(ScriptParseTree** scriptParseTree)
{
	//Log::Info("Load_ScriptParseTreeAsset", (*scriptParseTree)->name);
#pragma region ZOMBIES8PLAYER
	if (!strcmp((*scriptParseTree)->name, "maps/mp/zombies/_zm.gsc"))
	{
		Log::Info("Load_ScriptParseTreeAsset", "maps/mp/zombies/_zm.gsc Moding");
		BYTE* gscBuffer = (*scriptParseTree)->buffer;
		COD9_GSC* gsc = (COD9_GSC*)gscBuffer;
		gscFunction* currentFunction = (gscFunction*)(gscBuffer + gsc->gscFunctions);
		for (WORD i = 0; i < gsc->numOfFunctions; currentFunction++, i++)
		{
			if (!strcmp((const char*)(gscBuffer + currentFunction->name), "player_too_many_players_check"))
			{
				// Return player_too_many_players_check.
				*(BYTE*)(gscBuffer + currentFunction->start) = 0x00; // = OP_End
				break;
			}
		}
	}
#pragma endregion
	// Return the requested GSC.
	return MainPatchFunctions::XAssetStub(scriptParseTree);
}
WeaponVariantDef* MainPatchFunctions::Load_WeaponAsset(const char* WeaponName)
{
	WeaponVariantDef* result = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPON, WeaponName, true, -1).weapon;
	if (result)
	{
		if (!strcmp(WeaponName, "ballista_mp"))
		{
			DWORD WeaponDef = (*(DWORD*)result) + 0x0F; // Why the Hack is it 0x0F bytes different then on my RTM hack?
			
			*(DWORD*)(WeaponDef + 0x3E4) = 999999;
			//*(DWORD*)(WeaponDef + 0x3E8) = 999999;
			//*(DWORD*)(WeaponDef + 0x3EC) = 999999;
			//*(DWORD*)(WeaponDef + 0x3F0) = 999999;
			//*(DWORD*)(WeaponDef + 0x3F4) = 999999;
		}
		if (!strcmp(WeaponName, "mp7_mp"))
		{
			result->szDisplayName = "AK74u";



			//Testing
			//InGameConsole::Log(hString::va("result->weapDef->gunXModel 0x%lx\n", result->weapDef->gunXModel));
			//InGameConsole::Log(hString::va("result->weapDef->gunXModel->numsurfs 0x%lx\n", result->weapDef->gunXModel->numsurfs));
			//InGameConsole::Log(hString::va("result->weapDef->gunXModel->numBones 0x%lx\n", result->weapDef->gunXModel->numBones));
			//InGameConsole::Log(hString::va("result->weapDef->gunXModel->numRootBones 0x%lx\n", result->weapDef->gunXModel->numRootBones));

			//isnt it XModel** ? ahh who cares!
			XModel* ReplaceXModel = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_WEAPON, "pdw57_mp", true, -1).weapon->weapDef->gunXModel;
			result->weapDef->gunXModel = ReplaceXModel;
		}
	}
	else
		result = 0;
	return result;
}