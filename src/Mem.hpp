#ifndef MEM_HPP
#define MEM_HPP

#include "pch.hpp"

namespace mem
{
	uintptr_t FindDMAAddy(const uintptr_t ptr, const std::vector<WORD> offsets);
}

#endif
