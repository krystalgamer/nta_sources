#pragma once
typedef void(__cdecl * Com_Error_t)(errorParm_t code, const char *fmt, ...);
typedef XAssetHeader(__cdecl * DB_FindXAssetHeader_t)(XAssetType type, const char *name, bool errorIfMissing, int waitTime);
typedef int(__cdecl * DB_AddXAssetLoc_t)(int a1);
typedef void(__cdecl * Cmd_AddCommandInternal_t)(const char* name, CommandCB_t callback, cmd_function_s *);
typedef void(__cdecl * Cbuf_AddText_t)(int client, const char* cmd);
typedef dvar_t* (__cdecl * Dvar_RegisterBool_t)(const char* name, bool default, int flags, const char* description);
typedef int(__cdecl * FS_FOpenFileByMode_t)(const char *qpath, int *f, fsMode_t mode);
typedef void(__cdecl * FS_FCloseFile_t)(int h);
typedef void(__cdecl * FS_FreeFile_t)(const void *buffer);
typedef int(__cdecl * FS_ReadFile_t)(const char *qpath, void **buffer);
typedef const char **(__cdecl * FS_ListFiles_t)(const char *path, const char *extension, FsListBehavior_e behavior, int *numfiles, int allocTrackType);
typedef void(__cdecl * FS_FreeFileList_t)(const char **list, int allocTrackType);
typedef FILE*(__cdecl * FS_FileForHandle_t)(int f);
typedef int(__cdecl * FS_GetFileOsPath_t)(const char *filename, char *ospath);
typedef unsigned short(__cdecl * Scr_ExecThread_t)(scriptInstance_t inst, int handle, unsigned int paramcount);
typedef void(__cdecl * Scr_FreeThread_t)(scriptInstance_t inst, unsigned __int16 handle);
typedef unsigned int(__cdecl * Scr_LoadScriptInternal_t)(scriptInstance_t inst, const char *filename);
typedef int(__cdecl * Scr_GetFunctionHandle_t)(scriptInstance_t inst, const char *filename, const char *name, unsigned int *checksum, bool errorIfMissing);
typedef int(__cdecl * GScr_LoadScriptAndLabel_t)(scriptInstance_t inst, const char *filename, const char *label, int* bEnforceExists, bool errorIfMissing);
typedef void(__cdecl * G_ShutdownGame_t)(int freeScripts);
typedef bool(__cdecl * SV_Loaded_t)();
typedef g_entity_s* (__cdecl * SV_AddTestClient_t)();
typedef HudElem* (__cdecl * HudElem_Alloc_t)(int, int);
typedef short(__cdecl * G_LocalizedStringIndex_t)(const char* text);
typedef short(__cdecl * G_MaterialIndex_t)(const char* material);
typedef short(__cdecl * SL_GetString_t)(const char* string, int);
typedef char* (_cdecl* SL_ConvertToString_t)(short ref);
typedef void(__cdecl * Scr_NotifyNum_t)(int number, int type, short notify, int numArgs);
typedef int(__cdecl * Scr_AddString_t)(int, const char* value);
typedef int(__cdecl * Scr_AddEntity_t)(int, g_entity_s* value);
typedef int(__cdecl * Scr_AddInt_t)(int, int value);
typedef char* (_cdecl* Scr_GetString_t)(int, int argNum);
typedef void(__cdecl * Com_Printf_t)(const char *fmt, ...);
typedef void(__cdecl * NotifyClient_t)(int a1, const char* a2, const char* a3, const char* a4, int a5);
typedef void(__cdecl* R_AddCmdDrawText_t)(const char* Text, int NumOfChars, Font_s* Font, float X, float Y, float ScaleX, float ScaleY, float unk1, tColor Color, int unk2);
typedef void(__cdecl* DrawRotatedPic_t)(float x, float y, float angle, float w, float h, float dupw, float duph, float dupw2, float duph2, tColor* Color, Material* material);
typedef float(__cdecl* GetTextLengthSize_t)(DWORD, const char* Test, int Size, Font_s* Font);
typedef dvar_t* (__cdecl * Dvar_RegisterFloat_t)(const char* name, float default, float min, float max, int flags, const char* description);
typedef dvar_t* (__cdecl * Dvar_RegisterInt_t)(const char* name, int default, int min, int max, int flags, const char* description);


