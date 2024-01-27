#ifndef CONFIH_HPP
#define CONFIG_HPP

namespace config
{
	namespace Enable
	{
		constexpr bool Health = true;
		constexpr bool Armour = true;

		constexpr bool AssaultRifleClip = true;
		constexpr bool AssaultRifleReserve = true;

		constexpr bool SubmachineGunClip = true;
		constexpr bool SubmachineGunReserve = true;

		constexpr bool SniperRifleClip = true;
		constexpr bool SniperRifleReserve = true;

		constexpr bool CombatShotgunClip = true;
		constexpr bool CombatShotgunReserve = true;

		constexpr bool CarbineRifleClip = true;
		constexpr bool CarbineRifleReserve = true;

		constexpr bool PistolClip = true;
		constexpr bool PistolReserve = true;

		constexpr bool Grenade = true;

		constexpr bool WeaponSound = true;
		constexpr bool WeaponDamage = true;

		// Please keep only one rapidfire methode on true
		constexpr bool WeaponRapidfireAll = false; // If you switch guns than they will disappear but you can rapidfire will all guns
		constexpr bool WeaponRapidfire = true;     // You can switch guns but you cant rapidfire with semi guns e.g. snipers, pistol

		constexpr bool WeaponNoKickBack = true;
		constexpr bool WeaponNoRecoil = true;

		constexpr bool InfJump = true;

		constexpr bool ShowBulletHoles = true;
		constexpr bool NoSway = true;

		constexpr bool TeleportEnemies = false;

		constexpr bool Aimbot = true; // ADDING SOON KEYBIND SUPPORT DEFAULT IS CONTROL!
	}

	namespace Value
	{
		constexpr int Health = 123;
		constexpr int Armour = 456;

		constexpr int AssaultRifleClip = 789;
		constexpr int AssaultRifleReserve = 1234;

		constexpr int SubmachineGunClip = 123;
		constexpr int SubmachineGunReserve = 456;

		constexpr int SniperRifleClip = 321;
		constexpr int SniperRifleReserve = 654;

		constexpr int CombatShotgunClip = 1337;
		constexpr int CombatShotgunReserve = 7331;

		constexpr int CarbineRifleClip = 777;
		constexpr int CarbineRifleReserve = 333;

		constexpr int PistolClip = 5678;
		constexpr int PistolReserve = 4096;

		constexpr int Grenade = 512;

		constexpr int WeaponSound = 2;
		constexpr int WeaponDamage = 100;

		constexpr float aimbotSmoothness = 0.1f;
		constexpr float aimbotFov = 20.f;
	}

	void PrintSettings();
}

#endif
