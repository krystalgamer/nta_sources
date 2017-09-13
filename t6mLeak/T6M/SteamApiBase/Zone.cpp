#include "STDInc.h"
Hook::Stomp Zone::CustomAssetHook;


//mp 40
typedef int(__cdecl * a_t)(int*, int, int, int);
a_t a = (a_t)0x58E8A0;

typedef int(__cdecl * b_t)(const char*, int, int);
b_t b = (b_t)0x667CA0;


int sub_FC57C20()
{
	int v1;
	v1 = (int)"patch_Sonsored";
	a(&v1, 1, 0, 0);
	return b("patch_Sonsored", 64, 64);
}











void Zone::Initialize()
{
	//Loading Custom Fast Files
	//Zone::CustomAssetHook.Initialize(0x5E029F, sub_FC57C20);
	//Zone::CustomAssetHook.InstallHook();



}