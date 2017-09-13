#include "STDInc.h"
void Auth_Error(const char* message)
{
	static wchar_t buf[32768];
	MultiByteToWideChar(CP_UTF8, 0, message, -1, buf, sizeof(buf));
	MessageBoxW(NULL, buf, L"Error!", MB_OK | MB_ICONSTOP);
}
DWORD __stdcall ConsoleWindow(LPVOID lpThreadParameter)
{
	struct tagMSG Msg;
	Sleep(500);
	((void(*)(void))lpThreadParameter)();
	while (GetMessageA(&Msg, 0, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	return 0;
}
void ProcessSignature(const char* Sig, char* mask, int size, int logoffset, const char* Replace, int ReplaceOffset, int ReplaceSize)
{
	signature_t* signature = new signature_t;
	signature->signature = (unsigned char*)Sig;
	signature->mask = mask;
	signature->size = size;
	signature->logOffset = logoffset;
	signature->replace = (unsigned char*)Replace;
	signature->replaceOffset = ReplaceOffset;
	signature->replaceSize = ReplaceSize;
	ProcessSignature2(0, signature);
}
void ProcessSignature2(int id, signature_t* signature)
{
	unsigned char *pBasePtr = (unsigned char *)0x400000;
	unsigned char *pEndPtr = pBasePtr + 0x800000;//GetImageLength() - 0xF000;
	size_t i;
	int occurred = 0;

	while (pBasePtr < pEndPtr) {
		for (i = 0; i < signature->size; i++) {
			if ((signature->mask[i] != '?') && (signature->signature[i] != pBasePtr[i]))
				break;
		}

		if (i == signature->size)
		{
			//Log::Debug("", "Address Found %d : 0x%x", id, pBasePtr + signature->replaceOffset);
			if (signature->replaceCB)
			{
				signature->replaceCB(pBasePtr + signature->replaceOffset);
			}
			if (signature->replace)
			{
				// patch output
				memcpy(pBasePtr + signature->replaceOffset, signature->replace, signature->replaceSize);
			}
		}
		pBasePtr++;
	}
}