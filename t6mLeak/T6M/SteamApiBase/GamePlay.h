#pragma once
class GamePlay
{
private:
	static dvar_t* r_fog;
	static Hook::Stomp r_fog_Hook;
	static void GamePlay::r_fog_Hook_Function(DWORD, DWORD);
public:
	static void Initialize();
};