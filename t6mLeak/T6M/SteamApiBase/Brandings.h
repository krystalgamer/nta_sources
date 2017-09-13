#pragma once
class Brandings
{
private:
	static dvar_t* r_noborder;
	static int BuildNumber;
	static const char* UI_BuildNumberText;
	static const char* GameWindowCaption;
	static const char* ConsoleWindowCaption;

public:
	static void Initialize();
};