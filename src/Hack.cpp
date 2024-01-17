#include "offsets.hpp"
#include "config.hpp"
#include "mem.hpp"

void printConfig()
{
	static bool bPrintConfig{ true };

	if (bPrintConfig)
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

		std::cout << "Weapon Rapidfire          [ " << std::boolalpha << config::Enable::WeaponRapidfire << " ]\n";
		std::cout << "Weapon No KickBack        [ " << std::boolalpha << config::Enable::WeaponNoKickBack << " ]\n";
		std::cout << "Weapon No Recoil          [ " << std::boolalpha << config::Enable::WeaponNoRecoil << " ]\n\n";

		std::cout << "Infinite Jump             [ " << std::boolalpha << config::Enable::InfJump << " ]\n";

		bPrintConfig = false;
	}
}

void MainHack()
{
	const uintptr_t moduleBase = (uintptr_t)GetModuleHandleA("ac_client.exe");

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
			break;

		const uintptr_t* localPlayer = (uintptr_t*)(moduleBase + offsets::LocalPlayerObject);

		printConfig();

		if (localPlayer)
		{
			if (config::Enable::Health)
				*(int*)(*localPlayer + offsets::Health) = config::Value::Health;
			if (config::Enable::Armour)
				*(int*)(*localPlayer + offsets::Armour) = config::Value::Armour;

			if (config::Enable::AssaultRifleClip)
				*(int*)(*localPlayer + offsets::AssaultRifleClip) = config::Value::AssaultRifleClip;
			if (config::Enable::AssaultRifleReserve)
				*(int*)(*localPlayer + offsets::AssaultRifleReserve) = config::Value::AssaultRifleReserve;

			if (config::Enable::SubmachineGunClip)
				*(int*)(*localPlayer + offsets::SubmachineGunClip) = config::Value::SubmachineGunClip;
			if (config::Enable::SubmachineGunReserve)
				*(int*)(*localPlayer + offsets::SubmachineGunReserve) = config::Value::SubmachineGunReserve;

			if (config::Enable::SniperRifleClip)
				*(int*)(*localPlayer + offsets::SniperRifleClip) = config::Value::SniperRifleClip;
			if (config::Enable::SniperRifleReserve)
				*(int*)(*localPlayer + offsets::SniperRifleReserve) = config::Value::SniperRifleReserve;

			if (config::Enable::CombatShotgunClip)
				*(int*)(*localPlayer + offsets::CombatShotgunClip) = config::Value::CombatShotgunClip;
			if (config::Enable::CombatShotgunReserve)
				*(int*)(*localPlayer + offsets::CombatShotgunReserve) = config::Value::CombatShotgunReserve;

			if (config::Enable::CarbineRifleClip)
				*(int*)(*localPlayer + offsets::CarbineRifleClip) = config::Value::CarbineRifleClip;
			if (config::Enable::CarbineRifleReserve)
				*(int*)(*localPlayer + offsets::CarbineRifleReserve) = config::Value::CarbineRifleReserve;

			if (config::Enable::PistolClip)
				*(int*)(*localPlayer + offsets::PistolClip) = config::Value::PistolClip;
			if (config::Enable::PistolReserve)
				*(int*)(*localPlayer + offsets::PistolReserve) = config::Value::PistolReserve;

			if (config::Enable::Grenade)
				*(int*)(*localPlayer + offsets::Grenade) = config::Value::Grenade;


			if (config::Enable::WeaponSound)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponSound }) = config::Value::WeaponSound;
			if (config::Enable::WeaponRapidfire)
			{
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponRapidfire }) = 0;
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponIsAuto }) = 1;
			}
			if (config::Enable::WeaponDamage)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponDamage }) = config::Value::WeaponDamage;
			if (config::Enable::WeaponNoKickBack)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponKickBack }) = 0;
			if (config::Enable::WeaponNoRecoil)
				*(int*)mem::FindDMAAddy(moduleBase + 0x18AC00, { offsets::WeaponRecoil }) = 0;


			if (config::Enable::InfJump)
				*(int*)(*localPlayer + offsets::Infjump) = 1;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
