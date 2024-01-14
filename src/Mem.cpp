#include "Mem.h"

namespace mem
{
	uintptr_t FindDMAAddy(const uintptr_t ptr, const std::vector<unsigned short> offsets)
	{
		uintptr_t addr = ptr;
		for (unsigned int i{ 0 }; i < offsets.size(); ++i)
		{
			addr = *(uintptr_t*)addr;
			addr += offsets[i];
		}

		return addr;
	}
}