class Addresses
{
public:
	static Com_Error_t Com_Error;
	static Com_Printf_t Com_Printf;
	static Cbuf_AddText_t Cbuf_AddText;
	static DB_FindXAssetHeader_t DB_FindXAssetHeader;
	static DB_AddXAssetLoc_t DB_AddXAssetLoc;
	static Cmd_AddCommandInternal_t  Cmd_AddCommandInternal;
	static FS_FreeFile_t FS_FreeFile;
	static FS_ReadFile_t FS_ReadFile;
	static FS_FCloseFile_t FS_FCloseFile;
	static FS_FOpenFileByMode_t FS_FOpenFileByMode;
	static FS_ListFiles_t FS_ListFiles;
	static FS_FreeFileList_t FS_FreeFileList;
	static FS_FileForHandle_t FS_FileForHandle;
	static FS_GetFileOsPath_t FS_GetFileOsPath;
	static Scr_ExecThread_t Scr_ExecThread;
	static Scr_FreeThread_t Scr_FreeThread;
	static Scr_LoadScriptInternal_t Scr_LoadScriptInternal;
	static GScr_LoadScriptAndLabel_t GScr_LoadScriptAndLabel;
	static G_ShutdownGame_t G_ShutdownGame;//
	static SL_GetString_t SL_GetString;
	static SL_ConvertToString_t SL_ConvertToString;
	static Scr_NotifyNum_t Scr_NotifyNum;
	static Scr_AddString_t Scr_AddString;
	static Scr_AddEntity_t Scr_AddEntity;
	static Scr_AddInt_t Scr_AddInt;
	static Scr_GetString_t Scr_GetString;
	static NotifyClient_t NotifyClient;
	static Dvar_RegisterBool_t  Dvar_RegisterBool;
	static Dvar_RegisterFloat_t Dvar_RegisterFloat;
	static Dvar_RegisterInt_t Dvar_RegisterInt;


	// Custom GSC & CSC Loading
	static DWORD scriptParseTreeLoad1_loc;
	static DWORD scriptParseTreeLoad2_loc;
	static DWORD scriptParseTreeLoad3_loc;
	static DWORD scriptParseTreeLoad4_loc;
	static DWORD loadGameTypeScript_loc;
	static DWORD loadGameType_loc;
	static DWORD scriptErrorParam_loc;
	static DWORD precacheInitCheck1_loc;
	static DWORD precacheInitCheck2_loc;
	static DWORD precacheInitCheck3_loc;

	// Commands
	static DWORD cmd_argc;
	static DWORD cmd_argv;

	// Bots
	static SV_AddTestClient_t SV_AddTestClient;
	static SV_Loaded_t SV_Loaded;
	static g_entity_s* g_entities;
	static DWORD BotArray1;
	static DWORD BotArray2;
	static DWORD BotArray3;
	static DWORD BotArraySize1;
	static DWORD BotArraySize2;
	static DWORD BotArraySize3;
	static DWORD BotArraySize4;
	static DWORD BotTag1;
	static DWORD BotTag2;

	// Hudelems
	static HudElem_Alloc_t HudElem_Alloc;
	static G_LocalizedStringIndex_t G_LocalizedStringIndex;
	static G_MaterialIndex_t G_MaterialIndex;
	static DWORD ShaderPrecacheLimitation;

	// Colored Name
	static DWORD ColoredName;
	static DWORD ClientUserinfoChanged;
	static DWORD GetClientName;
	static DWORD GetClientName1;
	static DWORD GetClientName2;
	static DWORD GetClientName3;
	static DWORD ICleanStrHook;
	static DWORD ICleanStr;
	static DWORD NameLength1;
	static DWORD NameLength2;
	static DWORD ColorTableFloat;
	static DWORD ColorTableByte;

	// Ingame Console
	static R_AddCmdDrawText_t R_AddCmdDrawText;
	static DrawRotatedPic_t DrawRotatedPic;
	static GetTextLengthSize_t GetTextLengthSize;
	static DWORD ConsoleCatcher;
	static DWORD ConsoleCatcher2;
	static DWORD RendererFrame;
	static DWORD RendererFrameO;
	static DWORD RendererStart;
	static DWORD RendererStartO;
	static DWORD RendererWidth;
	static DWORD RendererHeight;
	static DWORD InputUIToCL;
	static DWORD InputExecBinding;
	static DWORD InputExecBindingO;
	static DWORD InputCharEvent;
	static DWORD InputCharEventO;
	static DWORD InputKeyEvent;
	static DWORD InputKeyEventO;
	static DWORD InputMouseX;
	static DWORD InputMouseY;
	static DWORD InputHWND;

	// Custom Asset
	static DWORD FS_BaseGameFolderName;

	// SystemLink SererList
	static DWORD GetServerNameFromList;
	static DWORD GetServerCount;
	static DWORD ServerBaseAddress;

	// DW Server
	static DWORD custom_gethostbyname;
	static DWORD dw_recvfrom;
	static DWORD dw_sendto;
	static DWORD dw_recv;
	static DWORD dw_send;
	static DWORD dw_connect;
	static DWORD dw_select;

	// Brandings
	static DWORD UI_BuildNumber;
	static DWORD GameWindowName1;
	static DWORD GameWindowName2;
	static DWORD ConsoleWindowName;
	static DWORD GameWindowStyle1;
	static DWORD GameWindowStyle2;

	// DLC Check Hooks
	static DWORD MissingDLC;
	static DWORD CheckFlag;
	static DWORD DLCAppID;


	static void AssignFromPattern();
	static void Assign();
	static bool FS_FileExists(const char* file);
	static void FS_VectoredListFiles(const char *path, const char *extension, FsListBehavior_e behavior, std::vector<std::string> &vector, bool absolute = false, bool append = true);
};
