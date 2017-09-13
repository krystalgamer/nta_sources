#include "STDInc.h"
uint8_t *Patterns::FindPattern(const uint8_t *Pattern, const char *Mask)
{
	uint8_t *BasePtr = (uint8_t *)0x400100;
	uint8_t *EndPtr = BasePtr + 0x800000;

	return FindPattern(BasePtr, EndPtr, Pattern, Mask);
}
uint8_t *Patterns::FindPattern(uint8_t *BasePtr, uint8_t *EndPtr, const uint8_t *Pattern, const char *Mask)
{
	size_t Length = strlen(Mask);
	size_t i = 0;
	while (BasePtr < EndPtr)
	{
		for (i = 0; i < Length; i++)
		{
			if (!(Mask[i] == '?' || Mask[i] == '\x02') && Pattern[i] != BasePtr[i])
			{
				break;
			}
		}
		if (i == Length)
		{
			return BasePtr;
		}
		BasePtr++;
	}
	return nullptr;
}