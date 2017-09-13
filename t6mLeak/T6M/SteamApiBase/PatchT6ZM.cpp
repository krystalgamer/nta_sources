#include "STDInc.h"
void spawnTestElemZombie(int client)
{
	// Text
	HudElem* elem = HudElements::HudElem_Allocate();
	HudElements::HudElem_Init(elem, client);
	HudElements::HudElem_SetText(elem, "Jürgen Trovato & JD owns now zombies!");
	HudElements::HudElem_SetAlign(elem, TOP_LEFT);
	HudElements::HudElem_SetColor(elem, 0, 255, 255, 255);
	HudElements::HudElem_SetGlow(elem, 0, 255, 255, 40);
	elem->fontScale = 2.0f;
}
void testHudElems_f()
{
	int count = (Command::Cmd_ArgC() > 1 ? atoi(Command::Cmd_ArgV(1)) : 1);
	if (Addresses::SV_Loaded())
	{
		for (int i = 0; i < 4; i++)
		{
			spawnTestElemZombie(i);
		}
	}
}



void T6ZM::PatchT6ZM_V39()
{
	//fix jmp -> free does ...
	*(BYTE*)0x5F6AFB = 0xEB;

	//return shield
	*(BYTE*)0x46DF20 = 0xC3;

	//developer_script
	*(BYTE*)0x87E29F = 0x01;

	//lui_checksum_enabled
	*(BYTE*)0x87E03F = 0x00;

	//xblive_rankedmatch
	*(BYTE*)0x87E1F7 = 0x01;

	//silentfail
	*(BYTE*)0x552841 = 0x2F;

	//shield
	*(BYTE*)0x5D2E20 = 0xC3;

	//gpad_enabled
	*(BYTE*)0x4187A7 = 0x01;

	//Don't start Steam if Game change in menu
	*(BYTE*)0x676330 = 0xC3;

	//Make Systemlink Visible to Play Offline
	*(BYTE*)0x87E287 = 0x01;

	//Create a Thread for the Console
	CreateThread(0, 0, ConsoleWindow, (LPVOID)0x5CBFB0, 0, 0);


	//Load Custom Strings
	//MainPatchFunctions::HKS_StringHook.Initialize(0x889710, MainPatchFunctions::HKS_ReturnString);
	//MainPatchFunctions::HKS_StringHook.InstallHook();
}
void T6ZM::PatchT6ZM_V41()
{
	static cmd_function_s autoChangeClass_cmd;
	static cmd_function_s testHudElems_cmd;
	static cmd_function_s Notify_cmd;
	static cmd_function_s spawnBot_cmd;
	Addresses::Cmd_AddCommandInternal("autoChangeClass", Bots::autoChangeClass_f, &autoChangeClass_cmd);
	Addresses::Cmd_AddCommandInternal("testHudElems", testHudElems_f, &testHudElems_cmd);
	Addresses::Cmd_AddCommandInternal("Notify", PopupNotify::Notify_f, &Notify_cmd);
	Addresses::Cmd_AddCommandInternal("spawnBot", Bots::spawnBot_f, &spawnBot_cmd);



	// Set party_maxplayers to 8.
	//if (*(DWORD*)0x1239478)//127B874 dvar_t
	//	*(DWORD*)(*(DWORD*)0x1239478 + 24) = 8;
	// Set party_minplayers to 8.
	//if (*(DWORD*)0x1239988)
	//	*(DWORD*)(*(DWORD*)0x1239988 + 24) = 8;	
	//Addresses::Dvar_RegisterBool("tu9_rerunPlaylistRulesOnHost", false, DVAR_ARCHIVE, "");
	//Addresses::Dvar_RegisterInt("party_maxplayers", 18, 0x1300000001i64, 0, "");
	//Addresses::Dvar_RegisterInt("party_minplayers", 2, 77309411329i64, 0, (int)&szProxyBypass);




	//a_tu15          db '_tu15',0 
	*(BYTE*)0xC0BF44 = 0x33;

	//aOnline_tu15_zm db 'online_tu15_zm_',0
	*(BYTE*)0xC27F96 = 0x33;


	//fix jmp -> free does ...
	*(BYTE*)0x46049B = 0xEB;

	//return shield
	*(BYTE*)0x477830 = 0xC3;

	//developer_script
	*(BYTE*)0x88B16F = 0x01;

	//lui_checksum_enabled
	*(BYTE*)0x88AF0F = 0x00;

	//xblive_rankedmatch
	*(BYTE*)0x88B0C7 = 0x01;

	//silentfail
	*(BYTE*)0x6B75F1 = 0x2F;

	//shield
	*(BYTE*)0x665410 = 0xC3;

	//gpad_enabled
	*(BYTE*)0x668887 = 0x01;

	//Don't start Steam if Game change in menu
	*(BYTE*)0x52E240 = 0xC3;
	
	//Make Systemlink Visible to Play Offline
	*(BYTE*)0x88B157 = 0x01;


	//Create a Thread for the Console
	//Call console Function for some Reasons redacted do Same :P
	CreateThread(0, 0, ConsoleWindow, (LPVOID)0x4A67F0, 0, 0);

	////Load Custom Materials
	//MainPatchFunctions::HKS_MaterialHook.Initialize(0x6D0080, MainPatchFunctions::HKS_RegisterMaterial);
	//MainPatchFunctions::HKS_MaterialHook.InstallHook();

	////Load Custom Strings
	//MainPatchFunctions::HKS_StringHook.Initialize(0x8964F0, MainPatchFunctions::HKS_ReturnString);
	//MainPatchFunctions::HKS_StringHook.InstallHook();

	////Load RawFiles From FS
	//MainPatchFunctions::HKS_RawfileHook.Initialize(0x4A7550, MainPatchFunctions::HKS_LoadRawfile);
	//MainPatchFunctions::HKS_RawfileHook.InstallHook();

	////Load Scripts
	//MainPatchFunctions::ScriptParseHook.Initialize(0x4F8E50, MainPatchFunctions::Load_ScriptParseTreeAsset);
	//MainPatchFunctions::ScriptParseHook.InstallHook();
}