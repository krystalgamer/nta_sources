#pragma once
class MainPatchFunctions
{
public:
	static void XAssetStub(ScriptParseTree** scriptParseTree);
	static const char* HKS_ReturnString(const char* Name);
	static bool HKS_RegisterMaterial(const char *Name, Material **Out);
	static void* HKS_LoadRawfile(const char *Filename);
	static void Load_ScriptParseTreeAsset(ScriptParseTree** scriptParseTree);
	static WeaponVariantDef* Load_WeaponAsset(const char* WeaponName);



	static Hook::Stomp HKS_MaterialHook;
	static Hook::Stomp HKS_StringHook;
	static Hook::Stomp HKS_RawfileHook;
	static Hook::Stomp ScriptParseHook;
	static Hook::Stomp LoadCustomWeaponAsset;
};