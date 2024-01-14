#ifndef CONFIH_H
#define CONFIG_H

namespace config
{
	namespace Enable
	{
		constexpr bool Health = true;
		constexpr bool Armour = true;
		constexpr bool RifleClip = true;
		constexpr bool RifleReserve = true;
		constexpr bool PistolClip = true;
		constexpr bool PistolReserve = true;
		constexpr bool Grenade = true;
		
		constexpr bool WeaponSound = true;
		constexpr bool WeaponDamage = true;
		constexpr bool WeaponRapidfire = true;
		constexpr bool WeaponKickBack = true;
		constexpr bool WeaponRecoil = true;
	}

	namespace Value
	{
		constexpr int Health = 123;
		constexpr int Armour = 456;
		constexpr int RifleClip = 789;
		constexpr int RifleReserve = 1234;
		constexpr int PistolClip = 5678;
		constexpr int PistolReserve = 4096;
		constexpr int Grenade = 512;
		
		constexpr int WeaponSound = 2;
		constexpr int WeaponDamage = 100;
	}
}

#endif
