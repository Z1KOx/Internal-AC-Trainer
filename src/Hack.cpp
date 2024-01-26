#include "offsets.hpp"
#include "config.hpp"
#include "mem.hpp"

void MainHack()
{
	const uintptr_t moduleBase = (uintptr_t)GetModuleHandleA("ac_client.exe");

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
			break;

		config::PrintSettings();

		const uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + offsets::LocalPlayerObject);
		const uintptr_t* entityList = (uintptr_t*)(moduleBase + offsets::EntityList);
		const uintptr_t playerCount = *(uintptr_t*)(moduleBase + offsets::EntityCount);

		if (localPlayerPtr)
		{
			float local_x_position = *(FLOAT*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::X_position }));
			float local_y_position = *(FLOAT*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Y_position }));
			float local_z_position = *(FLOAT*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Z_position }));


			if (entityList)
			{
				std::vector<uintptr_t> entities;

				for (DWORD i{ 1 }; i < playerCount; ++i)
				{
					WORD counter = 0x4 * i;

					if (uintptr_t entity = *(int*)mem::FindDMAAddy4Bytes((uintptr_t)entityList, { counter }))
						entities.push_back(counter);
				}

				if (config::Enable::teleportEnemies)
				{
					for (const auto& entity : entities)
					{
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::X_position })) = local_x_position + 5.f;
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::Y_position })) = local_y_position;
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (WORD)entity, offsets::Z_position })) = local_z_position;
					}
				}
			}

			if (config::Enable::Health)
				*(int*)(*localPlayerPtr + offsets::Health) = config::Value::Health;
			if (config::Enable::Armour)
				*(int*)(*localPlayerPtr + offsets::Armour) = config::Value::Armour;

			if (config::Enable::AssaultRifleClip)
				*(int*)(*localPlayerPtr + offsets::AssaultRifleClip) = config::Value::AssaultRifleClip;
			if (config::Enable::AssaultRifleReserve)
				*(int*)(*localPlayerPtr + offsets::AssaultRifleReserve) = config::Value::AssaultRifleReserve;

			if (config::Enable::SubmachineGunClip)
				*(int*)(*localPlayerPtr + offsets::SubmachineGunClip) = config::Value::SubmachineGunClip;
			if (config::Enable::SubmachineGunReserve)
				*(int*)(*localPlayerPtr + offsets::SubmachineGunReserve) = config::Value::SubmachineGunReserve;

			if (config::Enable::SniperRifleClip)
				*(int*)(*localPlayerPtr + offsets::SniperRifleClip) = config::Value::SniperRifleClip;
			if (config::Enable::SniperRifleReserve)
				*(int*)(*localPlayerPtr + offsets::SniperRifleReserve) = config::Value::SniperRifleReserve;

			if (config::Enable::CombatShotgunClip)
				*(int*)(*localPlayerPtr + offsets::CombatShotgunClip) = config::Value::CombatShotgunClip;
			if (config::Enable::CombatShotgunReserve)
				*(int*)(*localPlayerPtr + offsets::CombatShotgunReserve) = config::Value::CombatShotgunReserve;

			if (config::Enable::CarbineRifleClip)
				*(int*)(*localPlayerPtr + offsets::CarbineRifleClip) = config::Value::CarbineRifleClip;
			if (config::Enable::CarbineRifleReserve)
				*(int*)(*localPlayerPtr + offsets::CarbineRifleReserve) = config::Value::CarbineRifleReserve;

			if (config::Enable::PistolClip)
				*(int*)(*localPlayerPtr + offsets::PistolClip) = config::Value::PistolClip;
			if (config::Enable::PistolReserve)
				*(int*)(*localPlayerPtr + offsets::PistolReserve) = config::Value::PistolReserve;

			if (config::Enable::Grenade)
				*(int*)(*localPlayerPtr + offsets::Grenade) = config::Value::Grenade;

			
			if (config::Enable::WeaponSound)
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponSound }) = config::Value::WeaponSound;
			
			if (config::Enable::WeaponRapidfireAll)
			{
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponRapidfire }) = 0;
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponIsAuto }) = 1;
			}
			if (config::Enable::WeaponRapidfire)
			{
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponRapidfire }) = 0;
			}

			if (config::Enable::WeaponDamage)
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponDamage }) = config::Value::WeaponDamage;
			if (config::Enable::WeaponNoKickBack)
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponKickBack }) = 0;
			if (config::Enable::WeaponNoRecoil)
				*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offsets::WeaponRecoil }) = 0;

			if (config::Enable::InfJump)
				*(int*)(*localPlayerPtr + offsets::Infjump) = 1;

			if (config::Enable::showBulletHoles)
				*(int*)(moduleBase + offsets::BulletHole) = 0;

			if (config::Enable::noSway)
				*(int*)(moduleBase + offsets::NoSway) = 1;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
}