#pragma once
class TitleUtils
{
public:
	static void dw_tutils_get_server_time(bdByteBuffer& data);
	static void dw_dml_get_user_data(bdByteBuffer& data);
	static void dw_messaging_send_global_im(bdByteBuffer& data);
	static void dw_handle_tutils_message(int type, const char* buf, int len);
	static char* dw_invite_data;
};