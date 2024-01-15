#ifndef MEM_H
#define MEM_H

#include "pch.hpp"

namespace mem
{
	uintptr_t FindDMAAddy(const uintptr_t ptr, const std::vector<unsigned short> offsets);
}

#endif
