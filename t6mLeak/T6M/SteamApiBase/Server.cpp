#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "STDInc.h"
//#include <ws2tcpip.h>// we need this?

typedef void(__cdecl * ui_keyboard_new_t)(int Type);
ui_keyboard_new_t ui_keyboard_new = (ui_keyboard_new_t)0x475CE0;




bool Server::LoggedIn = false;
void Server::SetupLogin()
{
	if (Server::LoggedIn)
	{
		*(DWORD*)Addresses::custom_gethostbyname = (DWORD)dw_Entry::custom_gethostbyname;
		*(DWORD*)Addresses::dw_recvfrom = (DWORD)dw_Entry::dw_recvfrom;
		*(DWORD*)Addresses::dw_sendto = (DWORD)dw_Entry::dw_sendto;
		*(DWORD*)Addresses::dw_recv = (DWORD)dw_Entry::dw_recv;
		*(DWORD*)Addresses::dw_send = (DWORD)dw_Entry::dw_send;
		*(DWORD*)Addresses::dw_connect = (DWORD)dw_Entry::dw_connect;
		*(DWORD*)Addresses::dw_select = (DWORD)dw_Entry::dw_select;

		InitializeCriticalSection(&dw_Handler::incomingCS);
		InitializeCriticalSection(&dw_Handler::packetCS);

		CreateThread(0, 0, dw_Handler::dw_thread, 0, 0, 0);
		xNP_RegisterMessageCallback(dw_Handler::dw_im_received);

		((void(*)(int))0x45CA30)(0);
	}
	else
	{
		//Server::LoggedIn = true;
		Addresses::Cbuf_AddText(0, "ui_keyboard_new 2");
		//ui_keyboard_new(2);
	}

	//MENU_EMAIL_KEYBOARD_TITLE_CAPS
	//MENU_CUSTOMCLASS_KEYBOARD
	//MENU_CLASS_SET_KEYBOARD
	//MENU_ENTER_TEAM_NAME
	//MENU_TWITCH_USERNAME
	//MENU_TWITCH_PASSWORD
	//MENU_TWITTER_USERNAME
	//MENU_TWITTER_PASSWORD


	//Login system? -> ui_keyboard_new 
}
__declspec(naked) void Server::ConnectingHook_Stub()
{
	__asm
	{
		push    0
		call	Server::SetupLogin
		add     esp, 0x0C
		retn
	}
}
void Server::Initialize()
{
	//QCALL(0x7E6F54, Server::ConnectingHook_Stub, QPATCH_JUMP);


	*(DWORD*)Addresses::custom_gethostbyname = (DWORD)dw_Entry::custom_gethostbyname;
	*(DWORD*)Addresses::dw_recvfrom = (DWORD)dw_Entry::dw_recvfrom;
	*(DWORD*)Addresses::dw_sendto = (DWORD)dw_Entry::dw_sendto;
	*(DWORD*)Addresses::dw_recv = (DWORD)dw_Entry::dw_recv;
	*(DWORD*)Addresses::dw_send = (DWORD)dw_Entry::dw_send;
	*(DWORD*)Addresses::dw_connect = (DWORD)dw_Entry::dw_connect;
	*(DWORD*)Addresses::dw_select = (DWORD)dw_Entry::dw_select;

	InitializeCriticalSection(&dw_Handler::incomingCS);
	InitializeCriticalSection(&dw_Handler::packetCS);

	CreateThread(0, 0, dw_Handler::dw_thread, 0, 0, 0);
	xNP_RegisterMessageCallback(dw_Handler::dw_im_received);
}