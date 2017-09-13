#pragma once
class dwMessage
{
private:
	bool _isBit;
	char _type;

	BYTE* _bytes;
public:
	bdBitBuffer bitBuffer;
	bdByteBuffer byteBuffer;

	dwMessage(char type, bool isBit);
	~dwMessage();

	void send(bool encrypted);
};