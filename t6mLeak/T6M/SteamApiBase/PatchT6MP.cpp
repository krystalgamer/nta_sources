#include "STDInc.h"
void spawnTestElem(int client)
{
	// Text
	HudElem* elem = HudElements::HudElem_Allocate();
	HudElements::HudElem_Init(elem, client);
	HudElements::HudElem_SetText(elem, "Sonsored!");
	HudElements::HudElem_SetAlign(elem, TOP_CENTER);
	HudElements::HudElem_SetColor(elem, 0, 0, 0, 255);
	HudElements::HudElem_SetGlow(elem, 255, 0, 0, 80);

	elem->fontScale = 2.0f;

	// Icon
	HudElem* material = HudElements::HudElem_Allocate();
	HudElements::HudElem_Init(material, client);
	HudElements::HudElem_SetIcon(material, "hud_medals_nuclear");
	HudElements::HudElem_SetAlign(material, TOP_CENTER);

	material->width = 60;
	material->height = 60;
	material->y = 30;
}
void testHudElems_f2()
{
	int count = (Command::Cmd_ArgC() > 1 ? atoi(Command::Cmd_ArgV(1)) : 1);
	if (Addresses::SV_Loaded())
	{
		for (int i = 0; i < 4; i++)
		{
			spawnTestElem(i);
		}
	}
}



