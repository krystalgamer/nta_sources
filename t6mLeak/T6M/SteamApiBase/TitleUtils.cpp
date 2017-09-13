#include "STDInc.h"
void TitleUtils::dw_tutils_get_server_time(bdByteBuffer& data)
{
	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(6);
	reply.byteBuffer.writeUInt32(1);
	reply.byteBuffer.writeUInt32(1);
	reply.byteBuffer.writeUInt32(time(NULL));
	reply.send(true);
}
void TitleUtils::dw_dml_get_user_data(bdByteBuffer& data)
{
	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(8);
	reply.byteBuffer.writeUInt32(1);
	reply.byteBuffer.writeUInt32(1);

	reply.byteBuffer.writeString("US");
	reply.byteBuffer.writeString("'murrica");
	reply.byteBuffer.writeString("California");
	reply.byteBuffer.writeString("Los Angeles");
	reply.byteBuffer.writeFloat(0.00f);
	reply.byteBuffer.writeFloat(0.00f);

	reply.send(true);
}
void TitleUtils::dw_messaging_send_global_im(bdByteBuffer& data)
{
	xNPID onlineID;
	char* msg; int msglen;
	data.readBlob(&msg, &msglen);
	data.readUInt64(&onlineID);
	xNP_SendMessage(onlineID, (uint8_t*)msg, msglen);
	Log::Debug("dwtitleutils", "sent instant message to %llx", onlineID);
}
void TitleUtils::dw_handle_tutils_message(int type, const char* buf, int len)
{
	bdByteBuffer data((char*)buf, len);
	char subtype = 0;
	data.readByte(&subtype);

	// bdTitleUtilities
	if (type == 12)
	{
		switch (subtype)
		{
		case 6:
			TitleUtils::dw_tutils_get_server_time(data);
			break;
		default:
			Log::Debug("dwtitleutils", "call %i", subtype);
			break;
		}
	}
	// bdDML
	else if (type == 27)
	{
		switch (subtype)
		{
		case 2:
			TitleUtils::dw_dml_get_user_data(data);
			break;
		}
	}
	// bdMessaging
	else if (type == 6)
	{
		switch (subtype)
		{
		case 18:
			TitleUtils::dw_messaging_send_global_im(data);
			break;
		}
	}
}