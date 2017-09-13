#include "STDInc.h"

Com_Error_t Addresses::Com_Error;
Com_Printf_t Addresses::Com_Printf;
Cbuf_AddText_t Addresses::Cbuf_AddText;
DB_FindXAssetHeader_t Addresses::DB_FindXAssetHeader;
DB_AddXAssetLoc_t Addresses::DB_AddXAssetLoc;
Cmd_AddCommandInternal_t Addresses::Cmd_AddCommandInternal;
FS_FreeFile_t Addresses::FS_FreeFile;
FS_ReadFile_t Addresses::FS_ReadFile;
FS_FCloseFile_t Addresses::FS_FCloseFile;
FS_FOpenFileByMode_t Addresses::FS_FOpenFileByMode;
FS_ListFiles_t Addresses::FS_ListFiles;
FS_FreeFileList_t Addresses::FS_FreeFileList;
FS_FileForHandle_t Addresses::FS_FileForHandle;
FS_GetFileOsPath_t Addresses::FS_GetFileOsPath;
Scr_ExecThread_t Addresses::Scr_ExecThread;
Scr_FreeThread_t Addresses::Scr_FreeThread;
Scr_LoadScriptInternal_t Addresses::Scr_LoadScriptInternal;
GScr_LoadScriptAndLabel_t Addresses::GScr_LoadScriptAndLabel;
G_ShutdownGame_t Addresses::G_ShutdownGame;
SL_GetString_t Addresses::SL_GetString;
SL_ConvertToString_t Addresses::SL_ConvertToString;
Scr_NotifyNum_t Addresses::Scr_NotifyNum;
Scr_AddString_t Addresses::Scr_AddString;
Scr_AddEntity_t Addresses::Scr_AddEntity;
Scr_AddInt_t Addresses::Scr_AddInt;
Scr_GetString_t Addresses::Scr_GetString;
NotifyClient_t Addresses::NotifyClient;
Dvar_RegisterBool_t Addresses::Dvar_RegisterBool;
Dvar_RegisterFloat_t Addresses::Dvar_RegisterFloat;
Dvar_RegisterInt_t Addresses::Dvar_RegisterInt;



// Custom GSC & CSC Loading
DWORD Addresses::scriptParseTreeLoad1_loc;
DWORD Addresses::scriptParseTreeLoad2_loc;
DWORD Addresses::scriptParseTreeLoad3_loc;
DWORD Addresses::scriptParseTreeLoad4_loc;
DWORD Addresses::loadGameTypeScript_loc;
DWORD Addresses::loadGameType_loc;
DWORD Addresses::scriptErrorParam_loc;
DWORD Addresses::precacheInitCheck1_loc;
DWORD Addresses::precacheInitCheck2_loc;
DWORD Addresses::precacheInitCheck3_loc;

// Commands
DWORD Addresses::cmd_argc;
DWORD Addresses::cmd_argv;

// Bots
SV_AddTestClient_t Addresses::SV_AddTestClient;
SV_Loaded_t Addresses::SV_Loaded;
g_entity_s* Addresses::g_entities;
DWORD Addresses::BotArray1;
DWORD Addresses::BotArray2;
DWORD Addresses::BotArray3;
DWORD Addresses::BotArraySize1;
DWORD Addresses::BotArraySize2;
DWORD Addresses::BotArraySize3;
DWORD Addresses::BotArraySize4;
DWORD Addresses::BotTag1;
DWORD Addresses::BotTag2;

// Hudelems
HudElem_Alloc_t Addresses::HudElem_Alloc;
G_LocalizedStringIndex_t Addresses::G_LocalizedStringIndex;
G_MaterialIndex_t Addresses::G_MaterialIndex;
DWORD Addresses::ShaderPrecacheLimitation;

// Colored Name
DWORD Addresses::ColoredName;
DWORD Addresses::ClientUserinfoChanged;
DWORD Addresses::GetClientName;
DWORD Addresses::GetClientName1;
DWORD Addresses::GetClientName2;
DWORD Addresses::GetClientName3;
DWORD Addresses::ICleanStrHook;
DWORD Addresses::ICleanStr;
DWORD Addresses::NameLength1;
DWORD Addresses::NameLength2;
DWORD Addresses::ColorTableFloat;
DWORD Addresses::ColorTableByte;

// Ingame Console
R_AddCmdDrawText_t Addresses::R_AddCmdDrawText;
DrawRotatedPic_t Addresses::DrawRotatedPic;
GetTextLengthSize_t Addresses::GetTextLengthSize;
DWORD Addresses::ConsoleCatcher;
DWORD Addresses::ConsoleCatcher2;
DWORD Addresses::RendererFrame;
DWORD Addresses::RendererFrameO;
DWORD Addresses::RendererStart;
DWORD Addresses::RendererStartO;
DWORD Addresses::RendererWidth;
DWORD Addresses::RendererHeight;
DWORD Addresses::InputUIToCL;
DWORD Addresses::InputExecBinding;
DWORD Addresses::InputExecBindingO;
DWORD Addresses::InputCharEvent;
DWORD Addresses::InputCharEventO;
DWORD Addresses::InputKeyEvent;
DWORD Addresses::InputKeyEventO;
DWORD Addresses::InputMouseX;
DWORD Addresses::InputMouseY;
DWORD Addresses::InputHWND;

