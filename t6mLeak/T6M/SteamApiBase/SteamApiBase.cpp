#include "STDInc.h"
static BYTE OriginalCode[20];
static PBYTE OriginalEP = 0;
// Unprotect the PE image.
DWORD OriginalProtection = 0;
void PatchGame();

void PatchGame()
{
	Patch();
	memcpy(OriginalEP, OriginalCode, 20);
	__asm jmp OriginalEP;
}
static void UnprotectModule(HMODULE Module)
{
	PIMAGE_DOS_HEADER DOSHeader = (PIMAGE_DOS_HEADER)Module;
	PIMAGE_NT_HEADERS NTHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)Module + DOSHeader->e_lfanew);
	SIZE_T Size = NTHeader->OptionalHeader.SizeOfImage;

	VirtualProtect((void *)Module, Size, PAGE_EXECUTE_READWRITE, &OriginalProtection);
}
// Find the EP, set access and replace it.
void SafeInit()
{
	HMODULE Module = GetModuleHandle(NULL);

	if (Module)
	{
		PIMAGE_DOS_HEADER DOSHeader = (PIMAGE_DOS_HEADER)Module;
		PIMAGE_NT_HEADERS NTHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)Module + DOSHeader->e_lfanew);

		UnprotectModule(Module);

		// Backup.
		PBYTE EP = (PBYTE)((DWORD_PTR)Module + NTHeader->OptionalHeader.AddressOfEntryPoint);
		OriginalEP = EP;
		memcpy(OriginalCode, EP, 20);
		memset(EP, 0x90, 20);

		// Patch the original entrypoint.
		uint32_t NewEP = (uint32_t)PatchGame - ((uint32_t)EP + 5);
		EP[0] = 0xE9; // jmp
		*(uint32_t *)&EP[1] = NewEP;
	}
}
// Entrypoint.
BOOL __stdcall DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		Log::Init("UserData/PlusOpsII.log", LogLevel_All);
		Log::Info("SteamApiBase", "Starting up..");
		// Patch the entrypoint.
		SafeInit();
	}
	return TRUE;
}