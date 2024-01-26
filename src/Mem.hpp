#ifndef MEM_HPP
#define MEM_HPP

#include "pch.hpp"

namespace mem
{
	uintptr_t FindDMAAddy2Bytes(const uintptr_t ptr, const std::vector<WORD> offsets);
	uintptr_t FindDMAAddy4Bytes(const uintptr_t ptr, const std::vector<DWORD> offsets);
}

#endif
