#include "STDInc.h"

const char* test1(char *arg0, size_t arg4, char *arg8, char* arg9, char* arg10)
{
	const char* EndConst = hString::va(arg8, arg9);
	
	// Todo soemthing like StingContains("exec ") :D or startwith
	//Todo remove exec from start with space after exec

	//if (strcomp)
	//{
	//	strstr(arg9, "exec");
	//	Addresses::Cbuf_AddText(0, arg9);
	//}

	//MessageBoxA(0, arg0, 0, 0);//nothing
	//MessageBoxA(0, arg8, 0, 0);//%s shit
	//MessageBoxA(0, arg9, 0, 0);// text
	return EndConst;
}

typedef g_entity_s* (__cdecl * G_Spawn_t)();
G_Spawn_t G_Spawn = (G_Spawn_t)0x6945D0;

g_entity_s* test2()
{
	Log::Error("", hString::va("%lx", _ReturnAddress()));
	return G_Spawn();
}
void test3(int a1, int a2)
{
	MessageBoxA(0, hString::va("%lx, %lx", a1, a2), 0, 0);
}



typedef void(__cdecl * sub_403D80_t)(g_entity_s*, int);
sub_403D80_t sub_403D80 = (sub_403D80_t)0x403D80;

typedef int(__cdecl * sub_4BF330_t)(int, int);
sub_4BF330_t sub_4BF330 = (sub_4BF330_t)0x4BF330;

typedef int(__cdecl * sub_445B90_t)(int, int);
sub_445B90_t sub_445B90 = (sub_445B90_t)0x445B90;

typedef int(__cdecl * sub_5BFD40_t)(int, int, int*);
sub_5BFD40_t sub_5BFD40 = (sub_5BFD40_t)0x5BFD40;

typedef int(__cdecl * sub_5B1760_t)(int);
sub_5B1760_t sub_5B1760 = (sub_5B1760_t)0x445B90;

typedef int(__cdecl * sub_5C9580_t)(int, g_entity_s*);
sub_5C9580_t sub_5C9580 = (sub_5C9580_t)0x5C9580;

typedef bool(__cdecl * sub_40C250_t)(g_entity_s*);
sub_40C250_t sub_40C250 = (sub_40C250_t)0x40C250;

typedef int(__cdecl * sub_4FE530_t)(int);
sub_4FE530_t sub_4FE530 = (sub_4FE530_t)0x4FE530;
void test4()
{
	int v0; // edi@1
	int v1 = 0; // ebx@2
	g_entity_s* v2; // esi@4
	int result; // eax@5
	int v4; // eax@6
	int v6 = 0; // [sp+Ch] [bp-Ch]@1
	int v7 = 0; // [sp+10h] [bp-8h]@4
	int v8 = 0; // [sp+14h] [bp-4h]@4

	v0 = (unsigned __int16)sub_445B90(0, 0);
	sub_5BFD40(0, 1, &v6);
	if (sub_5B1760(0) <= 2u)
		v1 = 0;
	else
		v1 = sub_4BF330(0, 2);
	v2 = G_Spawn();
	sub_403D80(v2 + 374, v0);//sp script model?
	*(DWORD*)(v2 + 308) = v6;
	*(DWORD*)(v2 + 312) = v7;
	*(DWORD*)(v2 + 316) = v8;
	*(DWORD*)(v2 + 388) = v1;
	if (sub_40C250(v2))
	{
		result = sub_5C9580(0, v2);
	}
	else
	{
		v4 = sub_4FE530(v0);
		Addresses::Com_Error(errorParm_t::ERR_FATAL, hString::va("unable to spawn \"%s\" entity", v4), 0);
	}
	//return result;
}
void Experimental::Initialize()
{
	if (Global::Game::Type != GameType::GAME_TYPE_MP)
		if (Global::Game::Version != GameVersion::GAME_VERSION_40)
			return;
	return;
	//QCALL(0x7EB9BF, test1, QPATCH_CALL);
	//QCALL(0x8473B0, test3, QPATCH_CALL);

	static cmd_function_s abc_cmd;
	Addresses::Cmd_AddCommandInternal("abc", test4, &abc_cmd);


	QCALL(0x41C6F7, test2, QPATCH_CALL);
	QCALL(0x44CB9F, test2, QPATCH_CALL);
	QCALL(0x5DA11B, test2, QPATCH_CALL);
	QCALL(0x68B0C5, test2, QPATCH_CALL);
	QCALL(0x68CD83, test2, QPATCH_CALL);
	QCALL(0x6F2301, test2, QPATCH_CALL);
	QCALL(0x6F233B, test2, QPATCH_CALL);
	QCALL(0x6F23FF, test2, QPATCH_CALL);
	QCALL(0x6F2578, test2, QPATCH_CALL);
	QCALL(0x81E896, test2, QPATCH_CALL);
	QCALL(0x82EF51, test2, QPATCH_CALL);
	QCALL(0x835592, test2, QPATCH_CALL);
	QCALL(0x8473A1, test2, QPATCH_CALL);
	QCALL(0x847468, test2, QPATCH_CALL);
	QCALL(0x847797, test2, QPATCH_CALL);
	QCALL(0x85019E, test2, QPATCH_CALL);
	QCALL(0x8503EF, test2, QPATCH_CALL);
	QCALL(0x850802, test2, QPATCH_CALL);
	QCALL(0x859B38, test2, QPATCH_CALL);
}