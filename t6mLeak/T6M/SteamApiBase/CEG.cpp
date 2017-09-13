#include "STDInc.h"
#include "CEG.h"

int CegHandler::unkHandlerShit;
char CegHandler::zone_file_mem2[16];
void* CegHandler::zone_file_mem;




Hook::Call CegHandler::cegMemcpyHook;
DWORD CegHandler::cegMemcpyHookLoc;
DWORD CegHandler::OldContextRecord = 0;

void CegHandler::sub_1002F5A0(PCONTEXT a1)
{
	a1->Dr0 = 0;
	a1->Dr1 = 0;
	a1->Dr2 = 0;
	a1->Dr3 = 0;
	a1->Dr7 &= 0xFFFFFFAA;
}
int CegHandler::sub_1002F5E0(DWORD* a1, char a2, char a3, int a4)
{
	*(DWORD*)a1 = (a4 << a2) | *(DWORD*)a1 & ~(((1 << a3) - 1) << a2);
	return a4 << a2;
}
void CegHandler::sub_1002F620(PCONTEXT ContextRecord, DWORD OldContextRecord)
{
	int v2; // ecx@7
	int v3; // eax@15
	char v4; // [sp+Ch] [bp-114h]@1
	int v5; // [sp+D0h] [bp-50h]@18
	int v6; // [sp+DCh] [bp-44h]@18
	int v7; // [sp+E8h] [bp-38h]@10
	unsigned __int8 v8; // [sp+F7h] [bp-29h]@1
	char v9; // [sp+103h] [bp-1Dh]@1
	char v10; // [sp+10Fh] [bp-11h]@1
	char v11; // [sp+11Bh] [bp-5h]@1

	v11 = 0;
	v10 = 0;
	v9 = 0;
	v8 = 0;
	if (ContextRecord->Dr7 & 1)
		v11 = 1;
	if (ContextRecord->Dr7 & 4)
		v10 = 1;
	if (ContextRecord->Dr7 & 0x10)
		v9 = 1;
	v2 = ContextRecord->Dr7 & 0x40;
	if (v2)
		v8 = 1;
	if (v11)
	{
		if (v10)
		{
			if (v9)
			{
				v3 = v8;
				if (v8)
					return;
				ContextRecord->Dr3 = OldContextRecord;
				v8 = 1;
				v7 = 3;
			}
			else
			{
				ContextRecord->Dr2 = OldContextRecord;
				v9 = 1;
				v7 = 2;
			}
		}
		else
		{
			ContextRecord->Dr1 = OldContextRecord;
			v10 = 1;
			v7 = 1;
		}
	}
	else
	{
		ContextRecord->Dr0 = OldContextRecord;
		v11 = 1;
		v7 = 0;
	}
	ContextRecord->Dr6 = 0;
	v6 = 0;
	v5 = 0;

	sub_1002F5E0(&ContextRecord->Dr7, 4 * v7 + 16, 2, 0);
	sub_1002F5E0(&ContextRecord->Dr7, 4 * v7 + 18, 2, v5);
	v3 = sub_1002F5E0(&ContextRecord->Dr7, 2 * v7, 1, 1);
}
LONG WINAPI CegHandler::CEG_CompleteTrap(LPEXCEPTION_POINTERS ExceptionInfo)
{
	if (ExceptionInfo->ExceptionRecord->ExceptionCode == 0x80000004)
	{
		if (ExceptionInfo->ContextRecord->Eip == OldContextRecord)
		{
			ExceptionInfo->ContextRecord->Esp -= 4;
			*(DWORD*)ExceptionInfo->ContextRecord->Esp = ExceptionInfo->ContextRecord->Eip;
			ExceptionInfo->ContextRecord->Eip = unkHandlerShit;
			sub_1002F5A0(ExceptionInfo->ContextRecord);
			OldContextRecord = 0;
			return EXCEPTION_CONTINUE_EXECUTION;
		}
		else if (*(BYTE*)ExceptionInfo->ContextRecord->Eip != 0x83 || *(BYTE*)(ExceptionInfo->ContextRecord->Eip + 1) != 0xC4)
		{
			return EXCEPTION_CONTINUE_SEARCH;
		}
		else
		{
			OldContextRecord = *(DWORD*)(ExceptionInfo->ContextRecord->Ebp + 4);
			sub_1002F5A0(ExceptionInfo->ContextRecord);
			sub_1002F620(ExceptionInfo->ContextRecord, OldContextRecord);
			return EXCEPTION_CONTINUE_EXECUTION;
		}
	}
	else if (ExceptionInfo->ExceptionRecord->ExceptionCode == 0x40101010)
	{
		sub_1002F620(ExceptionInfo->ContextRecord, ExceptionInfo->ExceptionRecord->ExceptionInformation[0]);
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	return EXCEPTION_CONTINUE_SEARCH;
}
void __stdcall CegHandler::cegRaiseException(ULONG_PTR Arguments)
{
	RaiseException(0x40101010u, 0, 1, &Arguments);
}
void CegHandler::MemcpyHook(LPVOID lpAddress, const void *Src, SIZE_T dwSize)
{
	DWORD flOldProtect;
	VirtualProtect(lpAddress, dwSize, 0x40u, &flOldProtect);
	memcpy(lpAddress, Src, dwSize);
}
void __stdcall CegHandler::cegZoneLoc(int ZoneMemLoc)
{
	Log::Error("ZONE FILE", "%lx", ZoneMemLoc);
	int CegZoneFile = 0; // Only used for Pointer Saving.(else we need memset and .... char array this way is so easy :D)
	int CegZoneFileSize = 0;
	if (Global::Game::Type == GameType::GAME_TYPE_ZM && Global::Game::Version == GameVersion::GAME_VERSION_39)
	{
		// Why + 3?
		switch (ZoneMemLoc + 3)
		{
		case 0x004B5927:
			CegZoneFile = (int)ZONE_004B5927;
			CegZoneFileSize = 0x428;
			break;
		case 0x005B0C54:
			CegZoneFile = (int)ZONE_005B0C54;
			CegZoneFileSize = 0x4D8;
			break;
		case 0x006BA817:
			CegZoneFile = (int)ZONE_006BA817;
			CegZoneFileSize = 0x5A8;
			break;
		case 0x006C1C82:
			CegZoneFile = (int)ZONE_006C1C82;
			CegZoneFileSize = 0x468;
			break;
		case 0x0058E533:
			CegZoneFile = (int)ZONE_0058E533;
			CegZoneFileSize = 0x1D8;
			break;
		case 0x0058F0C3:
			CegZoneFile = (int)ZONE_0058F0C3;
			CegZoneFileSize = 0x6E8;
			break;
		case 0x00524397:
			CegZoneFile = (int)ZONE_00524397;
			CegZoneFileSize = 0x548;
			break;
		}
	}
	if (Global::Game::Type == GameType::GAME_TYPE_ZM && Global::Game::Version == GameVersion::GAME_VERSION_41)
	{
		switch (ZoneMemLoc)
		{
		case 0x00513714:
			CegZoneFile = (int)ZONE_00513714;
			CegZoneFileSize = 0x1D68;
			break;
		case 0x004AEBD0:
			CegZoneFile = (int)ZONE_004AEBD0;
			CegZoneFileSize = 0x4D8;
			break;
		case 0x006CF8C1:
			CegZoneFile = (int)ZONE_006CF8C1;
			CegZoneFileSize = 0x548;
			break;
		case 0x00558924:
			CegZoneFile = (int)ZONE_00558924;
			CegZoneFileSize = 0x5A8;
			break;
		case 0x0042E4E1:
			CegZoneFile = (int)ZONE_0042E4E1;
			CegZoneFileSize = 0x6228;
			break;
		case 0x004F537E:
			CegZoneFile = (int)ZONE_004F537E;
			CegZoneFileSize = 0x6E8;
			break;
		case 0x00702B81:
			CegZoneFile = (int)ZONE_00702B81;
			CegZoneFileSize = 0x1D8;
			break;
		case 0x005459E0:
			CegZoneFile = (int)ZONE_005459E0;
			CegZoneFileSize = 0x428;
			break;
		case 0x00580E84:
			CegZoneFile = (int)ZONE_00580E84;
			CegZoneFileSize = 0x8598;
			break;
		case 0x005F6DD4:
			CegZoneFile = (int)ZONE_005F6DD4;
			CegZoneFileSize = 0x7D8;
			break;
		case 0x006DD704:
			CegZoneFile = (int)ZONE_006DD704;
			CegZoneFileSize = 0x468;
			break;
		}
	}
	if (Global::Game::Type == GameType::GAME_TYPE_MP && Global::Game::Version == GameVersion::GAME_VERSION_40)
	{
		switch (ZoneMemLoc)
		{
		case 0x0060B3F1://0060B3F4
			CegZoneFile = (int)ZONE_0060B3F4;
			CegZoneFileSize = 0x61E8;
			break;
		case 0x0064CA64:
			CegZoneFile = (int)ZONE_0064CA64;
			CegZoneFileSize = 0x468;
			break;
		case 0x00573DA4:
			CegZoneFile = (int)ZONE_00573DA4;
			CegZoneFileSize = 0x5A8;
			break;
		case 0x00493C30:
			CegZoneFile = (int)ZONE_00493C30;
			CegZoneFileSize = 0x4D8;
			break;
		case 0x004D5BF4:
			CegZoneFile = (int)ZONE_004D5BF4;
			CegZoneFileSize = 0x8578;
			break;
		case 0x005BB001:
			CegZoneFile = (int)ZONE_005BB001;
			CegZoneFileSize = 0x1D8;
			break;
		case 0x00495361:
			CegZoneFile = (int)ZONE_00495361;
			CegZoneFileSize = 0x548;
			break;
		case 0x005206CE:
			CegZoneFile = (int)ZONE_005206CE;
			CegZoneFileSize = 0x6E8;
			break;
		case 0x00685784:
			CegZoneFile = (int)ZONE_00685784;
			CegZoneFileSize = 0x1DD8;
			break;
		case 0x006F11A4:
			CegZoneFile = (int)ZONE_006F11A4;
			CegZoneFileSize = 0x698;
			break;
		case 0x00667250:
			CegZoneFile = (int)ZONE_00667250;
			CegZoneFileSize = 0x428;
			break;
		}
	}
	if (Global::Game::Type == GameType::GAME_TYPE_MP && Global::Game::Version == GameVersion::GAME_VERSION_43)
	{
		switch (ZoneMemLoc)
		{
		case 0x0052F174://0x0052F177
			CegZoneFile = (int)ZONE_0052F177;
			CegZoneFileSize = 0x388;
			break;
		case 0x0057FEEE:
			CegZoneFile = (int)ZONE_0057FEEE;
			CegZoneFileSize = 0x6E8;
			break;
		case 0x00519424:
			CegZoneFile = (int)ZONE_00519424;
			CegZoneFileSize = 0x1E58;
			break;
		case 0x0067F2C0:
			CegZoneFile = (int)ZONE_0067F2C0;
			CegZoneFileSize = 0x428;
			break;
		case 0x004167F4:
			CegZoneFile = (int)ZONE_004167F4;
			CegZoneFileSize = 0x5A8;
			break;
		case 0x00673501:
			CegZoneFile = (int)ZONE_00673501;
			CegZoneFileSize = 0x548;
			break;
		case 0x00607E01:
			CegZoneFile = (int)ZONE_00607E01;
			CegZoneFileSize = 0x698;
			break;
		case 0x005FA6C1:
			CegZoneFile = (int)ZONE_005FA6C1;
			CegZoneFileSize = 0x1D8;
			break;
		case 0x004AAF71:
			CegZoneFile = (int)ZONE_004AAF71;
			CegZoneFileSize = 0x848;
			break;
		case 0x0065CE31:
			CegZoneFile = (int)ZONE_0065CE31;
			CegZoneFileSize = 0x6228;
			break;
		case 0x004FA9B4:
			CegZoneFile = (int)ZONE_004FA9B4;
			CegZoneFileSize = 0x468;
			break;
		case 0x00896E34:
			CegZoneFile = (int)ZONE_00896E34;
			CegZoneFileSize = 0x488;
			break;
		case 0x005D2694:
			CegZoneFile = (int)ZONE_005D2694;
			CegZoneFileSize = 0x8578;
			break;
		case 0x00695FA0:
			CegZoneFile = (int)ZONE_00695FA0;
			CegZoneFileSize = 0x4D8;
			break;
		}
	}
	if (!CegZoneFile)
	{
		MessageBoxA(0, hString::va("Could not find static for %lx. Terminating application.", ZoneMemLoc), "Error", 0x10u);
		ExitProcess(0x63);
	}




	zone_file_mem = *(void**)CegZoneFile;
	*(DWORD*)zone_file_mem2 = *(DWORD*)(CegZoneFile + 4);
	*(DWORD*)&zone_file_mem2[4] = *(DWORD*)(CegZoneFile + 8);
	*(DWORD*)&zone_file_mem2[8] = *(DWORD*)(CegZoneFile + 12);
	*(DWORD*)&zone_file_mem2[12] = *(DWORD*)(CegZoneFile + 16);
	memmove(zone_file_mem, (const void*)(CegZoneFile + 20), CegZoneFileSize - 20);
}
__declspec(naked) void CegHandler::CEGEx1HookStub()
{
	__asm
	{
		mov     eax, [ebp + 4]
			push    eax
			call    CegHandler::cegZoneLoc

			mov     eax, offset CegHandler::zone_file_mem2
			push    10h
			push    eax
			mov     eax, [esp + 10h]
			push    eax
			call    memmove
			add     esp, 0Ch

			mov     eax, offset CegHandler::zone_file_mem2
			push    eax
			mov     eax, CegHandler::zone_file_mem
			push    eax
			call    CegHandler::cegMemcpyHook._Original

			add     esp, 8
			mov     CegHandler::unkHandlerShit, eax
			mov     eax, [ebp + 4]
			push    eax
			call    CegHandler::cegRaiseException
			retn
	}
}

//MessageBoxA(0, hString::va("%lx", ExceptionInfo->ContextRecord->Eax), 0, 0);
void CegHandler::AddFPFixup(DWORD Address, DWORD Address2)
{
	QMOV(Address, Address2);
}
void CegHandler::Initialize()
{
	CegHandler::cegMemcpyHookLoc = (uint32_t)Patterns::FindPattern((uint8_t*)"\xE8\x3F\x3F\x3F\x3F\x8B\x56\x08\x8B\x46\x0C\x8B\x4E\x04", "x????xxxxxxxxx");
	QCALL(CegHandler::cegMemcpyHookLoc, CegHandler::MemcpyHook, QPATCH_CALL);

	// Some obfuscated function, need to investigate it.
	QCALL((uint32_t)Patterns::FindPattern((uint8_t*)"\x8B\x44\x24\x18\x8B\x4C\x24\x14\x50\x51\x53", "xxxxxxxxxxx") + 13, (uint32_t)Patterns::FindPattern((uint8_t*)"\xC7\x86\x80\x00\x00\x00\x00\x01\x00\x00", "xxxxxxxxxx") - 0x5F, QPATCH_CALL);

	//Obfuscation destructor
	Patterns::FindPattern((uint8_t*)"\x56\x8B\xF1\x83\x7E\x08\x00\x74\x4B\x8B\x46\x04", "xxxxxxxxxxxx")[0] = 0xC3;

	cegMemcpyHook._Original = (LPVOID)(CegHandler::cegMemcpyHookLoc - 0x2E);
	Patterns::FindPattern((uint8_t*)"\x55\x8B\xEC\x8B\x45\x08\x83\x38\x00\x75\x04", "xxxxxxxxxxx")[0] = 0xC3;
	AddVectoredExceptionHandler(1, CegHandler::CEG_CompleteTrap);

	//Remove STEAM_DIPC_CONSUME request's
	Patterns::FindPattern((uint8_t*)"\x83\xEC\x48\x53\x55\x56\x57\x6A\x01\x8D\x44\x24\x34\x50\xFF\x15", "xxxxxxxxxxxxxxxx")[0] = 0xC3;
	Patterns::FindPattern((uint8_t*)"\x83\xEC\x48\x53\x55\x56\x57\x6A\x01\x8D\x44\x24\x34\x50\x33\xED", "xxxxxxxxxxxxxxxx")[0] = 0xC3;

	// SetUnhandledExceptionFilter function with push
	memset((void*)(uint32_t)Patterns::FindPattern((uint8_t*)"\x68\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xC6\x05", "x????xx????x????x????xx"), 0x90, 9);


	if (Global::Game::Type == GameType::GAME_TYPE_ZM)
	{
		if (Global::Game::Version == GameVersion::GAME_VERSION_39)
		{
			Setup_V39CEG();
		}
		else if (Global::Game::Version == GameVersion::GAME_VERSION_41)
		{
			Setup_V41CEG();
		}
		else if (Global::Game::Version == GameVersion::GAME_VERSION_41)
		{
			Setup_V43_ZM_CEG();
		}
	}
	else if (Global::Game::Type == GameType::GAME_TYPE_MP)
	{
		if (Global::Game::Version == GameVersion::GAME_VERSION_40)
		{
			Setup_V40CEG();
		}
		else if (Global::Game::Version == GameVersion::GAME_VERSION_43)
		{
			Setup_V43CEG();
		}
	}
	CegHandler::Signatures();
}
void CegHandler::Setup_V39CEG()
{
	// Decryption calls.
	QCALL(0x43D2B7, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x497906, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4A6D57, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5603FF, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5CBAC6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x6381DF, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x64456F, CEGEx1HookStub, QPATCH_CALL);


	*(BYTE*)0x99E3C0 = 0xC3;
	*(BYTE*)0x85E040 = 0xC3;
	memset((void*)0x6DA34F, 0x90, 9);// SetUnhandledExceptionFilter(TopLevelExceptionFilter);  do pattern
	QMOV(0x61E3D0, 0x498BA0);
	QMOV(0x4E9AB0, 0x4D3F60);
	*(BYTE*)0x5F6AFB = 0xEB;
	*(BYTE*)0x46DF20 = 0xC3;
	*(BYTE*)0x5D2E20 = 0xC3;
	QNOP(0x45ED26, 6);
}
void CegHandler::Setup_V40CEG()
{
	// Decryption calls.
	QCALL(0x6EF746, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x66934F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5DEBC6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5A51D7, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x57060F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x56BD21, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x51D236, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4FE476, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x42E3CF, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x418716, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x40514F, CEGEx1HookStub, QPATCH_CALL);

	// Destroyed functionpointers.
	CegHandler::AddFPFixup(0x42DF20, 0x697790);
	CegHandler::AddFPFixup(0x448C50, 0x97DF40);
	CegHandler::AddFPFixup(0x4EEF20, 0x979140);
	CegHandler::AddFPFixup(0x4FAD30, 0x5A09A0);
	CegHandler::AddFPFixup(0x59FC70, 0x417930);
	CegHandler::AddFPFixup(0x60BFA0, 0x4A6770);
	CegHandler::AddFPFixup(0x700450, 0x668210);
}
void CegHandler::Setup_V41CEG()
{
	// Decryption calls.
	QCALL(0x461691, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x51D36F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x522EF1, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x53CF66, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5563E6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5677DF, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x56C4F6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x575D1F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5E7947, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5F4E87, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x63A866, CEGEx1HookStub, QPATCH_CALL);

	//*(BYTE*)0x9ADCC0 = 0xC3;//unk  do pattern
	//*(BYTE*)0x86AED0 = 0xC3;//unk  do pattern


	// Destroyed functionpointers.
	CegHandler::AddFPFixup(0x483C30, 0x7CBFF0);
	CegHandler::AddFPFixup(0x4F91D0, 0x491500);
	CegHandler::AddFPFixup(0x58D240, 0x54EA20);
	CegHandler::AddFPFixup(0x5AB9F0, 0x7CF200);
	CegHandler::AddFPFixup(0x5B8D80, 0x67E970);
	CegHandler::AddFPFixup(0x5B8F70, 0x6A2810);
	CegHandler::AddFPFixup(0x647B50, 0x97C690);
	CegHandler::AddFPFixup(0x64B970, 0x41AEB0);
	CegHandler::AddFPFixup(0x6695A0, 0x7CF330);
	CegHandler::AddFPFixup(0x6D4860, 0x9778B0);
	CegHandler::AddFPFixup(0x6F3900, 0x7D0340);
	CegHandler::AddFPFixup(0x6DEF50, 0x5CC4C0);
	CegHandler::AddFPFixup(0x65CE60, 0x659350);

	//*(BYTE*)0x46049B = 0xEB;//unk  find it out wut its :D
	//*(BYTE*)0x4F6F10 = 0xC3;//unk  find it out wut its :D
	//*(BYTE*)0x665410 = 0xC3;//unk  find it out wut its :D
	//QNOP(0x0572AD6, 6);//unk  find it out wut its :D
}
void CegHandler::Setup_V43CEG()
{
	// Decryption calls.
	QCALL(0x405BB6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x43C95F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4C7BB1, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4D473F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4ED447, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4FECF6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x50490F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x510CE6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x564DE6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5FD8E7, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x680461, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x6B80A1, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x6D3526, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x6F2D8F, CEGEx1HookStub, QPATCH_CALL);

	// Destroyed functionpointers.
	CegHandler::AddFPFixup(0x41FCA0, 0x4A1620);
	CegHandler::AddFPFixup(0x461F20, 0x5B8620);
	CegHandler::AddFPFixup(0x492FF0, 0x980220);
	CegHandler::AddFPFixup(0x49C6C0, 0x7CF040);
	CegHandler::AddFPFixup(0x4AE6F0, 0x6A1DB0);
	CegHandler::AddFPFixup(0x4D8CE0, 0x608A20);
	CegHandler::AddFPFixup(0x4E35D0, 0x419C30);
	CegHandler::AddFPFixup(0x581E50, 0x5D2E90);
	CegHandler::AddFPFixup(0x592AE0, 0x7CC060);
	CegHandler::AddFPFixup(0x5EAF70, 0x59DEC0);
	CegHandler::AddFPFixup(0x6348A0, 0x5EE560);
	CegHandler::AddFPFixup(0x680110, 0x97B2F0);
	CegHandler::AddFPFixup(0x4AB110, 0x7D0100);
	CegHandler::AddFPFixup(0x47D650, 0x1050D20);
	CegHandler::AddFPFixup(0x634B00, 0x25);
	CegHandler::AddFPFixup(0x6D77E0, 0x60);
	CegHandler::AddFPFixup(0x49D370, 0x11);
	CegHandler::AddFPFixup(0x4C0970, 0x3F);
	CegHandler::AddFPFixup(0x68DCE0, 5);
	CegHandler::AddFPFixup(0x69EC80, 0x7D);
	CegHandler::AddFPFixup(0x40A260, 0x11);
	CegHandler::AddFPFixup(0x6173E0, 0x1D);
	CegHandler::AddFPFixup(0x57C050, 0x22);
	CegHandler::AddFPFixup(0x4F2460, 0x74);
	CegHandler::AddFPFixup(0x690210, 0xEDB88320);
	CegHandler::AddFPFixup(0x4D32D0, 0xEDB88320);
	CegHandler::AddFPFixup(0x6AC3A0, 0xEDB88320);
	CegHandler::AddFPFixup(0x49C8B0, 0xEDB88320);
	CegHandler::AddFPFixup(0x589870, 0xEDB88320);
	CegHandler::AddFPFixup(0x573980, 0x340BAE8);
	CegHandler::AddFPFixup(0x59F560, 0x340BB08);
	CegHandler::AddFPFixup(0x4F2A90, 0x340B8A8);
	CegHandler::AddFPFixup(0x6AC750, 0x340B8B8);
	CegHandler::AddFPFixup(0x609690, 0x340BD90);
	CegHandler::AddFPFixup(0x616DD0, 0x340BDB0);
	CegHandler::AddFPFixup(0x628AF0, 0x340BB68);
	CegHandler::AddFPFixup(0x635170, 0x340BBA4);
	CegHandler::AddFPFixup(0x642C00, 0x340B938);
	CegHandler::AddFPFixup(0x59B590, 0x340B958);
	CegHandler::AddFPFixup(0x4B18F0, 0x340BE00);
	CegHandler::AddFPFixup(0x675E80, 0x340BDE0);
	CegHandler::AddFPFixup(0x47D650, 0x1050D20);
	CegHandler::AddFPFixup(0x4D88C0, 0x1050D20);
	CegHandler::AddFPFixup(0x666000, 0x1050D20);
	CegHandler::AddFPFixup(0x4138C0, 0x1050D20);
	CegHandler::AddFPFixup(0x50C2E0, 0x1050D1C);



	QCALL(0x415BF7, 0x4B53F0, QPATCH_CALL);
	QCALL(0x5D9BCA, 0x5F6300, QPATCH_JUMP);
	QCALL(0x66B2EF, 0x6B0360, QPATCH_CALL);
	QCALL(0x522610, 0x44B290, QPATCH_JUMP);
	QCALL(0x703247, 0x530E70, QPATCH_CALL);
	QCALL(0x703247, 0x530E70, QPATCH_CALL);
	QCALL(0x5FE5E0, 0, QPATCH_CALL);

	//its 4:36 and i want to sleep stild dint found the problem :=(
	//*(BYTE*)0x49324C = 0x71;
	//now its working was only some Decryption calls missing.
}

// Kinda not possible now :P
void CegHandler::Setup_V43_ZM_CEG()
{
	// Decryption calls.
	QCALL(0x437D1F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x44C716, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x46D45F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x4773F6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x487B61, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x51F2C6, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x533366, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5630B1, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5A9A5F, CEGEx1HookStub, QPATCH_CALL);
	QCALL(0x5C06E7, CEGEx1HookStub, QPATCH_CALL);

	// Destroyed functionpointers.
	//CegHandler::AddFPFixup(0x6E2D60, 0x69F345);
	//CegHandler::AddFPFixup(0x6698A0, 0x4B12B0);//  * /
	//CegHandler::AddFPFixup(0x4E0AF0, 0x97CD00);
	//CegHandler::AddFPFixup(0x5982D0, 0x7CDED0);
	//CegHandler::AddFPFixup(0x57A450, 0x63A680);
	//CegHandler::AddFPFixup(0x649750, 0x537260);
	//CegHandler::AddFPFixup(0x538100, 0x4DF510);
	//CegHandler::AddFPFixup(0x5297D0, 0x6AA530);
	//CegHandler::AddFPFixup(0x592AE0, 0x7CC060);


	////CegHandler::AddFPFixup(0x5EAF70, 0x59DEC0);//58A270
	////CegHandler::AddFPFixup(0x6348A0, 0x5EE560);
	//CegHandler::AddFPFixup(0x62A3D0, 0x977DC0);
	////CegHandler::AddFPFixup(0x4AB110, 0x7D0100);
	////CegHandler::AddFPFixup(0x47D650, 0x1050D20);
	////CegHandler::AddFPFixup(0x634B00, 0x25);
	////CegHandler::AddFPFixup(0x6D77E0, 0x60);
	////CegHandler::AddFPFixup(0x49D370, 0x11);
	////CegHandler::AddFPFixup(0x4C0970, 0x3F);
	////CegHandler::AddFPFixup(0x68DCE0, 5);
	////CegHandler::AddFPFixup(0x69EC80, 0x7D);
	////CegHandler::AddFPFixup(0x40A260, 0x11);
	////CegHandler::AddFPFixup(0x6173E0, 0x1D);
	////CegHandler::AddFPFixup(0x57C050, 0x22);
	////CegHandler::AddFPFixup(0x4F2460, 0x74);
	////CegHandler::AddFPFixup(0x690210, 0xEDB88320);
	////CegHandler::AddFPFixup(0x4D32D0, 0xEDB88320);
	////CegHandler::AddFPFixup(0x6AC3A0, 0xEDB88320);
	////CegHandler::AddFPFixup(0x49C8B0, 0xEDB88320);
	////CegHandler::AddFPFixup(0x589870, 0xEDB88320);
	////CegHandler::AddFPFixup(0x573980, 0x340BAE8);
	////CegHandler::AddFPFixup(0x59F560, 0x340BB08);
	////CegHandler::AddFPFixup(0x4F2A90, 0x340B8A8);
	////CegHandler::AddFPFixup(0x6AC750, 0x340B8B8);
	////CegHandler::AddFPFixup(0x609690, 0x340BD90);
	////CegHandler::AddFPFixup(0x616DD0, 0x340BDB0);
	////CegHandler::AddFPFixup(0x628AF0, 0x340BB68);
	////CegHandler::AddFPFixup(0x635170, 0x340BBA4);
	////CegHandler::AddFPFixup(0x642C00, 0x340B938);
	////CegHandler::AddFPFixup(0x59B590, 0x340B958);
	////CegHandler::AddFPFixup(0x4B18F0, 0x340BE00);
	////CegHandler::AddFPFixup(0x675E80, 0x340BDE0);
	////CegHandler::AddFPFixup(0x47D650, 0x1050D20);
	////CegHandler::AddFPFixup(0x4D88C0, 0x1050D20);
	////CegHandler::AddFPFixup(0x666000, 0x1050D20);
	////CegHandler::AddFPFixup(0x4138C0, 0x1050D20);
	////CegHandler::AddFPFixup(0x50C2E0, 0x1050D1C);



	uint32_t a1 = (uint32_t)Patterns::FindPattern((uint8_t*)"\x55\x8B\xEC\x83\xC4\x90\x89\x4D\xFC\x8D\x45\x90\x6A\x6C\x50\xE8\x00\x00\x00\x00\x83\xC4\x08\x33\xC0\x8B\x4D\xFC\x8B\xE5\x5D\xC2\x0C\x00", "xxxxxxxxxxxxxxxx????xxxxxxxxxxxxxx");
	uint32_t a2 = (uint32_t)Patterns::FindPattern((uint8_t*)"\x83\xEC\x10\x56\x8D\x44\x24\x04\x57", "xxxxxxxxx");
	QCALL(a1, a2, QPATCH_CALL);

	QCALL(0x67392A, 0x6F7B70, QPATCH_JUMP);
	//QCALL(0x66B2EF, 0x6B0360, QPATCH_CALL);
	//QCALL(0x522610, 0x44B290, QPATCH_JUMP);
	//QCALL(0x703247, 0x530E70, QPATCH_CALL);
	//QCALL(0x703247, 0x530E70, QPATCH_CALL);
	//QCALL(0x5FE5E0, 0, QPATCH_CALL);
}
void CegHandler::Signatures()
{
	static signature_t signatures[26];
	memset(signatures, 0, sizeof(signatures));

	//ID : 0
	signatures[0].signature = (unsigned char*)"\x3F\x3F\xE8\x3F\x3F\x3F\x3F\x8A\x44\x24\x23";
	signatures[0].mask = "??x????xxxx";
	signatures[0].size = 11;
	signatures[0].logOffset = 0;
	signatures[0].replace = (unsigned char*)"\xB0\x01\x90\x90";
	signatures[0].replaceOffset = 7;
	signatures[0].replaceSize = 4;

	//ID : 1
	signatures[1].signature = (unsigned char*)"\x50\xC6\x3F\x3F\x3F\x3F\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\xC3";
	signatures[1].mask = "xx????x????xx?x";
	signatures[1].size = 15;
	signatures[1].logOffset = 0;
	signatures[1].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[1].replaceOffset = 6;
	signatures[1].replaceSize = 5;

	//ID : 2
	signatures[2].signature = (unsigned char*)"\x50\xC7\x44\x24\x3F\x3F\x00\x00\x00\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\xC3";
	signatures[2].mask = "xxxx??xxxx????xx?x";
	signatures[2].size = 18;
	signatures[2].logOffset = 0;
	signatures[2].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[2].replaceOffset = 10;
	signatures[2].replaceSize = 5;

	//ID : 3
	signatures[3].signature = (unsigned char*)"\x50\xC7\x44\x24\x3F\x3F\x00\x00\x00\xC7\x3F\x3F\x3F\x3F\x3F\x3F\x3F\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\xC3";
	signatures[3].mask = "xxxx??xxxx???????x????xx?x";
	signatures[3].size = 26;
	signatures[3].logOffset = 0;
	signatures[3].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[3].replaceOffset = 17;
	signatures[3].replaceSize = 5;

	//ID : 4
	signatures[4].signature = (unsigned char*)"\x50\xC6\x3F\x3F\x3F\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\x64";
	signatures[4].mask = "xx???x????xx?x";
	signatures[4].size = 14;
	signatures[4].logOffset = 0;
	signatures[4].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[4].replaceOffset = 5;
	signatures[4].replaceSize = 5;

	//ID : 5
	signatures[5].signature = (unsigned char*)"\x50\xC7\x45\x3F\x3F\x00\x00\x00\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\x64";
	signatures[5].mask = "xxx??xxxx????xx?x";
	signatures[5].size = 17;
	signatures[5].logOffset = 0;
	signatures[5].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[5].replaceOffset = 9;
	signatures[5].replaceSize = 5;

	//ID : 6
	signatures[6].signature = (unsigned char*)"\x50\xC7\x45\x3F\x3F\x00\x00\x00\xC7\x3F\x3F\x3F\x3F\x3F\x3F\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\xC3";
	signatures[6].mask = "xxx??xxxx??????x????xx?x";
	signatures[6].size = 24;
	signatures[6].logOffset = 0;
	signatures[6].replace = (unsigned char*)"\xB0\x01\x90\x90\x90";
	signatures[6].replaceOffset = 15;
	signatures[6].replaceSize = 5;

	//ID : 7
	signatures[7].signature = (unsigned char*)"\x56\xE8\x3F\x3F\x3F\x3F\x8B\xF0\xE8\x3F\x3F\x3F\x3F\x50\x56\xE8";
	signatures[7].mask = "xx????xxx????xxx";
	signatures[7].size = 16;
	signatures[7].logOffset = 0;
	signatures[7].replace = (unsigned char*)"\xB0\x01\xC3";
	signatures[7].replaceOffset = 0;
	signatures[7].replaceSize = 3;

	//ID : 8
	signatures[8].signature = (unsigned char*)"\xE8\x3F\x3F\x3F\x3F\x84\xC0\x5E\x68\x3F\x3F\x00\x00\x6A\x03";
	signatures[8].mask = "x????xxxx??xxxx";
	signatures[8].size = 15;
	signatures[8].logOffset = 0;
	signatures[8].replace = (unsigned char*)"\x33\xC0\x90\x90\x90";
	signatures[8].replaceOffset = 0;
	signatures[8].replaceSize = 5;

	//ID : 9
	signatures[9].signature = (unsigned char*)"\xE8\x3F\x3F\x3F\x3F\x84\xC0\x5E\x6A\x3F\x6A\x03";
	signatures[9].mask = "x????xxxx?xx";
	signatures[9].size = 12;
	signatures[9].logOffset = 0;
	signatures[9].replace = (unsigned char*)"\x33\xC0\x90\x90\x90";
	signatures[9].replaceOffset = 0;
	signatures[9].replaceSize = 5;

	//ID : 10
	signatures[10].signature = (unsigned char*)"\x80\x7C\x24\x04\x00\x75\x3F\x56\x8B";
	signatures[10].mask = "xxxxxx?xx";
	signatures[10].size = 9;
	signatures[10].logOffset = 0;
	signatures[10].replace = (unsigned char*)"\xB0\x01\xC3";
	signatures[10].replaceOffset = 0;
	signatures[10].replaceSize = 3;

	//ID : 11
	signatures[11].signature = (unsigned char*)"\x8D\x45\x08\x83\xE8\x04\x89\x45\xF8\x8B";
	signatures[11].mask = "xxxxxxxxxx";
	signatures[11].size = 10;
	signatures[11].logOffset = 0;
	signatures[11].replace = (unsigned char*)"\xE6";
	signatures[11].replaceOffset = -9;
	signatures[11].replaceSize = 1;

	//ID : 12
	signatures[12].signature = (unsigned char*)"\x81\xEC\x00\x08\x00\x00\x68\x3F\x3F\x3F\x00\xE8\x3F\x3F\x3F\x3F";
	signatures[12].mask = "xxxxxxx???xx????";
	signatures[12].size = 16;
	signatures[12].logOffset = 0;
	signatures[12].replace = (unsigned char*)"\xE6";
	signatures[12].replaceOffset = 0;
	signatures[12].replaceSize = 1;

	//ID : 13
	signatures[13].signature = (unsigned char*)"\x0B\xC1\x74\x0B\x84\xDB\x74\x07\xB8\x01\x00\x00\x00\x5B\xC3\x33";
	signatures[13].mask = "xxxxxxxxxxxxxxxx";
	signatures[13].size = 16;
	signatures[13].logOffset = 0;
	signatures[13].replace = (unsigned char*)"\xB0\x01";
	signatures[13].replaceOffset = 15;
	signatures[13].replaceSize = 2;

	//ID : 14
	signatures[14].signature = (unsigned char*)"\x83\xEC\x14\x53\x55\x56\x57\xE8\x3F\x3F\x3F\x3F\xE8\x3F\x3F\x3F\x3F";
	signatures[14].mask = "xxxxxxxx????x????";
	signatures[14].size = 17;
	signatures[14].logOffset = 0;
	signatures[14].replace = (unsigned char*)"\xC3";
	signatures[14].replaceOffset = 0;
	signatures[14].replaceSize = 1;

	//ID : 15
	signatures[15].signature = (unsigned char*)"\x81\xEC\x24\x04\x00\x00\x8B\x84\x24\x2C\x04\x00\x00\x8B\xC8\x2B";
	signatures[15].mask = "xxxxxxxxxxxxxxxx";
	signatures[15].size = 16;
	signatures[15].logOffset = 0;
	signatures[15].replace = (unsigned char*)"\xC3";
	signatures[15].replaceOffset = 0;
	signatures[15].replaceSize = 1;

	//ID : 16
	signatures[16].signature = (unsigned char*)"\x55\x8B\xEC\x51\x68\x3F\x3F\x3F\x00\x68\x3F\x3F\x3F\x00\x64\xFF\x35\x00\x00\x00\x00\x64";
	signatures[16].mask = "xxxxx???xx???xxxxxxxxx";
	signatures[16].size = 22;
	signatures[16].logOffset = 0;
	signatures[16].replace = (unsigned char*)"\xC3";
	signatures[16].replaceOffset = 0;
	signatures[16].replaceSize = 1;

	//ID : 17
	signatures[17].signature = (unsigned char*)"\x55\x8B\xEC\x83\xEC\x3F\x68\x3F\x3F\x3F\x00\x68\x3F\x3F\x3F\x00\x64\xFF";
	signatures[17].mask = "xxxxx?x???xx???xxx";
	signatures[17].size = 18;
	signatures[17].logOffset = 0;
	signatures[17].replace = (unsigned char*)"\xC3";
	signatures[17].replaceOffset = 0;
	signatures[17].replaceSize = 1;

	//ID : 18
	signatures[18].signature = (unsigned char*)"\x5F\x5E\x5D\xB0\x01\x5B\x81\xC4\x74\x02\x00\x00\xC3";
	signatures[18].mask = "xxxxxxxxxxxxx";
	signatures[18].size = 13;
	signatures[18].logOffset = 0;
	signatures[18].replace = (unsigned char*)"\x78";
	signatures[18].replaceOffset = 8;
	signatures[18].replaceSize = 1;

	//ID : 19
	signatures[19].signature = (unsigned char*)"\x57\x8B\x4C\x24\x08\x8B\x7C\x24\x0C\x33\xC0\x89\x08\x5F\xC3";
	signatures[19].mask = "xxxxxxxxxxxxxxx";
	signatures[19].size = 15;
	signatures[19].logOffset = 0;
	signatures[19].replace = (unsigned char*)"\xC3";
	signatures[19].replaceOffset = 0;
	signatures[19].replaceSize = 1;

	//ID : 20
	signatures[20].signature = (unsigned char*)"\x81\xEC\x74\x02\x00\x00\x8B\x8C\x24\x80\x02\x00\x00\x53\x55\x56";
	signatures[20].mask = "xxxxxxxxxxxxxxxx";
	signatures[20].size = 16;
	signatures[20].logOffset = 0;
	signatures[20].replace = (unsigned char*)"\xB0\x01\xC3";
	signatures[20].replaceOffset = 0;
	signatures[20].replaceSize = 3;

	//ID : 21
	signatures[21].signature = (unsigned char*)"\x51\x8D\x04\x24\x6A\x3F\x50\xC7\x44\x24\x08\x3F";
	signatures[21].mask = "xxxxx?xxxxx?";
	signatures[21].size = 12;
	signatures[21].logOffset = 0;
	signatures[21].replace = (unsigned char*)"\xB0\x01\xC3";
	signatures[21].replaceOffset = 0;
	signatures[21].replaceSize = 3;

	//could not found
	//NEW
	signatures[22].signature = (unsigned char*)"\x55\x8B\xEC\x81\xEC????\x00\x00\x53\x56\x57\x8B\x3D";
	signatures[22].mask = "xxxxx??xxxxxxx";
	signatures[22].size = 14;
	signatures[22].logOffset = 0;
	signatures[22].replace = (unsigned char*)"xC3";
	signatures[22].replaceOffset = 0;
	signatures[22].replaceSize = 1;

	//NEW2
	signatures[23].signature = (unsigned char*)"\x51\x8D\x04\x24\x6A\x3F\x50\xC7\x44\x24\x08\x3F";
	signatures[23].mask = "xxxxxxxxxxxxx";
	signatures[23].size = 13;
	signatures[23].logOffset = 0;
	signatures[23].replace = (unsigned char*)"\xC3";
	signatures[23].replaceOffset = 0;
	signatures[23].replaceSize = 1;

	//NEW3
	signatures[24].signature = (unsigned char*)"\x75\x44\x56\x8B\x74\x24\x0C";
	signatures[24].mask = "xxxxxxx";
	signatures[24].size = 7;
	signatures[24].logOffset = 0;
	signatures[24].replace = (unsigned char*)"\x71";
	signatures[24].replaceOffset = 0;
	signatures[24].replaceSize = 1;

	//NEW4
	signatures[25].signature = (unsigned char*)"\x51\x8D\x44\x24\x3F\x50\xE8\x3F\x3F\x3F\x3F\x83\xC4\x3F\xC3";
	signatures[25].mask = "xxxx?xx????xx?x";
	signatures[25].size = 15;
	signatures[25].logOffset = 0;
	signatures[25].replace = (unsigned char*)"\xC3";
	signatures[25].replaceOffset = 0;
	signatures[25].replaceSize = 1;

	//NEW5
	signatures[26].signature = (unsigned char*)"\x83\xEC\x48\x53\x55\x56\x57\x6A\x01\x8D\x44\x24\x34";
	signatures[26].mask = "xxxxxxxxxxxxx";
	signatures[26].size = 13;
	signatures[26].logOffset = 0;
	signatures[26].replace = (unsigned char*)"\xC3";
	signatures[26].replaceOffset = 0;
	signatures[26].replaceSize = 1;



	for (int i = 0; i < 22; i++)
	{
		signature_t* signature = &signatures[i];
		if (signature->signature)
		{
			ProcessSignature2(i, signature);
		}
	}
}