#include "Teleport.hpp"
#include "Mem.hpp"
#include "offsets.hpp"
#include "config.hpp"

void teleportEntities(uintptr_t* localPlayerPtr, uintptr_t* entityList, uintptr_t moduleBase)
{
	const uintptr_t playerCount = *(uintptr_t*)(moduleBase + offsets::EntityCount);

	const float local_x_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::X_position }));
	const float local_y_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Y_position }));
	const float local_z_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Z_position }));

	std::vector<uintptr_t> entities;

	if (config::Enable::TeleportEnemies)
	{
		for (size_t i{ 1 }; i < playerCount; ++i)
		{
			WORD counter = 0x4 * i;

			if (uintptr_t entity = *(int*)mem::FindDMAAddy4Bytes((uintptr_t)entityList, { counter }))
				entities.push_back(counter);
		}

		for (const auto& entity : entities)
		{
			*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::X_position })) = local_x_position + 5.f;
			*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::Y_position })) = local_y_position;
			*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::Z_position })) = local_z_position;
		}
	}
}
