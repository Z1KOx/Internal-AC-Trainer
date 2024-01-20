#ifndef OFFSETS_HPP
#define OFFSETS_HPP

#include "pch.hpp"

namespace offsets
{
	// Local-Player addresses
	inline constexpr DWORD Username = 0x205;
	inline constexpr DWORD Health = 0xEC;
	inline constexpr DWORD Armour = 0xF0;
	inline constexpr DWORD AssaultRifleClip = 0x140;
	inline constexpr DWORD AssaultRifleReserve = 0x11C;
	inline constexpr DWORD SubmachineGunClip = 0x138;
	inline constexpr DWORD SubmachineGunReserve = 0x114;
	inline constexpr DWORD SniperRifleClip = 0x13C;
	inline constexpr DWORD SniperRifleReserve = 0x118;
	inline constexpr DWORD CombatShotgunClip = 0x134;
	inline constexpr DWORD CombatShotgunReserve = 0x110;
	inline constexpr DWORD CarbineRifleClip = 0x130;
	inline constexpr DWORD CarbineRifleReserve = 0x10C;
	inline constexpr DWORD PistolClip = 0x12C;
	inline constexpr DWORD PistolReserve = 0x108;
	inline constexpr DWORD Grenade = 0x144;

	// Local-Player view angels
	inline constexpr DWORD X_view = 0x34;
	inline constexpr DWORD Y_view = 0x38;

	// Local-Player positions & movement
	inline constexpr DWORD X_headPosition = 0x4;
	inline constexpr DWORD Y_headPosition = 0x8;
	inline constexpr DWORD Z_headPosition = 0xC;
	inline constexpr DWORD X_position = 0x28;
	inline constexpr DWORD Y_position = 0x2C;
	inline constexpr DWORD Z_position = 0x30;
	inline constexpr BYTE Infjump = 0x5D;

	// Weapon customization
	inline const ::std::vector<WORD>WeaponSound{ 0x364, 0xC, 0x42 };
	inline const ::std::vector<WORD>WeaponRapidfire{ 0x364, 0xC, 0x46 };
	inline const ::std::vector<WORD>WeaponDamage{ 0x364, 0xC, 0x4A };
	inline const ::std::vector<WORD>WeaponKickBack{ 0x364, 0xC, 0x54 };
	inline const ::std::vector<WORD>WeaponClip{ 0x364, 0xC, 0x56 };
	inline const ::std::vector<WORD>WeaponRecoil{ 0x364 , 0xC, 0x60 };
	inline const ::std::vector<WORD>WeaponIsAuto{ 0x364, 0xC, 0x66 };

	// Base addresses
	inline constexpr ::std::ptrdiff_t LocalPlayerObject = 0x18AC00;
	inline constexpr ::std::ptrdiff_t EntityList = 0x18AC04;

	// Some random offsets i've reverse engineered recently for fun
	inline constexpr DWORD IsScoping = 0x66;
	inline constexpr DWORD IsDead = 0x76;
	inline constexpr DWORD CN = 0x1C4;
	inline constexpr DWORD CurrAmmo = 0x364 + 0x14 + 0x0;
	inline constexpr DWORD CurrWeapon = 0x364 + 0x4;
	inline constexpr DWORD Reloading = 0x364 + 0x20;
	inline constexpr DWORD Team = 0x30C;
	inline constexpr DWORD Ping = 0x1D0;
	inline constexpr DWORD Role = 0x200;
	inline constexpr DWORD Frags = 0x1DC;
	inline constexpr DWORD Flags = 0x1E0;
	inline constexpr DWORD Deaths = 0x1E4;
	inline constexpr DWORD Tks = 0x1E8;
	inline constexpr DWORD ToggleSpec = 0x318;
	inline constexpr DWORD WalkForward = 0x82;
	inline constexpr DWORD WalkLeft = 0x80;
	inline constexpr DWORD WalkRight = 0x81;
	inline constexpr DWORD WalkBackward = 0x83;
	inline constexpr DWORD Crouch = 0x63;
	inline constexpr DWORD CrosshairSize = 0x18A884;
	inline constexpr DWORD CrosshairFx = 0x18A88C;
	inline constexpr DWORD HideRadar = 0x18A894;
	inline constexpr DWORD HideCompass = 0x18A898;
	inline constexpr DWORD HideTeam = 0x18A89C;
	inline constexpr DWORD HideTeamScoreHud = 0x18A8A0;
	inline constexpr DWORD FlagScoreHudTransparency = 0x18A8A4;
	inline constexpr DWORD HideEditInfoPanel = 0x18A8A8;
	inline constexpr DWORD HideVote = 0x18A8AC;
	inline constexpr DWORD ShowMap = 0x18A8C0;
	inline constexpr DWORD DamageScreen = 0x18A8F0;
	inline constexpr DWORD MTExplosion = 0x18AAE4;
	inline constexpr DWORD BulletBouncesSound = 0x18AAF8;
	inline constexpr DWORD BulletHole = 0x18AAFC;
	inline constexpr DWORD BulletHoleEttl = 0x18AB00;
	inline constexpr DWORD LoadSky = 0x18ABBC;
	inline constexpr DWORD Gamemode = 0x18ABF8;
	inline constexpr DWORD Hitsound = 0x18AC38;
	inline constexpr DWORD AutoReload = 0x190908;
	inline constexpr DWORD NoSway = 0x1908F4;
	inline constexpr DWORD FullbrightLevel = 0x19083C;
	inline constexpr DWORD ShowWeapon = 0x18A86C;
	inline constexpr DWORD ShowVelocity = 0x18A90C;
	inline constexpr DWORD BlankOutHud = 0x18A910;
	inline constexpr DWORD GameSpeed = 0x191F38;
	inline constexpr DWORD Jump = 0x195164;
	inline constexpr DWORD RightHand = 0x190D34;
	inline constexpr DWORD ShowPosDbg = 0x18A904;
}

#endif
