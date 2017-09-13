#include "STDInc.h"

bdByteBuffer::bdByteBuffer(char* bytes, int length)
{
	bdByteBuffer::init(bytes, length);
}
void bdByteBuffer::init(char* bytes, int length)
{
	_bytes = (BYTE*)bytes;
	_curByte = 0;
	_maxByte = length;
	_dataTypePacking = false;
	_lastDataType = 0;
}
bool bdByteBuffer::write(int bytes, const void* data)
{
	if ((bytes + _curByte) > _maxByte)
	{
		return false;
	}

	memcpy(_bytes + _curByte, data, bytes);
	_curByte += bytes;
	return true;
}
bool bdByteBuffer::read(int bytes, void* output)
{
	if ((bytes + _curByte) > _maxByte)
	{
		return false;
	}
	memcpy(output, _bytes + _curByte, bytes);
	_curByte += bytes;
	return true;
}
bool bdByteBuffer::readDataType(char expected)
{
	if (_dataTypePacking && expected == _lastDataType)
	{
		return true;
	}
	char type;
	bdByteBuffer::read(1, &type);
	if (type != expected)
	{
		Log::Debug("bdByteBuffer", "invalid data type (got %d, expected %d)", type, expected);
		return false;
	}
	_lastDataType = type;
	return true;
}
bool bdByteBuffer::readBlob(char** output, int* length)
{
	bdByteBuffer::readDataType(0x13);
	unsigned int size;
	bdByteBuffer::readUInt32(&size);
	*output = (char*)&_bytes[_curByte];
	*length = size;
	_curByte += size;
	return true;
}
bool bdByteBuffer::readBoolean(bool* output)
{
	bdByteBuffer::readDataType(1);
	return bdByteBuffer::read(1, output);
}
bool bdByteBuffer::readFloat(float* output)
{
	bdByteBuffer::readDataType(13);
	return bdByteBuffer::read(4, output);
}
bool bdByteBuffer::readInt32(int* output)
{
	bdByteBuffer::readDataType(7);
	return bdByteBuffer::read(4, output);
}
bool bdByteBuffer::readUInt32(unsigned int* output)
{
	bdByteBuffer::readDataType(8);
	return bdByteBuffer::read(4, output);
}
bool bdByteBuffer::readInt64(__int64* output)
{
	bdByteBuffer::readDataType(9);
	return bdByteBuffer::read(8, output);
}
bool bdByteBuffer::readUInt64(unsigned __int64* output)
{
	bdByteBuffer::readDataType(10);
	return bdByteBuffer::read(8, output);
}
bool bdByteBuffer::readByte(char* output)
{
	bdByteBuffer::readDataType(3);
	return bdByteBuffer::read(1, output);
}
bool bdByteBuffer::readString(char** output)
{
	bdByteBuffer::readDataType(16);
	*output = (char*)&_bytes[_curByte];
	_curByte += strlen(*output) + 1;
	return true;
}
bool bdByteBuffer::readString(char* output, int length)
{
	bdByteBuffer::readDataType(16);

	char* string = (char*)&_bytes[_curByte];
	strcpy_s(output, length, string);

	_curByte += strlen(string) + 1;
	return true;
}
bool bdByteBuffer::writeBlob(const char* data, int length)
{
	bdByteBuffer::writeDataType(0x13);
	bdByteBuffer::writeUInt32(length);
	return write(length, data);
}
bool bdByteBuffer::writeByte(char data)
{
	bdByteBuffer::writeDataType(3);
	return write(1, &data);
}
bool bdByteBuffer::writeInt32(int data)
{
	bdByteBuffer::writeDataType(7);
	return write(4, &data);
}
bool bdByteBuffer::writeUInt32(unsigned int data)
{
	bdByteBuffer::writeDataType(8);
	return write(4, &data);
}
bool bdByteBuffer::writeInt64(__int64 data)
{
	bdByteBuffer::writeDataType(9);
	return write(8, &data);
}
bool bdByteBuffer::writeUInt64(unsigned __int64 data)
{
	bdByteBuffer::writeDataType(10);
	return write(8, &data);
}
bool bdByteBuffer::writeString(const char* data)
{
	bdByteBuffer::writeDataType(16);
	return write(strlen(data) + 1, data);
}
bool bdByteBuffer::writeFloat(float data)
{
	bdByteBuffer::writeDataType(13);
	return write(4, &data);
}
bool bdByteBuffer::writeDataType(char data)
{
	return write(1, &data);
}
int bdByteBuffer::getLength()
{
	return (_curByte);
}
char bdByteBuffer::peekbyte()
{
	return _bytes[_curByte];
}