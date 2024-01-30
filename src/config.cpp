#include "config.hpp"
#include "mem.hpp"
#include "offsets.hpp"
#include "Teleport.hpp"
#include "Aimbot.hpp"

namespace config
{
	void PrintSettings()
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

			//std::cout << "Weapon RapidfireAll       [ " << std::boolalpha << config::Enable::WeaponRapidfireAll << " ]\n";
			std::cout << "Weapon Rapidfire          [ " << std::boolalpha << config::Enable::WeaponRapidfire << " ]\n";
			std::cout << "Weapon No KickBack        [ " << std::boolalpha << config::Enable::WeaponNoKickBack << " ]\n";
			std::cout << "Weapon No Recoil          [ " << std::boolalpha << config::Enable::WeaponNoRecoil << " ]\n\n";

			std::cout << "Teleport Enemies          [ " << std::boolalpha << config::Enable::TeleportEnemies << " ]\n";
			std::cout << "Aimbot                    [ " << std::boolalpha << config::Enable::Aimbot << ", " << config::Value::aimbotFov << "f, " << config::Value::aimbotSmoothness << "f ]\n";

			s_bPrintConfig = false;
		}
	}

	void apply(const uintptr_t* localPlayerPtr, const DWORD offset, const int value, const bool enableFlag)
	{
		if (enableFlag)
			*(int*)(*localPlayerPtr + offset) = value;
	}

	void applyWeapon(uintptr_t* localPlayerPtr, const std::vector<WORD>& offset, int value, const bool enableFlag)
	{
		if (enableFlag)
			*(int*)mem::FindDMAAddy2Bytes((uintptr_t)localPlayerPtr, { offset }) = value;
	}

	void init(uintptr_t* localPlayerPtr)
	{
		constexpr bool enableFlags[] = {
				config::Enable::Health,
				config::Enable::Armour,
				config::Enable::AssaultRifleClip,
				config::Enable::AssaultRifleReserve,
				config::Enable::SubmachineGunClip,
				config::Enable::SubmachineGunReserve,
				config::Enable::SniperRifleClip,
				config::Enable::SniperRifleReserve,
				config::Enable::CombatShotgunClip,
				config::Enable::CombatShotgunReserve,
				config::Enable::CarbineRifleClip,
				config::Enable::CarbineRifleReserve,
				config::Enable::PistolClip,
				config::Enable::PistolReserve,
				config::Enable::Grenade
		};

		constexpr DWORD offsetArray4Bytes[] = {
			offsets::Health,
			offsets::Armour,
			offsets::AssaultRifleClip,
			offsets::AssaultRifleReserve,
			offsets::SubmachineGunClip,
			offsets::SubmachineGunReserve,
			offsets::SniperRifleClip,
			offsets::SniperRifleReserve,
			offsets::CombatShotgunClip,
			offsets::CombatShotgunReserve,
			offsets::CarbineRifleClip,
			offsets::CarbineRifleReserve,
			offsets::PistolClip,
			offsets::PistolReserve,
			offsets::Grenade,
		};

		constexpr int valueArray4Bytes[] = {
			config::Value::Health,
			config::Value::Armour,
			config::Value::AssaultRifleClip,
			config::Value::AssaultRifleReserve,
			config::Value::SubmachineGunClip,
			config::Value::SubmachineGunReserve,
			config::Value::SniperRifleClip,
			config::Value::SniperRifleReserve,
			config::Value::CombatShotgunClip,
			config::Value::CombatShotgunReserve,
			config::Value::CarbineRifleClip,
			config::Value::CarbineRifleReserve,
			config::Value::PistolClip,
			config::Value::PistolReserve,
			config::Value::Grenade,
		};

		constexpr size_t size{ std::size(enableFlags) };
		for (size_t i{ 0 }; i < size; ++i)
			config::apply(localPlayerPtr, offsetArray4Bytes[i], valueArray4Bytes[i], enableFlags[i]);

		config::applyWeapon(localPlayerPtr, offsets::WeaponSound, config::Value::WeaponSound, config::Enable::WeaponSound);
		config::applyWeapon(localPlayerPtr, offsets::WeaponDamage, config::Value::WeaponDamage, config::Enable::WeaponDamage);
		config::applyWeapon(localPlayerPtr, offsets::WeaponRapidfire, 0, config::Enable::WeaponRapidfire);
		config::applyWeapon(localPlayerPtr, offsets::WeaponNoKickBack, 0, config::Enable::WeaponNoKickBack);
		config::applyWeapon(localPlayerPtr, offsets::WeaponNoRecoil, 0, config::Enable::WeaponNoRecoil);
	}

	void initFeatures(uintptr_t* localPlayerPtr, uintptr_t* entityList, uintptr_t moduleBase)
	{
		if (config::Enable::TeleportEnemies)
			teleportEntities(localPlayerPtr, entityList, moduleBase);

		if (config::Enable::Aimbot)
			Aimbot(moduleBase);
	}
}
