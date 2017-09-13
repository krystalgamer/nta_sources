#include "STDInc.h"




const char* ConsoleTitle = "Sonsored T6>";
const char* ConsoleText = "spawnbot all";

const char* InGameConsole::DebugLog = "";
std::vector<const char*> DebugLogList;
int VectorCountDebugLogList = 0;


Font_s* ConsoleFont;		// void* does same.
Font_s* NormalFont;			// void* does same.
Material* Material_White;	// void* does same.
bool ConsoleOpen = false;/*false*//*true*/



void DrawConsole()
{
	Addresses::R_AddCmdDrawText("Sonsored", 0x7FFFFFFF, NormalFont, 20.0f, 40.0f, 1.0f, 1.0f, 0, tColor{ 1.0f, 1.0f, 1.0f, 0.05f }, 0);
	if (ConsoleOpen)
	{
		tColor color = { 0.25f, 1.0f, 0.0f, 1.0f };
		tColor color2 = { 1.0f, 1.0f, 0.0f, 0.5f };
		float width = (float)*(DWORD*)Addresses::RendererWidth;
		float height = (float)*(DWORD*)Addresses::RendererHeight;

		Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, width - 60, 28.0f, 0, 0, 0, 0, &color, Material_White);



		Addresses::DrawRotatedPic(10.0f,			10.0f,		1.0f,	width - 60,		28.0f,		0,		0,		0.1f,		0.1f,	&color, Material_White);
		Addresses::DrawRotatedPic(10.0f,			10.0f,		1.0f,	1.0f,			28.0f,		0,		0,		0.6f,		0.6f,	&color2, Material_White);
		Addresses::DrawRotatedPic(width - 11.0f,	10.0f,		1.0f,	1.0f,			28.0f,		0,		0,		0.6f,		0.6f,	&color2, Material_White);
		Addresses::DrawRotatedPic(10.0f,			10.0f,		1.0f,	width - 40,			1,		0,		0,		0.6f,		0.6f,	&color2, Material_White);
		Addresses::DrawRotatedPic(10.0f,			37.0f,		1.0f,	width - 50,			1,		0,		0,		0.6f,		0.6f,	&color2, Material_White);




		//Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, RendererWidthA, 28.0f, 0, 0, 0, 0, tColor{ 0.25f, 0.25f, 0.2f, 1.0f });
		//Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, 2.0f, 28.0f, 0, 0, 0, 0, tColor{ 0.125f, 0.125f, 0.1f, 1.0f });
		//Addresses::DrawRotatedPic(RendererWidthA + 8.0f, 10.0f, 1.0f, 2.0f, 28.0f, 0, 0, 0, 0, tColor{ 0.125f, 0.125f, 0.1f, 1.0f });
		

		//Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, RendererWidthA, 28.0f, 0, 0, 0, 0, tColor{ 1, 1, 1, 1 }); // rect inside
		//Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, 1.0f, 28.0f, 0, 0, 0, 0,					tColor{ 0.6f, 0.6f, 0.6f, 1.0f }); // left
		//Addresses::DrawRotatedPic(RendererWidthA + 10.0f, 10.0f, 1.0f, 1.0f, 28.0f, 0, 0, 0, 0, tColor{ 0.6f, 0.6f, 0.6f, 1.0f }); // right
		//Addresses::DrawRotatedPic(10.0f, 10.0f, 1.0f, (float)RendererWidthA, 1.0f, 0, 0, 0, 0,	tColor{ 0.6f, 0.6f, 0.6f, 1.0f }); // top
		//Addresses::DrawRotatedPic(10.0f, 37.0f, 1.0f, (float)RendererWidthA, 1.0f, 0, 0, 0, 0,	tColor{ 0.6f, 0.6f, 0.6f, 1.0f }); // down


		float TextDrawLength = Addresses::GetTextLengthSize(0, ConsoleTitle, 10, ConsoleFont);
		Addresses::R_AddCmdDrawText(ConsoleTitle, 0x7FFFFFFF, ConsoleFont, 16.0f, 33.0f, 1.0f, 1.0f, 0, tColor{ 1.0f, 1.0f, 1.0f, 1.0f }, 0);
		Addresses::R_AddCmdDrawText(ConsoleText, 0x10000, ConsoleFont, (TextDrawLength + 22.0f), 32.0f, 1.0f, 1.0f, 0, tColor{ 1.0f, 1.0f, 1.0f, 1.0f }, 0);
	}

#ifdef _DEBUG
	for (int i = 0; i < DebugLogList.size(); i++)
	{
		Addresses::R_AddCmdDrawText(DebugLogList[i], 0x7FFFFFFF, ConsoleFont, 20.0f, 40.0f + (i * 15), 1.0f, 1.0f, 0, tColor{ 1.0f, 1.0f, 1.0f, 1.0f }, 0);
	}
#endif
}
void ExecuteKey_Stub()//44DD77
{
	//Hmm we need a key catcher
	ConsoleOpen = !ConsoleOpen;
}


void InitGameConsole()
{
	ConsoleFont = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_FONT, "fonts/720/consolefont", true, -1).font;
	NormalFont = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_FONT, "fonts/720/normalFont", true, -1).font;
	Material_White = Addresses::DB_FindXAssetHeader(XAssetType::ASSET_TYPE_MATERIAL, "white", true, -1).material;
}
void __declspec(naked) RendererFrame_Stub()
{
	DrawConsole();
	__asm jmp Addresses::RendererFrameO
}
void __declspec(naked) RendererStart_Stub()
{
	InitGameConsole();
	__asm jmp Addresses::RendererStartO
}
void InGameConsole::Log(const char* text)
{
	// + 1 for new incoming
	if (DebugLogList.size() + 1 >= 25)
	{
		DebugLogList.erase(DebugLogList.begin());
	}
	//increment count for us :D
	VectorCountDebugLogList++;

	//push it onto the vector
	DebugLogList.push_back(hString::va("%i	:	%s", VectorCountDebugLogList, text));
	DebugLog = text;
}
void InGameConsole::Initialize()
{
	QCALL(Addresses::RendererFrame, RendererFrame_Stub, QPATCH_CALL);
	QCALL(Addresses::RendererStart, RendererStart_Stub, QPATCH_JUMP);



	QCALL(Addresses::ConsoleCatcher2, ExecuteKey_Stub, QPATCH_CALL);
	QCALL(Addresses::ConsoleCatcher, ExecuteKey_Stub, QPATCH_JUMP);

	//QCALL(Addresses::DrawRotatedPic, GetParamsDrawConsole, QPATCH_JUMP);
}