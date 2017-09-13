#pragma once
class CegHandler
{
private:
	static int unkHandlerShit;
	static char zone_file_mem2[16];
	static void* zone_file_mem;
	static void sub_1002F5A0(PCONTEXT a1);
	static int sub_1002F5E0(DWORD* a1, char a2, char a3, int a4);
	static void sub_1002F620(PCONTEXT ContextRecord, DWORD OldContextRecord);
	static void __stdcall cegRaiseException(ULONG_PTR Arguments);
	static void CEGEx1HookStub();

	static CRITICAL_SECTION SomewhatCritical;
	static Hook::Call cegMemcpyHook;
	static void MemcpyHook(LPVOID lpAddress, const void *Src, SIZE_T dwSize);
	static DWORD cegMemcpyHookLoc;
	static void Signatures();
	static LONG WINAPI CEG_CompleteTrap(LPEXCEPTION_POINTERS ExceptionInfo);
	static DWORD OldContextRecord;
	static void __stdcall cegZoneLoc(int ZoneMemLoc);

	static void AddFPFixup(DWORD Address, DWORD Address2);
	static void Setup_V39CEG();
	static void Setup_V40CEG();
	static void Setup_V41CEG();
	static void Setup_V43CEG();
	static void Setup_V43_ZM_CEG();



	static char ZONE_004B5927[];
	static char ZONE_005B0C54[];
	static char ZONE_006BA817[];
	static char ZONE_006C1C82[];
	static char ZONE_0058E533[];
	static char ZONE_0058F0C3[];
	static char ZONE_00524397[];

	static char ZONE_00513714[];
	static char ZONE_004AEBD0[];
	static char ZONE_006CF8C1[];
	static char ZONE_00558924[];
	static char ZONE_0042E4E1[];
	static char ZONE_004F537E[];
	static char ZONE_00702B81[];
	static char ZONE_005459E0[];
	static char ZONE_00580E84[];
	static char ZONE_005F6DD4[];
	static char ZONE_006DD704[];


	static char ZONE_0060B3F4[];
	static char ZONE_0064CA64[];
	static char ZONE_00573DA4[];
	static char ZONE_00493C30[];
	static char ZONE_004D5BF4[];
	static char ZONE_005BB001[];
	static char ZONE_00495361[];
	static char ZONE_005206CE[];
	static char ZONE_00685784[];
	static char ZONE_006F11A4[];
	static char ZONE_00667250[];

	//mp43
	static char ZONE_0052F177[];
	static char ZONE_0057FEEE[];
	static char ZONE_00519424[];
	static char ZONE_0067F2C0[];
	static char ZONE_004167F4[];
	static char ZONE_00673501[];
	static char ZONE_00607E01[];
	static char ZONE_005FA6C1[];
	static char ZONE_004AAF71[];
	static char ZONE_0065CE31[];
	static char ZONE_004FA9B4[];
	static char ZONE_00896E34[];
	static char ZONE_005D2694[];
	static char ZONE_00695FA0[];
public:
	static void Initialize();
};