#include <windows.h>
#include <vector>
#include <cstdio>

BOOL WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	printf("DLL injected in AssaultCube successfully\n\n");
	printf("Numpad1 = Rifle Ammo\n");
	printf("Numpad2 = Health\n");
	printf("Numpad3 = Grenade\n");
	printf("Numpad4 = Armor\n");
	printf("Numpad5 = Pistol Ammo\n");
	printf("Numpad6 = Pistol Clip\n");
	printf("Numpad7 = Rifle Clip\n");
	printf("END = Eject\n");

	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	bool bAmmo{ false }, bHealth{false}, bGrenade{false}, bArmor{false}, bPistolAmmo{false}, bPistolClip{false}, bRifleClip{false};

	while(true)
	{
		if (GetAsyncKeyState(VK_END) & 1)
		{
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bAmmo = !bAmmo;
		}
		if(GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bHealth = !bHealth;
		}
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bGrenade = !bGrenade;
		}
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			bArmor = !bArmor;
		}
		if (GetAsyncKeyState(VK_NUMPAD5) & 1)
		{
			bPistolAmmo = !bPistolAmmo;
		}
		if (GetAsyncKeyState(VK_NUMPAD6) & 1)
		{
			bPistolClip = !bPistolClip;
		}
		if (GetAsyncKeyState(VK_NUMPAD7) & 1)
		{
			bRifleClip = !bRifleClip;
		}

		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x0017E0A8);

		if(localPlayerPtr)
		{
			if(bAmmo)
			{
				*(int*)(*localPlayerPtr + 0x140) = 999;
			}
			if(bHealth)
			{
				*(int*)(*localPlayerPtr + 0xEC) = 999;
			}
			if (bGrenade)
			{
				*(int*)(*localPlayerPtr + 0x144) = 999;
			}
			if (bArmor)
			{
				*(int*)(*localPlayerPtr + 0xF0) = 999;
			}
			if (bPistolAmmo)
			{
				*(int*)(*localPlayerPtr + 0x12C) = 999;
			}
			if (bPistolClip)
			{
				*(int*)(*localPlayerPtr + 0x108) = 999;
			}
			if (bRifleClip)
			{
				*(int*)(*localPlayerPtr + 0x11C) = 999;
			}
		}

		Sleep(1);
	}

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}


BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}