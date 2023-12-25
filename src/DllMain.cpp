#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <thread>

// ReClass.NET
class Entity
{
public:
	char pad_0000[236]; //0x0000
	int32_t health; //0x00EC
	int32_t armor; //0x00F0
	char pad_00F4[20]; //0x00F4
	int32_t pistolReserveAmmo; //0x0108
	char pad_010C[16]; //0x010C
	int32_t rifleReserveAmmo; //0x011C
	char pad_0120[12]; //0x0120
	int32_t pistolAmmo; //0x012C
	char pad_0130[16]; //0x0130
	int32_t rifleAmmo; //0x0140
	int32_t grenade; //0x0144
	char pad_0148[760]; //0x0148
};

void UI()
{
	printf("[STATUS] DLL injected in AssaultCube successfully\n\n");
	printf("___________________________________________________\n\n");

	printf("Numpad1 = Rifle Ammo\n");
	printf("Numpad2 = Health\n");
	printf("Numpad3 = Grenade\n");
	printf("Numpad4 = Armor\n");
	printf("Numpad5 = Pistol ammo\n");
	printf("Numpad6 = Pistol reserve ammo\n");
	printf("Numpad7 = Rifle reserve ammo\n");
	printf("END = Eject\n");

	printf("___________________________________________________\n\n");
	printf("Toggle section\n\n");
}

BOOL WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	if(moduleBase)
		UI();

	bool bRifleAmmo{ false }, bHealth{ false }, bGrenade{ false }, bArmor{ false }, bPistolAmmo{ false }, bPistolClip{ false }, bRifleClip{ false };

	while (true)
	{
		if (GetAsyncKeyState(VK_END) & 1)
			break;

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bRifleAmmo = !bRifleAmmo;

			if (bRifleAmmo)
				printf("Rifle Ammo toggle on\n");
			else
				printf("Rifle Ammo toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bHealth = !bHealth;

			if (bHealth)
				printf("Health toggle on\n");
			else
				printf("Health toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bGrenade = !bGrenade;

			if (bGrenade)
				printf("Grenade toggle on\n");
			else
				printf("Grenade toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			bArmor = !bArmor;

			if (bArmor)
				printf("Armor toggle on\n");
			else
				printf("Armor toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD5) & 1)
		{
			bPistolAmmo = !bPistolAmmo;

			if (bPistolAmmo)
				printf("Pistol Ammo toggle on\n");
			else
				printf("Pistol Ammo toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD6) & 1)
		{
			bPistolClip = !bPistolClip;

			if (bPistolClip)
				printf("Pistol Clip toggle on\n");
			else
				printf("Pistol Clip toggle off\n");
		}
		if (GetAsyncKeyState(VK_NUMPAD7) & 1)
		{
			bRifleClip = !bRifleClip;

			if (bRifleClip)
				printf("Rifle Clip toggle on\n");
			else
				printf("Rifle Clip toggle off\n");
		}

		Entity* localPlayer = *(Entity**)(moduleBase + 0x0017E0A8);

		if (localPlayer)
		{
			if (bRifleAmmo)
				localPlayer->rifleAmmo = 999;
			if (bHealth)
				localPlayer->health = 999;
			if (bGrenade)
				localPlayer->grenade = 999;
			if (bArmor)
				localPlayer->armor = 999;
			if (bPistolAmmo)
				localPlayer->pistolAmmo = 999;
			if (bPistolClip)
				localPlayer->pistolReserveAmmo = 999;
			if (bRifleClip)
				localPlayer->rifleReserveAmmo = 999;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}


BOOL APIENTRY DllMain(
	HINSTANCE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpvReserved
)
{
	HANDLE hThread = nullptr;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		hThread = CreateThread(
			nullptr,
			NULL,
			(LPTHREAD_START_ROUTINE)HackThread,
			hModule,
			NULL,
			nullptr
		);
		if (hThread) {
			CloseHandle(hThread);
		}
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}
