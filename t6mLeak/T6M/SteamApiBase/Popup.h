#pragma once
class PopupNotify
{
public:
	static void Notify_f();
	static void Notify(int a1, const char* a2, const char* a3, const char* a4, int a5);
	static void ClearPopup();
};