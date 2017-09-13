#include "STDInc.h"
HudElem* HudElements::HudElem_Allocate()
{
	HudElem* elem = Addresses::HudElem_Alloc(1023, 0);
	memset(elem, 0, sizeof(HudElem));
	return elem;
}
void HudElements::HudElem_Init(HudElem* elem, int client)
{
	elem->color[0] = 255;
	elem->color[1] = 255;
	elem->color[2] = 255;
	elem->color[3] = 255;

	elem->playerInd = client;
	elem->fontScale = 1.0f;
	elem->font = 0;
	elem->ui3dWindow = 0xFF;
}
void HudElements::HudElem_Free(HudElem* elem)
{
	memset(elem, 0, sizeof(HudElem));
}
void HudElements::HudElem_SetAlign(HudElem* elem, HudElemAlign align)
{
	// Probably there are more accurate values, but these will work for now
	switch (align)
	{
		// TOP
	case TOP_LEFT_COMPASS:
		elem->alignScreen = 0;
		elem->alignOrg = 0;
		break;

	case TOP_LEFT:
		elem->alignScreen = 96;
		elem->alignOrg = 0;
		break;

	case TOP_RIGHT:
		elem->alignScreen = 60;
		elem->alignOrg = 0;
		break;

	case TOP_CENTER:
		elem->alignScreen = 40;
		elem->alignOrg = 20;
		break;


		// CENTER
	case CENTER_LEFT:
		elem->alignScreen = 66;
		elem->alignOrg = 1;
		break;

	case CENTER_RIGHT:
		elem->alignScreen = 55;
		elem->alignOrg = 1;
		break;

	case CENTER_CENTER:
		elem->alignScreen = 34;
		elem->alignOrg = 5;
		break;


		// BOTTOM
	case BOTTOM_LEFT:
		elem->alignScreen = 83;
		elem->alignOrg = 0;
		break;

	case BOTTOM_RIGHT:
		elem->alignScreen = 51;
		elem->alignOrg = 0;
		break;

	case BOTTOM_CENTER:
		elem->alignScreen = 35;
		elem->alignOrg = 7;
		break;
	}
}
void HudElements::HudElem_SetText(HudElem* elem, const char* text)
{
	elem->type = 1;
	elem->text = Addresses::G_LocalizedStringIndex(text);
}
void HudElements::HudElem_SetIcon(HudElem* elem, const char* material)
{
	elem->type = 8;
	elem->materialIndex = Addresses::G_MaterialIndex(material);
}
void HudElements::HudElem_SetColor(HudElem* elem, char r, char g, char b, char a)
{
	elem->color[0] = r;
	elem->color[1] = g;
	elem->color[2] = b;
	elem->color[3] = a;
}
void HudElements::HudElem_SetGlow(HudElem* elem, char r, char g, char b, char a)
{
	elem->glowColor[0] = r;
	elem->glowColor[1] = g;
	elem->glowColor[2] = b;
	elem->glowColor[3] = a;
}
void HudElements::Initialize()
{
	// Remove shader precache limitation
	*(BYTE*)Addresses::ShaderPrecacheLimitation = 0xEB;
}