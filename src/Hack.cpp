#include "offsets.h"
#include "config.h"
#include "mem.h"

void MainHack()
{
	const uintptr_t moduleBase = (uintptr_t)GetModuleHandleA("ac_client.exe");
	static bool bPrintConfig{ true };

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
			break;

		const uintptr_t* localPlayer = (uintptr_t*)(moduleBase + offsets::LocalPlayerObject);

		if (bPrintConfig)
		{
			if (config::Enable::Health)
				std::cout << "Health            [ " << std::boolalpha << config::Enable::Health << ", " << config::Value::Health << " ]\n";
			else
				std::cout << "Health            [ " << std::boolalpha << config::Enable::Health << " ]\n";

			if (config::Enable::Armour)
				std::cout << "Armour            [ " << std::boolalpha << config::Enable::Armour << ", " << config::Value::Armour << " ]\n";
			else
				std::cout << "Armour            [ " << std::boolalpha << config::Enable::Armour << " ]\n";

			if (config::Enable::RifleClip)
				std::cout << "Rifle Clip        [ " << std::boolalpha << config::Enable::RifleClip << ", " << config::Value::RifleClip << " ]\n";
			else
				std::cout << "Rifle Clip        [ " << std::boolalpha << config::Enable::RifleClip << " ]\n";

			if (config::Enable::RifleReserve)
				std::cout << "Rifle Reserve     [ " << std::boolalpha << config::Enable::RifleReserve << ", " << config::Value::RifleReserve << " ]\n";
			else
				std::cout << "Rifle Reserve     [ " << std::boolalpha << config::Enable::RifleReserve << " ]\n";

			if (config::Enable::PistolClip)
				std::cout << "Pistol Clip       [ " << std::boolalpha << config::Enable::PistolClip << ", " << config::Value::PistolClip << " ]\n";
			else
				std::cout << "Pistol Clip       [ " << std::boolalpha << config::Enable::PistolClip << " ]\n";

			if (config::Enable::PistolReserve)
				std::cout << "Pistol Reserve    [ " << std::boolalpha << config::Enable::PistolReserve << ", " << config::Value::PistolReserve << " ]\n";
			else
				std::cout << "Pistol Reserve    [ " << std::boolalpha << config::Enable::PistolReserve << " ]\n";

			if (config::Enable::Grenade)
				std::cout << "Grenade           [ " << std::boolalpha << config::Enable::Grenade << ", " << config::Value::Grenade << " ]\n\n";
			else
				std::cout << "Grenade           [ " << std::boolalpha << config::Enable::Grenade << " ]\n\n";


			if (config::Enable::WeaponSound)
				std::cout << "Weapon Sound      [ " << std::boolalpha << config::Enable::WeaponSound << ", " << config::Value::WeaponSound << " ]\n";
			else
				std::cout << "Weapon Sound      [ " << std::boolalpha << config::Enable::WeaponSound << " ]\n";

			if (config::Enable::WeaponDamage)
				std::cout << "Weapon Damage     [ " << std::boolalpha << config::Enable::WeaponDamage << ", " << config::Value::WeaponDamage << " ]\n";
			else
				std::cout << "Weapon Damage     [ " << std::boolalpha << config::Enable::WeaponDamage << " ]\n";

			std::cout << "Weapon Rapidfire  [ " << std::boolalpha << config::Enable::WeaponRapidfire << " ]\n";
			std::cout << "Weapon KickBack   [ " << std::boolalpha << config::Enable::WeaponKickBack << " ]\n";
			std::cout << "Weapon Recoil     [ " << std::boolalpha << config::Enable::WeaponRecoil << " ]\n";

			bPrintConfig = false;
		}

		if (localPlayer)
		{
			if (config::Enable::Health)
				*(int*)(*localPlayer + offsets::Health) = config::Value::Health;
			if (config::Enable::Armour)
				*(int*)(*localPlayer + offsets::Armour) = config::Value::Armour;
			if (config::Enable::RifleClip)
				*(int*)(*localPlayer + offsets::RifleClip) = config::Value::RifleClip;
			if (config::Enable::RifleReserve)
				*(int*)(*localPlayer + offsets::RifleReserve) = config::Value::RifleReserve;
			if (config::Enable::PistolClip)
				*(int*)(*localPlayer + offsets::PistolClip) = config::Value::PistolClip;
			if (config::Enable::PistolReserve)
				*(int*)(*localPlayer + offsets::PistolReserve) = config::Value::PistolReserve;
			if (config::Enable::Grenade)
				*(int*)(*localPlayer + offsets::Grenade) = config::Value::Grenade;

			if (config::Enable::WeaponSound)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponSound }) = config::Value::WeaponSound;
			if (config::Enable::WeaponRapidfire)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponRapidfire }) = 0;
			if (config::Enable::WeaponDamage)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponDamage }) = config::Value::WeaponDamage;
			if (config::Enable::WeaponKickBack)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponKickBack }) = 0;
			if (config::Enable::WeaponRecoil)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponRecoil }) = 0;
		}
	}
}