void T6MP::PatchT6MP_V40()
{
	static cmd_function_s testHudElems_cmd;
	static cmd_function_s autoChangeClass_cmd;
	static cmd_function_s Notify_cmd;
	static cmd_function_s spawnBot_cmd;
	Addresses::Cmd_AddCommandInternal("testHudElems", testHudElems_f2, &testHudElems_cmd);
	Addresses::Cmd_AddCommandInternal("autoChangeClass", Bots::autoChangeClass_f, &autoChangeClass_cmd);
	Addresses::Cmd_AddCommandInternal("Notify", PopupNotify::Notify_f, &Notify_cmd);
	Addresses::Cmd_AddCommandInternal("spawnBot", Bots::spawnBot_f, &spawnBot_cmd);

	

	//fix jmp -> free does ...
	*(BYTE*)0x5BFA6B = 0xEB;

	//
	*(BYTE*)0x5DDC20 = 0xC3;

	//developer_script 1
	*(BYTE*)0x88A657 = 0x01;

	//lui_checksum_enabled
	*(BYTE*)0x88A3F7 = 0x00;

	//xblive_rankedmatch
	*(BYTE*)0x88A5AF = 0x01;

	//silentfail
	*(BYTE*)0x5080D1 = 0x2F;

	//tu11_partymigrate_allowPrivatePartyClientsToHost
	*(BYTE*)0x5664CA = 0x00;

	//WinMain remove something idk :D
	*(BYTE*)0x544240 = 0xC3;

	//gpad_enabled
	*(BYTE*)0x6B6607 = 0x01;








	// a_tu14          db '_tu14',0      
	*(BYTE*)0xC1D910 = 0x33;

	//aOnline_tu14_mp db 'online_tu14_mp_',0 
	*(BYTE*)0xBE0F26 = 0x33;





	//Don't start Steam if Game change in menu
	*(BYTE*)0x4BE550 = 0xC3;

	//Make Systemlink Visible to Play Offline   developer 1
	*(BYTE*)0x88A63F = 0x01;

	//Create a Thread for the Console
	CreateThread(0, 0, ConsoleWindow, (LPVOID)0x54D4F0, 0, 0);

	//Load Custom Materials
	MainPatchFunctions::HKS_MaterialHook.Initialize(0x4863E0, MainPatchFunctions::HKS_RegisterMaterial);
	MainPatchFunctions::HKS_MaterialHook.InstallHook();

	//Load Custom Strings
	MainPatchFunctions::HKS_StringHook.Initialize(0x895DB0, MainPatchFunctions::HKS_ReturnString);
	MainPatchFunctions::HKS_StringHook.InstallHook();

	//Load RawFiles From FS
	MainPatchFunctions::HKS_RawfileHook.Initialize(0x494BA0, MainPatchFunctions::HKS_LoadRawfile);
	MainPatchFunctions::HKS_RawfileHook.InstallHook();

	//Load Scripts
	MainPatchFunctions::ScriptParseHook.Initialize(0x5E7060, MainPatchFunctions::Load_ScriptParseTreeAsset);
	MainPatchFunctions::ScriptParseHook.InstallHook();

	//Load Custom Weapons
	MainPatchFunctions::LoadCustomWeaponAsset.Initialize(0x94E354, MainPatchFunctions::Load_WeaponAsset);
	MainPatchFunctions::LoadCustomWeaponAsset.InstallHook();
}
void T6MP::PatchT6MP_V43()
{

	static cmd_function_s testHudElems_cmd;
	static cmd_function_s autoChangeClass_cmd;
	static cmd_function_s Notify_cmd;
	Addresses::Cmd_AddCommandInternal("testHudElems", testHudElems_f2, &testHudElems_cmd);
	Addresses::Cmd_AddCommandInternal("autoChangeClass", Bots::autoChangeClass_f, &autoChangeClass_cmd);
	Addresses::Cmd_AddCommandInternal("Notify", PopupNotify::Notify_f, &Notify_cmd);



	//fix jmp -> free does ...
	*(BYTE*)0x517AFB = 0xEB;

	//
	*(BYTE*)0x5DDC20 = 0xC3;

	//lui_checksum_enabled
	*(BYTE*)0x88BEA7 = 0x00;

	//xblive_rankedmatch
	*(BYTE*)0x88C05F = 0x01;

	//silentfail
	*(BYTE*)0x62FA61 = 0x2F;

	//tu11_partymigrate_allowPrivatePartyClientsToHost
	*(BYTE*)0x4F0C0A = 0x00;

	//WinMain remove something idk :D
	*(BYTE*)0x6BAB80 = 0xC3;

	//gpad_enabled
	*(BYTE*)0x4E4DF7 = 0x01;

	//Don't start Steam if Game change in menu
	*(BYTE*)0x5E0660 = 0xC3;

	//developer_script 1
	*(BYTE*)0x88C107 = 0x01;

	//developer 1
	*(BYTE*)0x88C0EF = 0x01;
	




	//a_tu17          db '_tu17',0 
	*(BYTE*)0xBFF698 = 0x33;

	//aOnline_tu17_mp db 'online_tu17_mp_',0
	*(BYTE*)0xBF04AE = 0x33;







	//Create a Thread for the Console
	CreateThread(0, 0, ConsoleWindow, (LPVOID)0x473AD0, 0, 0);

	//Load Custom Materials
	MainPatchFunctions::HKS_MaterialHook.Initialize(0x5152D0, MainPatchFunctions::HKS_RegisterMaterial);
	MainPatchFunctions::HKS_MaterialHook.InstallHook();

	//Load Custom Strings
	MainPatchFunctions::HKS_StringHook.Initialize(0x897970, MainPatchFunctions::HKS_ReturnString);
	MainPatchFunctions::HKS_StringHook.InstallHook();

	//Load RawFiles From FS
	MainPatchFunctions::HKS_RawfileHook.Initialize(0x69D680, MainPatchFunctions::HKS_LoadRawfile);
	MainPatchFunctions::HKS_RawfileHook.InstallHook();

	//Load Scripts
	MainPatchFunctions::ScriptParseHook.Initialize(0x539630, MainPatchFunctions::Load_ScriptParseTreeAsset);
	MainPatchFunctions::ScriptParseHook.InstallHook();

	//Load Custom Weapons
	MainPatchFunctions::LoadCustomWeaponAsset.Initialize(0x950294, MainPatchFunctions::Load_WeaponAsset);
	MainPatchFunctions::LoadCustomWeaponAsset.InstallHook();
}