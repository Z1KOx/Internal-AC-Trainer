#ifndef MEM_H
#define MEM_H

#include "pch.h"

namespace mem
{
	uintptr_t FindDMAAddy(const uintptr_t ptr, const std::vector<unsigned short> offsets);
}

#endif