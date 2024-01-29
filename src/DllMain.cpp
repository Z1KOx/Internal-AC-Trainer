#include "Hack.cpp"
#include "offsets.hpp"

DWORD Uninitilize(HINSTANCE hModule, FILE* f)
{
	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

void Initilize(HINSTANCE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	MainHack();

	Uninitilize(hModule, f);
}

bool __stdcall DllMain(
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
		hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Initilize, hModule, 0, nullptr);

		if (hThread)
		{
			CloseHandle(hThread);
			hThread = nullptr;
		}
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}
