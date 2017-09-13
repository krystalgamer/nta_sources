#include "StdInc.h"

void bdMatchMakingInfo::Serialize(bdByteBuffer packet)
{

}
void bdMatchMakingInfo::Serialize(dwMessage packet)
{
	packet.byteBuffer.writeBlob(Address, strlen(Address));
	packet.byteBuffer.writeByte(SessionID);
	packet.byteBuffer.writeUInt32(Unknown1);
	packet.byteBuffer.writeUInt32(Unknown2);
	packet.byteBuffer.writeUInt32(Players);

}
void bdMatchMakingInfo::Deserialize(bdByteBuffer packet)
{
	char adrbytes[4];
	char portbytes[2];
	int size;
	packet.readBlob(&Address, &size);
	packet.readUInt32(&Unknown1);
	packet.readUInt32(&Unknown2);

	//InternalIPAddress
	adrbytes[0] = Address[0];
	adrbytes[1] = Address[1];
	adrbytes[2] = Address[2];
	adrbytes[3] = Address[3];

	portbytes[0] = Address[4];
	portbytes[1] = Address[5];

	memcpy(&InternalIPAddress, adrbytes, 4);
	memcpy(&InternalPort, adrbytes, 2);

	/*
	char ipAddressFinal[15];
	if (InternalIPAddress)
	{
	const int NBYTES = 4;
	uint8 octet[NBYTES];
	for(int i = 0 ; i < NBYTES ; i++)
	{
	octet[i] = InternalIPAddress >> (i * 8);
	}
	sprintf(ipAddressFinal, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
	}
	const char* sidc2 = (const char*)ipAddressFinal;
	MessageBox(NULL,sidc2,"InternalIP",MB_ICONINFORMATION);
	*/



	//IPAddress
	adrbytes[0] = Address[18];
	adrbytes[1] = Address[19];
	adrbytes[2] = Address[20];
	adrbytes[3] = Address[21];

	portbytes[0] = Address[22];
	portbytes[1] = Address[23];


	memcpy(&IPAddress, adrbytes, 4);
	memcpy(&Port, adrbytes, 2);

	/*
	char ipAddressFinal2[15];
	if (IPAddress)
	{
	const int NBYTES = 4;
	uint8 octet[NBYTES];
	for(int i = 0 ; i < NBYTES ; i++)
	{
	octet[i] = IPAddress >> (i * 8);
	}
	sprintf(ipAddressFinal2, "%d.%d.%d.%d", octet[0], octet[1], octet[2], octet[3]);
	}
	const char* sidc3 = (const char*)ipAddressFinal2;
	MessageBox(NULL,sidc3,"IPAddress",MB_ICONINFORMATION);
	*/

	if (adrbytes[0] == 0)
	{
		IPAddress = InternalIPAddress;
		Port = InternalPort;
	}
}
void bdMatchMakingInfo::Deserialize(dwMessage packet)
{
	char adrbytes[4];
	char portbytes[2];

	int size;
	packet.byteBuffer.readBlob(&Address, &size);
	packet.byteBuffer.readUInt32(&Unknown1);
	packet.byteBuffer.readUInt32(&Unknown2);

	//InternalIPAddress
	adrbytes[0] = Address[0];
	adrbytes[1] = Address[1];
	adrbytes[2] = Address[2];
	adrbytes[3] = Address[3];


	portbytes[0] = Address[4];
	portbytes[1] = Address[5];

	memcpy(&InternalIPAddress, adrbytes, 4);
	memcpy(&InternalPort, adrbytes, 2);

	//IPAddress
	adrbytes[0] = Address[18];
	adrbytes[1] = Address[19];
	adrbytes[2] = Address[20];
	adrbytes[3] = Address[21];
	portbytes[0] = Address[22];
	portbytes[1] = Address[23];

	memcpy(&IPAddress, adrbytes, 4);
	memcpy(&Port, adrbytes, 2);
	if (adrbytes[0] == 0)
	{
		IPAddress = InternalIPAddress;
		Port = InternalPort;
	}
}