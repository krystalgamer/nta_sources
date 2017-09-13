#pragma once
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")
class DumpHandler // Would a namespace be better here?
{
public:
	static void Initialize();
private:
	

	static LONG WINAPI CustomUnhandledExceptionFilter(LPEXCEPTION_POINTERS ExceptionInfo);
	static LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter_Stub(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
	static DWORD WINAPI SafeTimeGetTime();
};
