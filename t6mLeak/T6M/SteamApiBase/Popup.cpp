#include "STDInc.h"
void PopupNotify::Notify_f()
{
	if (Command::Cmd_ArgC() != 6)
	{
		Notify(0, "menu_lobby_icon_blackops", "Too few parameters!", "", 10000);
	}
	else
	{
		Notify((int)Command::Cmd_ArgV(1), (const char*)Command::Cmd_ArgV(2), (const char*)Command::Cmd_ArgV(3), (const char*)Command::Cmd_ArgV(4), (int)Command::Cmd_ArgV(5));
	}
}
void PopupNotify::Notify(int a1, const char* a2, const char* a3, const char* a4, int a5)
{
	Addresses::NotifyClient(a1, a2, a3, a4, a5);
}
void PopupNotify::ClearPopup()
{
	Addresses::NotifyClient(0, "menu_mp_lobby_none_selected", 0, 0, 0);
}