// Custom Asset
DWORD Addresses::FS_BaseGameFolderName;

// SystemLink SererList
DWORD Addresses::GetServerNameFromList;
DWORD Addresses::GetServerCount;
DWORD Addresses::ServerBaseAddress;

// DW Server
DWORD Addresses::custom_gethostbyname;
DWORD Addresses::dw_recvfrom;
DWORD Addresses::dw_sendto;
DWORD Addresses::dw_recv;
DWORD Addresses::dw_send;
DWORD Addresses::dw_connect;
DWORD Addresses::dw_select;

// Brandings
DWORD Addresses::UI_BuildNumber;
DWORD Addresses::GameWindowName1;
DWORD Addresses::GameWindowName2;
DWORD Addresses::ConsoleWindowName;
DWORD Addresses::GameWindowStyle1;
DWORD Addresses::GameWindowStyle2;

// DLC Check Hooks
DWORD Addresses::MissingDLC;
DWORD Addresses::CheckFlag;
DWORD Addresses::DLCAppID;


void Addresses::AssignFromPattern()
{
}
void Addresses::Assign()
{
	switch (Global::Game::Version)
	{
		case GAME_VERSION_39:
		{
			Addresses::Com_Error					= (Com_Error_t)0x506AC0;
			Addresses::Com_Printf					= (Com_Printf_t)0x452300;
			Addresses::Cbuf_AddText					= (Cbuf_AddText_t)0x4F43F0;
			Addresses::DB_FindXAssetHeader				= (DB_FindXAssetHeader_t)0x6653A0;
			Addresses::DB_AddXAssetLoc				= (DB_AddXAssetLoc_t)0x7FBCB0;			
			Addresses::Cmd_AddCommandInternal           = (Cmd_AddCommandInternal_t)0x489D80;

			Addresses::FS_FreeFile						= (FS_FreeFile_t)0x40C030;
			Addresses::FS_ReadFile                  = (FS_ReadFile_t)0x50EE60;
			Addresses::FS_FCloseFile                = (FS_FCloseFile_t)0x610130;
			Addresses::FS_FOpenFileByMode				= (FS_FOpenFileByMode_t)0x699780;
			Addresses::FS_ListFiles                 = (FS_ListFiles_t)0x4DC1D0;
			Addresses::FS_FreeFileList				= (FS_FreeFileList_t)0x4481D0;
			Addresses::FS_FileForHandle             = (FS_FileForHandle_t)0x5B2640;
			Addresses::FS_GetFileOsPath             = (FS_GetFileOsPath_t)0x6CE330;
			Addresses::Scr_ExecThread					= (Scr_ExecThread_t)0x489040;
			Addresses::Scr_FreeThread               = (Scr_FreeThread_t)0x4DDD60;

			Addresses::Scr_LoadScriptInternal		= (Scr_LoadScriptInternal_t)0x4B4490;
			Addresses::GScr_LoadScriptAndLabel		= (GScr_LoadScriptAndLabel_t)0x67A0E0;
			Addresses::G_ShutdownGame				= (G_ShutdownGame_t)0x536410;
			Addresses::SL_GetString					= (SL_GetString_t)0x6F5A50;
			Addresses::SL_ConvertToString			= (SL_ConvertToString_t)0x4FE530;
			Addresses::Scr_NotifyNum				= (Scr_NotifyNum_t)0x53D5D0;
			Addresses::Scr_AddString				= (Scr_AddString_t)0x6AB5E0;
			Addresses::Scr_AddEntity				= (Scr_AddEntity_t)0x5C9580;
			Addresses::Scr_AddInt					= (Scr_AddInt_t)0x4E1C20;
			Addresses::Scr_GetString				= (Scr_GetString_t)0x6608D0;
			Addresses::NotifyClient					= (NotifyClient_t)0x4E0140;
			Addresses::Dvar_RegisterBool				= (Dvar_RegisterBool_t)0x5F5D70;
			Addresses::Dvar_RegisterFloat			= (Dvar_RegisterFloat_t)0x4F73D0;
			Addresses::Dvar_RegisterInt				= (Dvar_RegisterInt_t)0x5E49D0;



			// Custom GSC & CSC Loading
			Addresses::scriptParseTreeLoad1_loc			= 0x4FD6E4;
			Addresses::scriptParseTreeLoad2_loc			= 0x40D603;
			Addresses::scriptParseTreeLoad3_loc			= 0x562DC4;
			Addresses::scriptParseTreeLoad4_loc			= 0x551DBF;
			Addresses::loadGameTypeScript_loc			= 0x6450F0;
			Addresses::loadGameType_loc					= 0x6C129D;
			Addresses::scriptErrorParam_loc				= 0x467187;
			Addresses::precacheInitCheck1_loc			= 0x6C1237;
			Addresses::precacheInitCheck2_loc			= 0x6C12DA;
			Addresses::precacheInitCheck3_loc			= 0x82D958;

			// Commands
			Addresses::cmd_argc						= 0x25087DC;
			Addresses::cmd_argv						= 0x25087FC;
			
			// Bots
			Addresses::SV_AddTestClient					= (SV_AddTestClient_t)0x5C87D0;
			Addresses::SV_Loaded					= (SV_Loaded_t)0x580AA0;
			Addresses::g_entities					= (g_entity_s*)0x21BF3C0;
			Addresses::BotArray1						= 0x5C87EB;
			Addresses::BotArray2 						= 0x5C8808;
			Addresses::BotArray3 						= 0x5BC9E1;
			Addresses::BotArraySize1 					= 0x5C87DB;
			Addresses::BotArraySize2  					= 0x5C87FB;
			Addresses::BotArraySize3  					= 0x5BC9BF;
			Addresses::BotArraySize4  					= 0x5BC9D4;
			Addresses::BotTag1  						= 0x65DCA1;
			Addresses::BotTag2  						= 0x40F05A;

			// Hudelems
			Addresses::HudElem_Alloc				= (HudElem_Alloc_t)0x4E3120;
			Addresses::G_LocalizedStringIndex		= (G_LocalizedStringIndex_t)0x44F6B0;
			Addresses::G_MaterialIndex				= (G_MaterialIndex_t)0x542C10;
			Addresses::ShaderPrecacheLimitation			= 0x5FA369;

			// Colored Name
			Addresses::ColoredName						= 0x6F27AF;
			Addresses::ClientUserinfoChanged			= 0x8120F0;
			Addresses::GetClientName				= 0x00;
			Addresses::GetClientName1				= 0x00;
			Addresses::GetClientName2				= 0x00;
			Addresses::GetClientName3				= 0x00;
			Addresses::ICleanStrHook				= 0x00;
			Addresses::ICleanStr					= 0x00;
			Addresses::NameLength1						= 0x52FFAB;
			Addresses::NameLength2						= 0x54DDD3;
			Addresses::ColorTableFloat					= 0xC26690;
			Addresses::ColorTableByte					= 0xCE4BB8;
			
			// Ingame Console
			Addresses::R_AddCmdDrawText					= (R_AddCmdDrawText_t)0x7076C0;
			Addresses::DrawRotatedPic					= (DrawRotatedPic_t)0x7071F0;
			Addresses::GetTextLengthSize				= (GetTextLengthSize_t)0x72A970;
			Addresses::ConsoleCatcher 					= 0x485CB9;
			Addresses::ConsoleCatcher2 					= 0x485CA7;
			Addresses::RendererFrame 					= 0x7E592E;
			Addresses::RendererFrameO 					= 0x6C8630;
			Addresses::RendererStart 					= 0x4C5622;
			Addresses::RendererStartO 					= 0x4FCDF0;
			Addresses::RendererWidth 					= 0x3533428;
			Addresses::RendererHeight 					= 0x353342C;
			Addresses::InputUIToCL 						= 0x6CF4F2;
			Addresses::InputExecBinding	 				= 0x5CF410;
			Addresses::InputExecBindingO 				= 0x5CF415;
			Addresses::InputCharEvent 					= 0x446780;
			Addresses::InputCharEventO 					= 0x446785;
			Addresses::InputKeyEvent 					= 0x6C2D20;
			Addresses::InputKeyEventO 					= 0x6C2D25;
			Addresses::InputMouseX 						= 0x2AF3F60;
			Addresses::InputMouseY 						= 0x2AF3F64;
			Addresses::InputHWND						= 0x2AF9388;

			// Custom Asset
			Addresses::FS_BaseGameFolderName			= 0x8B8D2E;

			// SystemLink SererList
			Addresses::GetServerNameFromList			= 0x64FF70;
			Addresses::GetServerCount					= 0x6CC370;
			Addresses::ServerBaseAddress				= 0x115A998;

			// DW Server
			Addresses::custom_gethostbyname				= 0xB4956C;
			Addresses::dw_recvfrom						= 0xB4951C;
			Addresses::dw_sendto						= 0xB49524;
			Addresses::dw_recv							= 0xB4953C;
			Addresses::dw_send							= 0xB49560;
			Addresses::dw_connect						= 0xB4952C;
			Addresses::dw_select						= 0xB49520;

			// Brandings
			Addresses::UI_BuildNumber					= 0x4C99C2;
			Addresses::GameWindowName1					= 0x4C9EE3;
			Addresses::GameWindowName2					= 0x4C9EEA;
			Addresses::ConsoleWindowName				= 0x62549C;
			Addresses::GameWindowStyle1					= 0x72D2EA;
			Addresses::GameWindowStyle2					= 0x72D304;

			// DLC Check Hooks
			Addresses::MissingDLC						= 0x9615E3;
			Addresses::CheckFlag						= 0x4EF490;
			Addresses::DLCAppID							= 0x65DDD0;
			break;
		}
		case GAME_VERSION_40:
		{
			Addresses::Com_Error						= (Com_Error_t)0x506AC0;
			Addresses::Com_Printf						= (Com_Printf_t)0x452300;
			Addresses::Cbuf_AddText						= (Cbuf_AddText_t)0x4F43F0;
			Addresses::DB_FindXAssetHeader				= (DB_FindXAssetHeader_t)0x526800;
			Addresses::DB_AddXAssetLoc					= (DB_AddXAssetLoc_t)0x7FBCB0;			
			Addresses::Cmd_AddCommandInternal			= (Cmd_AddCommandInternal_t)0x667FA0;

			Addresses::FS_FreeFile						= (FS_FreeFile_t)0x654390;
			Addresses::FS_ReadFile						= (FS_ReadFile_t)0x50EE60;
			Addresses::FS_FCloseFile					= (FS_FCloseFile_t)0x610130;
			Addresses::FS_FOpenFileByMode				= (FS_FOpenFileByMode_t)0x588770;
			Addresses::FS_ListFiles						= (FS_ListFiles_t)0x4DC1D0;
			Addresses::FS_FreeFileList					= (FS_FreeFileList_t)0x4481D0;
			Addresses::FS_FileForHandle					= (FS_FileForHandle_t)0x5B2640;
			Addresses::FS_GetFileOsPath					= (FS_GetFileOsPath_t)0x6CE330;
			Addresses::Scr_ExecThread					= (Scr_ExecThread_t)0x6364E0;
			Addresses::Scr_FreeThread					= (Scr_FreeThread_t)0x4DDD60;

			Addresses::Scr_LoadScriptInternal			= (Scr_LoadScriptInternal_t)0x4B4490;
			Addresses::GScr_LoadScriptAndLabel			= (GScr_LoadScriptAndLabel_t)0x67A0E0;
			Addresses::G_ShutdownGame					= (G_ShutdownGame_t)0x536410;
			Addresses::SL_GetString						= (SL_GetString_t)0x6F5A50;
			Addresses::SL_ConvertToString				= (SL_ConvertToString_t)0x4FE530;
			Addresses::Scr_NotifyNum					= (Scr_NotifyNum_t)0x53D5D0;
			Addresses::Scr_AddString					= (Scr_AddString_t)0x6AB5E0;
			Addresses::Scr_AddEntity					= (Scr_AddEntity_t)0x5C9580;
			Addresses::Scr_AddInt						= (Scr_AddInt_t)0x4E1C20;
			Addresses::Scr_GetString					= (Scr_GetString_t)0x6608D0;
			Addresses::NotifyClient						= (NotifyClient_t)0x4E0140;
			Addresses::Dvar_RegisterBool				= (Dvar_RegisterBool_t)0x4BD840;
			Addresses::Dvar_RegisterFloat				= (Dvar_RegisterFloat_t)0x4F73D0;
			Addresses::Dvar_RegisterInt					= (Dvar_RegisterInt_t)0x5E49D0;



			// Custom GSC & CSC Loading
			Addresses::scriptParseTreeLoad1_loc			= 0x6B27F4;
			Addresses::scriptParseTreeLoad2_loc			= 0x4B44F3;
			Addresses::scriptParseTreeLoad3_loc			= 0x561524;
			Addresses::scriptParseTreeLoad4_loc			= 0x67A12F;
			Addresses::loadGameTypeScript_loc			= 0x488285;
			Addresses::loadGameType_loc					= 0x697E52;
			Addresses::scriptErrorParam_loc				= 0x685EB7;
			Addresses::precacheInitCheck1_loc			= 0x697DEC;
			Addresses::precacheInitCheck2_loc			= 0x697E8F;
			Addresses::precacheInitCheck3_loc			= 0x83a608;

			// Commands
			Addresses::cmd_argc							= 0x25087DC;
			Addresses::cmd_argv							= 0x25087FC;

			// Bots
			Addresses::SV_AddTestClient					= (SV_AddTestClient_t)0x62C140;//Spawn bot -> 0x853000 game call this function
			Addresses::SV_Loaded						= (SV_Loaded_t)0x580AA0;
			Addresses::g_entities						= (g_entity_s*)0x21BF3C0;
			Addresses::BotArray1						= 0x49214B;
			Addresses::BotArray2						= 0x492168;
			Addresses::BotArray3						= 0x4F7DA1;
			Addresses::BotArraySize1					= 0x49213B;
			Addresses::BotArraySize2					= 0x49215B;
			Addresses::BotArraySize3					= 0x4F7D7F;
			Addresses::BotArraySize4					= 0x4F7D94;
			Addresses::BotTag1							= 0x644183;
			Addresses::BotTag2							= 0x62C28C;

			// Hudelems
			Addresses::HudElem_Alloc					= (HudElem_Alloc_t)0x4E3120;
			Addresses::G_LocalizedStringIndex			= (G_LocalizedStringIndex_t)0x44F6B0;
			Addresses::G_MaterialIndex					= (G_MaterialIndex_t)0x542C10;
			Addresses::ShaderPrecacheLimitation			= 0x542C89;

			// Colored Name
			Addresses::ColoredName						= 0x64C31F;
			Addresses::ClientUserinfoChanged			= 0x81ED10;
			Addresses::GetClientName					= 0x61E650;
			Addresses::GetClientName1					= 0x7A2939;
			Addresses::GetClientName2					= 0x7A29AC;
			Addresses::GetClientName3					= 0x9773D3;
			Addresses::ICleanStrHook					= 0x61E6EA;
			Addresses::ICleanStr						= 0x6DAF80;
			Addresses::NameLength1						= 0x4C8BAB;
			Addresses::NameLength2						= 0x4A2C53;
			Addresses::ColorTableFloat					= 0xC63C50;
			Addresses::ColorTableByte					= 0xD254B8;

			// Ingame Console
			Addresses::R_AddCmdDrawText					= (R_AddCmdDrawText_t)0x70F6A0;
			Addresses::DrawRotatedPic					= (DrawRotatedPic_t)0x70F1D0;
			Addresses::GetTextLengthSize				= (GetTextLengthSize_t)0x732590;
			Addresses::ConsoleCatcher					= 0x44DD89;
			Addresses::ConsoleCatcher2					= 0x44DD77;
			Addresses::RendererFrame					= 0x7EDD9E;
			Addresses::RendererFrameO					= 0x5EBFB0;
			Addresses::RendererStart					= 0x4DBF32;
			Addresses::RendererStartO					= 0x6CBAD0;
			Addresses::RendererWidth					= 0x35771A8;
			Addresses::RendererHeight					= 0x35771AC;
			Addresses::InputUIToCL						= 0x67D0D2;
			Addresses::InputExecBinding					= 0x572040;
			Addresses::InputExecBindingO				= 0x572045;
			Addresses::InputCharEvent					= 0x4022E0;
			Addresses::InputCharEventO					= 0x4022E5;
			Addresses::InputKeyEvent					= 0x6E7820;
			Addresses::InputKeyEventO					= 0x6E7825;
			Addresses::InputMouseX						= 0x2B37CE0;
			Addresses::InputMouseY						= 0x2B37CE4;
			Addresses::InputHWND						= 0x2B3D108;

			// Custom Asset
			Addresses::FS_BaseGameFolderName			= 0x8C4E3E;

			// SystemLink SererList
			Addresses::GetServerNameFromList			= 0x458DA0;
			Addresses::GetServerCount					= 0x60E9A0;
			Addresses::ServerBaseAddress				= 0x119AD28;

			// DW Server
			Addresses::custom_gethostbyname				= 0xB6B56C;
			Addresses::dw_recvfrom						= 0xB6B51C;
			Addresses::dw_sendto						= 0xB6B524;
			Addresses::dw_recv							= 0xB6B53C;
			Addresses::dw_send							= 0xB6B560;
			Addresses::dw_connect						= 0xB6B52C;
			Addresses::dw_select						= 0xB6B520;

			// Brandings
			Addresses::UI_BuildNumber					= 0x60CBA2;
			Addresses::GameWindowName1					= 0x656253;
			Addresses::GameWindowName2					= 0x65625A;
			Addresses::ConsoleWindowName				= 0x6EA16C;
			Addresses::GameWindowStyle1					= 0x734F1A;
			Addresses::GameWindowStyle2					= 0x734F34;

			// DLC Check Hooks
			Addresses::MissingDLC						= 0x96ED53;
			Addresses::CheckFlag						= 0x652C40;
			Addresses::DLCAppID							= 0x429A40;
			break;
		}
		case GAME_VERSION_41:
		{
			Addresses::Com_Error						= (Com_Error_t)0x6013A0;
			Addresses::Com_Printf						= (Com_Printf_t)0x484B00;
			Addresses::Cbuf_AddText						= (Cbuf_AddText_t)0x6B9D20;
			Addresses::DB_FindXAssetHeader				= (DB_FindXAssetHeader_t)0x43F460;
			Addresses::DB_AddXAssetLoc					= (DB_AddXAssetLoc_t)0x7FD0B0;
			Addresses::Cmd_AddCommandInternal			= (Cmd_AddCommandInternal_t)0x4DC2A0;
			Addresses::FS_FreeFile						= (FS_FreeFile_t)0x5A2220;
			Addresses::FS_ReadFile						= (FS_ReadFile_t)0x60F610;
			Addresses::FS_FCloseFile					= (FS_FCloseFile_t)0x64C560;
			Addresses::FS_FOpenFileByMode				= (FS_FOpenFileByMode_t)0x498F50;
			Addresses::FS_ListFiles						= (FS_ListFiles_t)0x4113C0;
			Addresses::FS_FreeFileList					= (FS_FreeFileList_t)0x6406C0;
			Addresses::FS_FileForHandle					= (FS_FileForHandle_t)0x00;//////////fix
			Addresses::FS_GetFileOsPath					= (FS_GetFileOsPath_t)0x6B51B0;
			Addresses::Scr_ExecThread					= (Scr_ExecThread_t)0x436DA0;
			Addresses::Scr_FreeThread					= (Scr_FreeThread_t)0x617D60;
			Addresses::Scr_LoadScriptInternal			= (Scr_LoadScriptInternal_t)0x608360;
			Addresses::GScr_LoadScriptAndLabel			= (GScr_LoadScriptAndLabel_t)0x53E5A0;
			Addresses::G_ShutdownGame					= (G_ShutdownGame_t)0x688A40;//
			Addresses::SL_GetString						= (SL_GetString_t)0x4601E0;
			Addresses::SL_ConvertToString				= (SL_ConvertToString_t)0x532230;
			Addresses::Scr_NotifyNum					= (Scr_NotifyNum_t)0x664770;
			Addresses::Scr_AddString					= (Scr_AddString_t)0x5A5540;
			Addresses::Scr_AddEntity					= (Scr_AddEntity_t)0x5D8F80;
			Addresses::Scr_AddInt						= (Scr_AddInt_t)0x503480;
			Addresses::Scr_GetString					= (Scr_GetString_t)0x488110;
			Addresses::NotifyClient						= (NotifyClient_t)0x45B660;
			Addresses::Dvar_RegisterBool				= (Dvar_RegisterBool_t)0x5FBCC0;
			Addresses::Dvar_RegisterFloat				= (Dvar_RegisterFloat_t)0x4D0480;
			Addresses::Dvar_RegisterInt					= (Dvar_RegisterInt_t)0x5A3D70;



			// Custom GSC & CSC Loading
			Addresses::scriptParseTreeLoad1_loc			= 0x6648A4;
			Addresses::scriptParseTreeLoad2_loc			= 0x6083C3;
			Addresses::scriptParseTreeLoad3_loc			= 0x624494;
			Addresses::scriptParseTreeLoad4_loc			= 0x53E5EF;
			Addresses::loadGameTypeScript_loc			= 0x47E0E0;
			Addresses::loadGameType_loc					= 0x67F02D;
			Addresses::scriptErrorParam_loc				= 0x4F0727;
			Addresses::precacheInitCheck1_loc			= 0x67EFC7;
			Addresses::precacheInitCheck2_loc			= 0x67F06A;
			Addresses::precacheInitCheck3_loc			= 0x83AA08;

			// Commands
			Addresses::cmd_argc							= 0x250A75C;
			Addresses::cmd_argv							= 0x250A77C;

			// Bots
			Addresses::SV_AddTestClient					= (SV_AddTestClient_t)0x428A90;//Spawn bot -> 0x853000 game call this function
			Addresses::SV_Loaded						= (SV_Loaded_t)0x6F4880;
			Addresses::g_entities						= (g_entity_s*)0x21C13C0;
			Addresses::BotArray1						= 0x62D76B;
			Addresses::BotArray2						= 0x62D788;
			Addresses::BotArray3						= 0x6D4811;
			Addresses::BotArraySize1					= 0x62D75B;
			Addresses::BotArraySize2					= 0x62D77B;
			Addresses::BotArraySize3					= 0x6D47EF;
			Addresses::BotArraySize4					= 0x6D4804;
			Addresses::BotTag1							= 0x4981D2;
			Addresses::BotTag2							= 0x428BDB;

			// Hudelems
			Addresses::HudElem_Alloc					= (HudElem_Alloc_t)0x69F5A0;
			Addresses::G_LocalizedStringIndex			= (G_LocalizedStringIndex_t)0x467CD0;
			Addresses::G_MaterialIndex					= (G_MaterialIndex_t)0x40AF20;
			Addresses::ShaderPrecacheLimitation			= 0x40AF99;

			// Colored Name
			Addresses::ColoredName						= 0x40906F;
			Addresses::ClientUserinfoChanged			= 0x81F230;
			Addresses::GetClientName					= 0x00;//
			Addresses::GetClientName1					= 0x00;//
			Addresses::GetClientName2					= 0x00;//
			Addresses::GetClientName3					= 0x00;//
			Addresses::ICleanStrHook					= 0x00;//
			Addresses::ICleanStr						= 0x00;//
			Addresses::NameLength1						= 0x4CF5AB;
			Addresses::NameLength2						= 0x53B0C3;
			Addresses::ColorTableFloat					= 0xC64840;
			Addresses::ColorTableByte					= 0xD24A28;

			// Ingame Console
			Addresses::R_AddCmdDrawText					= (R_AddCmdDrawText_t)0x70F440;
			Addresses::DrawRotatedPic					= (DrawRotatedPic_t)0x70EF70;
			Addresses::GetTextLengthSize				= (GetTextLengthSize_t)0x732710;
			Addresses::ConsoleCatcher					= 0x58E219;
			Addresses::ConsoleCatcher2					= 0x58E207;
			Addresses::RendererFrame					= 0x7EF1EE;
			Addresses::RendererFrameO					= 0x4AF5A0;
			Addresses::RendererStart					= 0x6CE2A2;
			Addresses::RendererStartO					= 0x560040;
			Addresses::RendererWidth					= 0x3579128;
			Addresses::RendererHeight					= 0x357912C;
			Addresses::InputUIToCL						= 0x5A3C32;
			Addresses::InputExecBinding					= 0x4554E0;
			Addresses::InputExecBindingO				= 0x4554E5;
			Addresses::InputCharEvent					= 0x6E5BB0;
			Addresses::InputCharEventO					= 0x6E5BB5;
			Addresses::InputKeyEvent					= 0x60C4A0;
			Addresses::InputKeyEventO					= 0x60C4A5;
			Addresses::InputMouseX						= 0x2B39C60;
			Addresses::InputMouseY						= 0x2B39C64;
			Addresses::InputHWND						= 0x2B3F088;

			// Custom Asset
			Addresses::FS_BaseGameFolderName			= 0x8C564E;

			// SystemLink SererList
			Addresses::GetServerNameFromList			= 0x57AE20;
			Addresses::GetServerCount					= 0x594EB0;
			Addresses::ServerBaseAddress				= 0x119CD28;

			// DW Server
			Addresses::custom_gethostbyname				= 0xB6A56C;
			Addresses::dw_recvfrom						= 0xB6A51C;
			Addresses::dw_sendto						= 0xB6A524;
			Addresses::dw_recv							= 0xB6A53C;
			Addresses::dw_send							= 0xB6A560;
			Addresses::dw_connect						= 0xB6A52C;
			Addresses::dw_select						= 0xB6A520;

			// Brandings
			Addresses::UI_BuildNumber					= 0x660D32;
			Addresses::GameWindowName1					= 0x482E83;
			Addresses::GameWindowName2					= 0x482E8A;
			Addresses::ConsoleWindowName				= 0x5F799C;
			Addresses::GameWindowStyle1					= 0x7350AA;
			Addresses::GameWindowStyle2					= 0x7350C4;

			// DLC Check Hooks
			Addresses::MissingDLC						= 0x00;
			Addresses::CheckFlag						= 0x00;
			Addresses::DLCAppID							= 0x00;
			break;
		}
		case GAME_VERSION_43:
		{
			Addresses::Com_Error                        = (Com_Error_t)0x58FC30;
			Addresses::Com_Printf						= (Com_Printf_t)0x63A1F0;
			Addresses::Cbuf_AddText                     = (Cbuf_AddText_t)0x5C6F10;
			Addresses::DB_FindXAssetHeader				= (DB_FindXAssetHeader_t)0x6F9030;
			Addresses::DB_AddXAssetLoc                  = (DB_AddXAssetLoc_t)0x07FDCB0;
			Addresses::Cmd_AddCommandInternal			= (Cmd_AddCommandInternal_t)0x5B3070;
			Addresses::FS_FreeFile						= (FS_FreeFile_t)0x6DC730;
			Addresses::FS_ReadFile                      = (FS_ReadFile_t)0x513030;
			Addresses::FS_FCloseFile                    = (FS_FCloseFile_t)0x494570;
			Addresses::FS_FOpenFileByMode				= (FS_FOpenFileByMode_t)0x521620;
			Addresses::FS_ListFiles                     = (FS_ListFiles_t)0x52F100;
			Addresses::FS_FreeFileList                  = (FS_FreeFileList_t)0x443EB0;
			Addresses::FS_FileForHandle					= (FS_FileForHandle_t)0x46D830;
			Addresses::FS_GetFileOsPath                 = (FS_GetFileOsPath_t)0x688D80;
			Addresses::Scr_ExecThread					= (Scr_ExecThread_t)0x4BB610;
			Addresses::Scr_FreeThread                   = (Scr_FreeThread_t)0x5468A0;
			Addresses::Scr_LoadScriptInternal           = (Scr_LoadScriptInternal_t)0x5D2720;
			Addresses::GScr_LoadScriptAndLabel          = (GScr_LoadScriptAndLabel_t)0x416D30;
			Addresses::G_ShutdownGame                   = (G_ShutdownGame_t)0x60DCF0;
			Addresses::SL_GetString						= (SL_GetString_t)0x602C40; // Not 100% sure if its correct
			Addresses::SL_ConvertToString				= (SL_ConvertToString_t)0x422D10;
			Addresses::Scr_NotifyNum					= (Scr_NotifyNum_t)0x578690;
			Addresses::Scr_AddString					= (Scr_AddString_t)0x4F1650;
			Addresses::Scr_AddEntity					= (Scr_AddEntity_t)0x4C20F0;
			Addresses::Scr_AddInt						= (Scr_AddInt_t)0x57AFF0;
			Addresses::Scr_GetString					= (Scr_GetString_t)0x67C6A0;
			Addresses::NotifyClient						= (NotifyClient_t)0x459520;
			Addresses::Dvar_RegisterBool                = (Dvar_RegisterBool_t)0x4E0170;
			Addresses::Dvar_RegisterFloat				= (Dvar_RegisterFloat_t)0x4445C0;
			Addresses::Dvar_RegisterInt					= (Dvar_RegisterInt_t)0x5F24E0;



			// Custom GSC & CSC Loading
			Addresses::scriptParseTreeLoad1_loc			= 0x5B7C44;
			Addresses::scriptParseTreeLoad2_loc			= 0x5D2783;
			Addresses::scriptParseTreeLoad3_loc			= 0x48EE84;
			Addresses::scriptParseTreeLoad4_loc			= 0x416D7F;
			Addresses::loadGameTypeScript_loc			= 0x5B5A05;
			Addresses::loadGameType_loc					= 0x4A1CE2;
			Addresses::scriptErrorParam_loc				= 0x6CDAD7;
			Addresses::precacheInitCheck1_loc			= 0x4A1C7C;
			Addresses::precacheInitCheck2_loc			= 0x4A1D1F;
			Addresses::precacheInitCheck3_loc			= 0x83C108;

			// Commands
			Addresses::cmd_argc							= 0x2538BDC;
			Addresses::cmd_argv							= 0x2538BFC;

			// Bots
			Addresses::SV_AddTestClient					= (SV_AddTestClient_t)0x5514B0;
			Addresses::SV_Loaded						= (SV_Loaded_t)0x510FC0;
			Addresses::g_entities						= (g_entity_s*)0x21EF7C0;
			Addresses::BotArray1						= 0x6A2C8B;
			Addresses::BotArray2						= 0x6A2CA8;
			Addresses::BotArray3						= 0x667E61;
			Addresses::BotArraySize1					= 0x6A2C7B;
			Addresses::BotArraySize2					= 0x6A2C9B;
			Addresses::BotArraySize3					= 0x667E3F;
			Addresses::BotArraySize4					= 0x667E54;
			Addresses::BotTag1							= 0x679BF3;
			Addresses::BotTag2							= 0x5515FC;

			// Hudelems
			Addresses::HudElem_Alloc                    = (HudElem_Alloc_t)0x479DF0;
			Addresses::G_LocalizedStringIndex           = (G_LocalizedStringIndex_t)0x6D64E0;
			Addresses::G_MaterialIndex                  = (G_MaterialIndex_t)0x5F0320;
			Addresses::ShaderPrecacheLimitation			= 0x5F0399;

			// Colored Name
			Addresses::ColoredName						= 0x6286FF;
			Addresses::ClientUserinfoChanged			= 0x820830;
			Addresses::GetClientName					= 0x5B0F50;
			Addresses::GetClientName1					= 0x7A4129;
			Addresses::GetClientName2					= 0x7A419C;
			Addresses::GetClientName3					= 0x9795A3;
			Addresses::ICleanStrHook					= 0x5B0FEA;
			Addresses::ICleanStr						= 0x44F2B0;
			Addresses::NameLength1						= 0x53F25B;
			Addresses::NameLength2						= 0x5F0283;
			Addresses::ColorTableFloat					= 0xC6EC80;
			Addresses::ColorTableByte					= 0xD30A08;

			// Ingame Console
			Addresses::R_AddCmdDrawText					= (R_AddCmdDrawText_t)0x711150;
			Addresses::DrawRotatedPic					= (DrawRotatedPic_t)0x710C80;
			Addresses::GetTextLengthSize				= (GetTextLengthSize_t)0x734020;
			Addresses::ConsoleCatcher 					= 0x5DA6C9;
			Addresses::ConsoleCatcher2 					= 0x5DA6B7;
			Addresses::RendererFrame 					= 0x7EF9FE;
			Addresses::RendererFrameO 					= 0x583EE0;
			Addresses::RendererStart 					= 0x5990E2;
			Addresses::RendererStartO 					= 0x632110;
			Addresses::RendererWidth 					= 0x35A9328;
			Addresses::RendererHeight 					= 0x35A932C;
			Addresses::InputUIToCL 						= 0x651682;
			Addresses::InputExecBinding 				= 0x66C390;
			Addresses::InputExecBindingO 				= 0x66C395;
			Addresses::InputCharEvent 					= 0x68B960;
			Addresses::InputCharEventO 					= 0x68B965;
			Addresses::InputKeyEvent 					= 0x5D0980;
			Addresses::InputKeyEventO 					= 0x5D0985;
			Addresses::InputMouseX 						= 0x2B69960;
			Addresses::InputMouseY 						= 0x2B69964;
			Addresses::InputHWND 						= 0x2B6ED88;

			// Custom Asset
			Addresses::FS_BaseGameFolderName			= 0x8C6A0E;

			// SystemLink SererList
			Addresses::GetServerNameFromList			= 0x520E00;
			Addresses::GetServerCount					= 0x705630;
			Addresses::ServerBaseAddress				= 0x11C7F18;

			// DW Server
			Addresses::custom_gethostbyname				= 0xB7056C;
			Addresses::dw_recvfrom						= 0xB7051C;
			Addresses::dw_sendto						= 0xB70524;
			Addresses::dw_recv							= 0xB7053C;
			Addresses::dw_send							= 0xB70560;
			Addresses::dw_connect						= 0xB7052C;
			Addresses::dw_select						= 0xB70520;

			// Brandings
			Addresses::UI_BuildNumber					= 0x53ED42;
			Addresses::GameWindowName1					= 0x5A6343;
			Addresses::GameWindowName2					= 0x5A634A;
			Addresses::ConsoleWindowName				= 0x562EAC;
			Addresses::GameWindowStyle1					= 0x7369AA;
			Addresses::GameWindowStyle2					= 0x7369C4;

			// DLC Check Hooks
			Addresses::MissingDLC						= 0x970DB3;
			Addresses::CheckFlag						= 0x429440;
			Addresses::DLCAppID							= 0x473B20;
			break;
		}
	}
	Addresses::AssignFromPattern();
}
bool Addresses::FS_FileExists(const char* file)
{
	return (Addresses::FS_FOpenFileByMode(file, 0, FS_READ) > 0);
}
void Addresses::FS_VectoredListFiles(const char *path, const char *extension, FsListBehavior_e behavior, std::vector<std::string> &vector, bool absolute, bool append)
{
	if (!append) vector.clear();
	int count = 0;
	const char** list = Addresses::FS_ListFiles(path, extension, behavior, &count, 0xC);
	for (int i = 0; i < count; i++)
	{
		vector.push_back(hString::va("%s%s", (absolute ? path : ""), list[i]));
		Addresses::Com_Printf(hString::va("%s%s", (absolute ? path : ""), list[i]));
		Addresses::Com_Printf(hString::va("%s%s", path, list[i]));
	}
	Addresses::FS_FreeFileList(list, 0xC);
}