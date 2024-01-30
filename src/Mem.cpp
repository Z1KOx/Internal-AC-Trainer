#include "Mem.hpp"

namespace mem
{
	uintptr_t FindDMAAddy2Bytes(const uintptr_t ptr, const std::vector<WORD>& offsets)
	{
		uintptr_t addr = ptr;
		for (unsigned int i{ 0 }; i < offsets.size(); ++i)
		{
			addr = *(uintptr_t*)addr;
			addr += offsets[i];
		}

		return addr;
	}

	uintptr_t FindDMAAddy4Bytes(const uintptr_t ptr, const std::vector<DWORD>& offsets)
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
