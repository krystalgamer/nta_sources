class Storage
{
public:
	static void dw_storage_get_publisher_file(bdByteBuffer& data);
	static void dw_storage_get_user_file(bdByteBuffer& data);
	static void dw_storage_upload_user_file(bdByteBuffer& data);
	static void dw_handle_storage_message(int type, const char* buf, int len);
};