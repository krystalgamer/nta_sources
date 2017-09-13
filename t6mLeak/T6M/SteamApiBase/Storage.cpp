#include "STDInc.h"
#include <fstream>
void Storage::dw_storage_get_publisher_file(bdByteBuffer& data)
{
	char Filename[512];
	data.readString(Filename, sizeof(Filename));

	static uint8_t fileBuffer[131072];

	Log::Debug("dwstorage", "fetching publisher file %s", Filename);

	if (strstr(Filename, "ffotd_tu13_mp"))
	{
		strcpy(Filename, "ffotd_tu13_mp");
	}
	else if (strstr(Filename, "online_tu13_mp"))
	{
		strcpy(Filename, "online_tu13_mp.wad");
	}
	else if (strstr(Filename, "ffotd_tu13_zm"))
	{
		strcpy(Filename, "ffotd_tu13_zm");
	}
	else if (strstr(Filename, "online_tu13_zm"))
	{
		strcpy(Filename, "online_tu13_zm.wad");
	}


	PMAsync<PMGetPublisherFileResult>* async = xNP_GetPublisherFile(Filename, fileBuffer, sizeof(fileBuffer));
	PMGetPublisherFileResult* result = async->Wait();


	Log::Debug("dwstorage", "result %d, size %d", result->result, result->fileSize);

	if (result->result == GetFileResultOK)
	{
		dwMessage reply(1, false);
		reply.byteBuffer.writeUInt64(0x8000000000000001);
		reply.byteBuffer.writeUInt32(0);
		reply.byteBuffer.writeByte(7);
		reply.byteBuffer.writeUInt32(1);
		reply.byteBuffer.writeUInt32(1);
		reply.byteBuffer.writeBlob((char*)result->buffer, result->fileSize);
		reply.send(true);
		//write_to_file(filename,result->buffer,result->fileSize);
	}
	else
	{
		dwMessage reply(1, false);
		reply.byteBuffer.writeUInt64(0x8000000000000001);
		reply.byteBuffer.writeUInt32(0x3E8);
		reply.send(true);
	}
	Log::Debug("bdstorage","Done.");
}
void Storage::dw_storage_get_user_file(bdByteBuffer& data)
{
	char filename[512];
	data.readString(filename, sizeof(filename));

	static uint8_t fileBuffer[131072];

	Log::Debug("dwstorage", "fetching user file %s", filename);

	xNPID myxNPID;
	xNP_GetxNPID(&myxNPID);

	PMAsync<PMGetUserFileResult>* async = xNP_GetUserFile(filename, myxNPID, fileBuffer, sizeof(fileBuffer));
	PMGetUserFileResult* result = async->Wait();

	Log::Debug("dwstorage", "result %d, size %d", result->result, result->fileSize);

	if (result->result == GetFileResultOK)
	{
		dwMessage reply(1, false);
		reply.byteBuffer.writeUInt64(0x8000000000000001);
		reply.byteBuffer.writeUInt32(0);
		reply.byteBuffer.writeByte(7);
		reply.byteBuffer.writeUInt32(1);
		reply.byteBuffer.writeUInt32(1);
		reply.byteBuffer.writeBlob((char*)result->buffer, result->fileSize);
		reply.send(true);
		//write_to_file(filename,result->buffer,result->fileSize);
	}
	else if (result->result == GetFileResultNotFound)
	{
		dwMessage reply(1, false);
		reply.byteBuffer.writeUInt64(0x8000000000000001);
		reply.byteBuffer.writeUInt32(0x3E8);
		reply.send(true);
	}
	else
	{
		dwMessage reply(1, false);
		reply.byteBuffer.writeUInt64(0x8000000000000001);
		reply.byteBuffer.writeUInt32(2);
		reply.send(true);
	}
}
void Storage::dw_storage_upload_user_file(bdByteBuffer& data)
{
	char filename[512];
	bool stuff; char* filedata; int filelen;
	data.readString(filename, sizeof(filename));
	data.readBoolean(&stuff);
	data.readBlob(&filedata, &filelen);

	Log::Debug("dwstorage", "writing user file %s", filename);

	xNPID myxNPID;
	xNP_GetxNPID(&myxNPID);

	PMAsync<PMWriteUserFileResult>* async = xNP_WriteUserFile(filename, myxNPID, (uint8_t*)filedata, filelen);

	dwMessage reply(1, false);
	reply.byteBuffer.writeUInt64(0x8000000000000001);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeByte(1);
	reply.byteBuffer.writeUInt32(0);
	reply.byteBuffer.writeUInt32(0);
	reply.send(true);
}
void Storage::dw_handle_storage_message(int type, const char* buf, int len)
{
	bdByteBuffer data((char*)buf, len);
	char subtype = 0;
	data.readByte(&subtype);

	Log::Debug("dwstorage", "call %i", subtype);
	switch (subtype)
	{
	case 1:
		dw_storage_upload_user_file(data);
		break;
	case 3:
		dw_storage_get_user_file(data);
		break;
	case 7:
		dw_storage_get_publisher_file(data);
		break;
	default:
		Log::Debug("dwstorage", "call %i", subtype);
		break;
	}
}