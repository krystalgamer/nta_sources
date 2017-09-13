#pragma once
class HudElements
{
public:
	static HudElem* HudElem_Allocate();
	static void HudElem_Init(HudElem* elem, int client);
	static void HudElem_Free(HudElem* elem);
	static void HudElem_SetAlign(HudElem* elem, HudElemAlign align);
	static void HudElem_SetText(HudElem* elem, const char* text);
	static void HudElem_SetIcon(HudElem* elem, const char* material);
	static void HudElem_SetColor(HudElem* elem, char r, char g, char b, char a);
	static void HudElem_SetGlow(HudElem* elem, char r, char g, char b, char a);
	static void Initialize();
};