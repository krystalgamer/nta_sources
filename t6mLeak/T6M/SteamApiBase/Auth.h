#pragma once
class dw_Auth
{
public:
	static void dw_handle_auth_message_server(const char* buf, int len);
	static void dw_handle_auth_message_steam(const char* buf, int len);
	static void dw_handle_auth_message_register_server(const char* buf, int len);
	static void dw_handle_auth_message(int type, const char* buf, int len);
	static void dw_handle_lobby_message(int type, const char* buf, int len);
};