#pragma once
using ShortString = std::basic_string<uint16_t>;
using LongString = std::basic_string<uint32_t>;
class hString
{
public:
	static const char *va(const char *fmt, ...);
	static std::vector<char *> Explode(char *Input, const char *Separator);
	static const char *Implode(std::vector<char *> &Input, const char *Separator);
	static const char *Base64Encode(char *String);
	static const char *Base64Decode(char *String);
	static std::string ToReadableString(std::basic_string<uint8_t> &Input, const char *Token = "");
	static const char *ToReadableString(uint8_t *Input, uint32_t Length, const char *Token = "");
};
