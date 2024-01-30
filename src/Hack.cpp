#include "offsets.hpp"
#include "config.hpp"

void MainHack()
{
	const uintptr_t moduleBase = (uintptr_t)GetModuleHandleA("ac_client.exe");

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
			break;

		config::PrintSettings();

		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + offsets::LocalPlayerObject);
		uintptr_t* entityList = (uintptr_t*)(moduleBase + offsets::EntityList);

		if (localPlayerPtr)
		{
			if (entityList)
				config::initFeatures(localPlayerPtr, entityList, moduleBase);

			config::init(localPlayerPtr);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}
