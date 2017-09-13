#pragma once
class FileSystem
{
public:
	static bool ReadFile(const char *Filename, void *DataBuffer, uint32_t &BufferLength);
	static bool FileSystem::ReadFile(const char* Filename, void* DataBuffer);
	static int64_t GetFileSize(const char *Filename);
	static bool FileExists(const char *Filename);
	static bool ListFiles(std::string Path, std::vector<std::string>& Results, const char *Extension = nullptr);
};
class FileIO
{
public:
	static void WriteFile(std::string Filename, std::string Buffer, bool Append = false);
	static void WriteFile(std::string Filename, std::basic_string<uint8_t> Buffer, bool Append = false);
	static void WriteFile(std::string Filename, const void *Data, uint32_t Length, bool Append = false);
	static void WriteFile(const char *Filename, const void *Data, uint32_t Length, bool Append = false);

	static bool ListFiles(std::string Path, const char *Extension, std::vector<std::string> &Results);
	static const char *GetCurrentDir();

	static uint32_t GetFileSize(std::string Path);
	static bool ReadFileIntoBuffer(std::string Path, std::basic_string<uint8_t> &Buffer);

	static void DeleteFile(std::string Path);
	static bool FileExists(std::string Path);

	static void CreateDir(std::string Path, bool isFile = false);
};