#include "offsets.hpp"
#include "config.hpp"
#include "mem.hpp"

void printConfig()
{
	static bool s_bPrintConfig{ true };

	if (s_bPrintConfig)
	{
		std::cout << "Keybind END will eject this trainer\n\n\n";
		if (config::Enable::Health)
			std::cout << "Health                    [ " << std::boolalpha << config::Enable::Health << ", " << config::Value::Health << " ]\n";
		else
			std::cout << "Health                    [ " << std::boolalpha << config::Enable::Health << " ]\n";

		if (config::Enable::Armour)
			std::cout << "Armour                    [ " << std::boolalpha << config::Enable::Armour << ", " << config::Value::Armour << " ]\n";
		else
			std::cout << "Armour                    [ " << std::boolalpha << config::Enable::Armour << " ]\n";

		if (config::Enable::AssaultRifleClip)
			std::cout << "Assault Rifle Clip        [ " << std::boolalpha << config::Enable::AssaultRifleClip << ", " << config::Value::AssaultRifleClip << " ]\n";
		else
			std::cout << "Assault Rifle Clip        [ " << std::boolalpha << config::Enable::AssaultRifleClip << " ]\n";

		if (config::Enable::AssaultRifleReserve)
			std::cout << "Assault Rifle Reserve     [ " << std::boolalpha << config::Enable::AssaultRifleReserve << ", " << config::Value::AssaultRifleReserve << " ]\n";
		else
			std::cout << "Assault Rifle Reserve     [ " << std::boolalpha << config::Enable::AssaultRifleReserve << " ]\n";

		if (config::Enable::SubmachineGunClip)
			std::cout << "Submachine Gun Clip       [ " << std::boolalpha << config::Enable::SubmachineGunClip << ", " << config::Value::SubmachineGunClip << " ]\n";
		else
			std::cout << "Submachine Gun Clip       [ " << std::boolalpha << config::Enable::SubmachineGunClip << " ]\n";

		if (config::Enable::SniperRifleClip)
			std::cout << "Sniper Rifle Clip         [ " << std::boolalpha << config::Enable::SniperRifleClip << ", " << config::Value::SniperRifleClip << " ]\n";
		else
			std::cout << "Sniper Rifle Clip         [ " << std::boolalpha << config::Enable::SniperRifleClip << " ]\n";

		if (config::Enable::SniperRifleReserve)
			std::cout << "Sniper Rifle Reserve      [ " << std::boolalpha << config::Enable::SniperRifleReserve << ", " << config::Value::SniperRifleReserve << " ]\n";
		else
			std::cout << "Sniper Rifle Reserve      [ " << std::boolalpha << config::Enable::SniperRifleReserve << " ]\n";

		if (config::Enable::CombatShotgunClip)
			std::cout << "Combat Shotgun Clip       [ " << std::boolalpha << config::Enable::CombatShotgunClip << ", " << config::Value::CombatShotgunClip << " ]\n";
		else
			std::cout << "Combat Shotgun Clip       [ " << std::boolalpha << config::Enable::CombatShotgunClip << " ]\n";

		if (config::Enable::CombatShotgunReserve)
			std::cout << "Combat Shotgun Reserve    [ " << std::boolalpha << config::Enable::CombatShotgunReserve << ", " << config::Value::CombatShotgunReserve << " ]\n";
		else
			std::cout << "Combat Shotgun Reserve    [ " << std::boolalpha << config::Enable::CombatShotgunReserve << " ]\n";

		if (config::Enable::CarbineRifleClip)
			std::cout << "Carbine Rifle Clip        [ " << std::boolalpha << config::Enable::CarbineRifleClip << ", " << config::Value::CarbineRifleClip << " ]\n";
		else
			std::cout << "Carbine Rifle Clip        [ " << std::boolalpha << config::Enable::CarbineRifleClip << " ]\n";

		if (config::Enable::CarbineRifleReserve)
			std::cout << "Carbine Rifle Reserve     [ " << std::boolalpha << config::Enable::CarbineRifleReserve << ", " << config::Value::CarbineRifleReserve << " ]\n";
		else
			std::cout << "Carbine Rifle Reserve     [ " << std::boolalpha << config::Enable::CarbineRifleReserve << " ]\n";

		if (config::Enable::PistolClip)
			std::cout << "Pistol Clip               [ " << std::boolalpha << config::Enable::PistolClip << ", " << config::Value::PistolClip << " ]\n";
		else
			std::cout << "Pistol Clip               [ " << std::boolalpha << config::Enable::PistolClip << " ]\n";

		if (config::Enable::PistolReserve)
			std::cout << "Pistol Reserve            [ " << std::boolalpha << config::Enable::PistolReserve << ", " << config::Value::PistolReserve << " ]\n";
		else
			std::cout << "Pistol Reserve            [ " << std::boolalpha << config::Enable::PistolReserve << " ]\n";

		if (config::Enable::Grenade)
			std::cout << "Grenade                   [ " << std::boolalpha << config::Enable::Grenade << ", " << config::Value::Grenade << " ]\n\n";
		else
			std::cout << "Grenade                   [ " << std::boolalpha << config::Enable::Grenade << " ]\n\n";


		if (config::Enable::WeaponSound)
			std::cout << "Weapon Sound              [ " << std::boolalpha << config::Enable::WeaponSound << ", " << config::Value::WeaponSound << " ]\n";
		else
			std::cout << "Weapon Sound              [ " << std::boolalpha << config::Enable::WeaponSound << " ]\n";

		if (config::Enable::WeaponDamage)
			std::cout << "Weapon Damage             [ " << std::boolalpha << config::Enable::WeaponDamage << ", " << config::Value::WeaponDamage << " ]\n";
		else
			std::cout << "Weapon Damage             [ " << std::boolalpha << config::Enable::WeaponDamage << " ]\n";

		std::cout << "Weapon RapidfireAll       [ " << std::boolalpha << config::Enable::WeaponRapidfireAll << " ]\n";
		std::cout << "Weapon Rapidfire          [ " << std::boolalpha << config::Enable::WeaponRapidfire << " ]\n";
		std::cout << "Weapon No KickBack        [ " << std::boolalpha << config::Enable::WeaponNoKickBack << " ]\n";
		std::cout << "Weapon No Recoil          [ " << std::boolalpha << config::Enable::WeaponNoRecoil << " ]\n\n";

		std::cout << "Infinite Jump             [ " << std::boolalpha << config::Enable::InfJump << " ]\n\n";

		std::cout << "Show BulletHoles          [ " << std::boolalpha << config::Enable::showBulletHoles << " ]\n\n";

		std::cout << "Teleport Enemies          [ " << std::boolalpha << config::Enable::teleportEnemies << " ]\n";

		s_bPrintConfig = false;
	}
}

