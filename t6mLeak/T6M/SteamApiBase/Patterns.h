#pragma once
class Patterns
{
public:
	static uint8_t *FindPattern(const uint8_t *Pattern, const char *Mask);
	static uint8_t *FindPattern(uint8_t *BasePtr, uint8_t *EndPtr, const uint8_t *Pattern, const char *Mask);
};