#define __STDC_FORMAT_MACROS
#include "STDInc.h"
#include <stdio.h>


PMSID dw_match::sid;
void dw_match::register_match_session(bdByteBuffer& data)
{
	char* unknownblob1;
	int len1;
	char* unknownblob2;
	int len2;
	unsigned int unint1;
	unsigned int unint2;
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
	int a6;
	int a7;
	int a8;
	int a9;
	int a10;
	int a11;
	int a12;
	float float1;
	PMID unk64;
	data.readBlob(&unknownblob1, &len1);
	data.readUInt32(&unint1);
	data.readUInt32(&unint2);
	data.readUInt64(&unk64);
	data.readBlob(&unknownblob2, &len2);
	data.readInt32(&a1);
	data.readInt32(&a2);
	data.readInt32(&a3);
	data.readInt32(&a4);
	data.readInt32(&a5);
	data.readInt32(&a6);
	data.readInt32(&a7);
	data.readInt32(&a8);
	data.readFloat(&float1);
	data.readInt32(&a9);
	data.readInt32(&a10);
	data.readInt32(&a11);
	data.readInt32(&a12);

	PMSessionInfo session;
	session.players = 0;
}
void dw_match::update_match_session(bdByteBuffer& data)
{

}
void dw_match::find_match_session_fromid(bdByteBuffer& data)
{

}
void dw_match::find_match_sessions(bdByteBuffer& data)
{
}
void dw_match::inviteto_match_session(bdByteBuffer& data)
{
	PMID onlineID;
	char* msg; int msglen;

	data.readUInt64(&onlineID);
	data.readBlob(&msg, &msglen);


	//NP_SendMessage(onlineID, (uint8_t*)msg, msglen);


	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(21);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeUInt32(0);
	reply.send(true);
}
void dw_match::submit_performance(bdByteBuffer& data)
{
	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(21);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeUInt32(0);
	reply.send(true);
}
void dw_match::get_performance_values(bdByteBuffer& data)
{
	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(21);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeUInt32(0);
	reply.send(true);

}
void dw_match::find_match_session_paged(bdByteBuffer& data)
{

}
void dw_match::find_match_sessions_byentityIDs(bdByteBuffer& data)
{

}
void dw_match::update_match_session_players(bdByteBuffer& data)
{

}
void dw_match::delete_match_session(bdByteBuffer& data)
{
	//MessageBox(NULL,va("delete match"),"Info",MB_ICONINFORMATION);
	if (sid != NULL)
	{
//		NP_DeleteSession(sid);
		sid = NULL;
	}

	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(1);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeUInt32(0);
	reply.send(true);
}
void dw_match::match_packet_received(int type, const char* buf, int len)
{
	bdByteBuffer data((char*)buf, len);
	char call = 0;
	data.readByte(&call);

	Log::Debug("bdMatchamking", "type %d",call);

	switch (call)
	{
	case 1:
		register_match_session(data);
		break;
	case 2:
		update_match_session(data);
		break;
	case 3:
		delete_match_session(data);
		break;
	case 4:
		find_match_session_fromid(data);
		break;
	case 5:
		find_match_sessions(data);
		break;
	case 8:
		inviteto_match_session(data);
		break;
	case 9:
		submit_performance(data);
		break;
	case 10:
		get_performance_values(data);
		break;
	case 12:
		update_match_session_players(data);
		break;
	case 13:
		find_match_session_paged(data);
		break;
	case 14:
		find_match_sessions_byentityIDs(data);
		break;
	default:

		break;
	}
	std::ofstream fp;
	fp.open(hString::va("encrypted 21 - %d", call), std::ios::out | std::ios::binary);
	fp.write((char*)buf, len);
}