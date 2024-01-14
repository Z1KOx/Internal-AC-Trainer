#ifndef OFFSETS_H
#define OFFSETS_H

#include "pch.h"

namespace offsets
{
	// Local-Player addresses
	inline constexpr DWORD Username = 0x205;
	inline constexpr DWORD Health = 0xEC;
	inline constexpr DWORD Armour = 0xF0;
	inline constexpr DWORD RifleClip = 0x140;
	inline constexpr DWORD RifleReserve = 0x11C;
	inline constexpr DWORD PistolClip = 0x12C;
	inline constexpr DWORD PistolReserve = 0x108;
	inline constexpr DWORD Grenade = 0x144;

	// Local-Player view angels
	inline constexpr DWORD X_view = 0x34;
	inline constexpr DWORD Y_view = 0x38;

	// Local-Player positions
	inline constexpr DWORD X_position = 0x28;
	inline constexpr DWORD Y_position = 0x2C;
	inline constexpr DWORD Z_position = 0x30;

	// Weapon customization
	inline const std::vector<unsigned short>WeaponSound{ 0x364, 0xC, 0x42 };
	inline const std::vector<unsigned short>WeaponRapidfire{ 0x364, 0xC, 0x46 };
	inline const std::vector<unsigned short>WeaponDamage{ 0x364, 0xC, 0x4A };
	inline const std::vector<unsigned short>WeaponKickBack{ 0x364, 0xC, 0x54 };
	inline const std::vector<unsigned short>WeaponClip{ 0x364, 0xC, 0x56 };
	inline const std::vector<unsigned short>WeaponRecoil{ 0x364 , 0xC, 0x60 };

	// Base addresses
	inline constexpr ptrdiff_t LocalPlayerObject = 0x18AC00;
	inline constexpr ptrdiff_t EntityList = 0x18AC04;
}

#endif