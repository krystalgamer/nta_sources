#include "STDInc.h"
// Return command parameter count
int Command::Cmd_ArgC()
{
	return *(int*)Addresses::cmd_argc;
}
// Return command parameter value for the given index
char* Command::Cmd_ArgV(int index)
{
	if (index >= Cmd_ArgC())
	{
		return "";
	}
	else
	{
		return (*(char***)Addresses::cmd_argv)[index];
	}
}