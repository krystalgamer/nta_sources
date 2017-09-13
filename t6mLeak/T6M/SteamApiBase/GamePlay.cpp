#include "STDInc.h"
dvar_t* GamePlay::r_fog;
Hook::Stomp GamePlay::r_fog_Hook;




typedef void(__cdecl * sub_76D270_t)(DWORD a1, DWORD a2);
sub_76D270_t sub_76D270 = (sub_76D270_t)0x76D270;

void GamePlay::r_fog_Hook_Function(DWORD a1, DWORD a2)
{
	//InGameConsole::Log(hString::va("*(DWORD*)a1 %lx", *(DWORD*)(a1 + 1)));
	//InGameConsole::Log(hString::va("*(DWORD*)a2 %lx", *(DWORD*)a2));
	//InGameConsole::Log(hString::va("a1 %lx", a1));
	//InGameConsole::Log(hString::va("a2 %lx", a2));

	sub_76D270(*(DWORD*)(a1 + 1), a2);//fix

	//if (r_fog->current.enabled)
	//{
	//	//do nothing for no fog lol so easy why should we do it hard way?
	//}
	//else
	//{
	//	peterpenis(a1, a2);
	//}
	return;
}






const char* G_Say_SetTextFunction(const char* stdIn)
{
	//if first char == '/' we want a command
	if (stdIn[0] == '/')
	{
		//How the hack why -1 don't work?
		Addresses::Cbuf_AddText(0, (const char*)stdIn + 1);
	}
	return stdIn;
}
void GamePlay::Initialize()
{
	//GamePlay::r_fog = Addresses::Dvar_RegisterBool("r_fog", true, DVAR_ARCHIVE, "");
	//QCALL(0x72D767, r_fog_Hook_f, QPATCH_JUMP);
	//QCALL(0x72D766, r_fog_Hook_f, QPATCH_JUMP);
	//GamePlay::r_fog_Hook.Initialize(Addresses::R_GenerateFog, r_fog_Hook_f, 5, true);
	//GamePlay::r_fog_Hook.InstallHook();


	//G_Say_SetTextFunction Hook
//	QCALL(Addresses::G_Say_SetTextFunction, G_Say_SetTextFunction, QPATCH_CALL);

	//Remove FOG if we dont like it/Dvar
	//QCALL(0x72D5F7, r_fog_Hook_Function, QPATCH_CALL);
	//QCALL(0x76D270, r_fog_Hook_Function, QPATCH_CALL);
}