void MainHack()
{
	const uintptr_t moduleBase = (uintptr_t)GetModuleHandleA("ac_client.exe");

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
			break;

		const uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + offsets::LocalPlayerObject);
		const uintptr_t* entityList = (uintptr_t*)(moduleBase + offsets::EntityList);
		const uintptr_t playerCount = *(uintptr_t*)(moduleBase + offsets::EntityCount);

		printConfig();

		if (localPlayerPtr)
		{
			float local_x_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::X_position }));
			float local_y_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Y_position }));
			float local_z_position = *(float*)(mem::FindDMAAddy4Bytes((uintptr_t)localPlayerPtr, { offsets::Z_position }));

			if (entityList)
			{
				std::vector<uintptr_t> entities;

				for (unsigned int i{ 1 }; i < playerCount; ++i)
				{
					unsigned short counter = 0x4 * i;

					if (uintptr_t entity = *(int*)mem::FindDMAAddy4Bytes((uintptr_t)entityList, { counter }))
						entities.push_back(counter);
				}

				if (config::Enable::teleportEnemies)
				{
					for (const auto& entity : entities)
					{
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (unsigned short)entity, offsets::X_position })) = local_x_position + 5.f;
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (unsigned short)entity, offsets::Y_position })) = local_y_position;
						*(float*)(mem::FindDMAAddy4Bytes((uintptr_t)entityList, { (unsigned short)entity, offsets::Z_position })) = local_z_position;
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