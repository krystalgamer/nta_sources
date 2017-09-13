#pragma once
class InGameConsole
{
public:
	static void Initialize();
	static const char* DebugLog;
	static void Log(const char*);
};