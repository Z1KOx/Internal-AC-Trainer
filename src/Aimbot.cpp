#include "pch.hpp"
#include "vector.hpp"
#include "offsets.hpp"
#include "config.hpp"

#define M_PI 3.14159265358979323846

void Aimbot(uintptr_t moduleBase)
{
	uintptr_t localplayer = *reinterpret_cast<uintptr_t*>(moduleBase + offsets::LocalPlayerObject);
	uintptr_t entityList = *reinterpret_cast<uintptr_t*>(moduleBase + offsets::EntityList);
	uintptr_t playerCount = *(uintptr_t*)(moduleBase + offsets::EntityCount);

	Vec3 localHeadPos = *(Vec3*)(localplayer + offsets::X_headPosition);
	uintptr_t localTeam = *(uintptr_t*)(localplayer + offsets::Team);

<<<<<<< HEAD
	uintptr_t bestEntity = localplayer;
	float distance = 1000;

	for (int i = 1; i < playerCount; i++)
	{
		uintptr_t entity = *(uintptr_t*)(entityList + offsets::X_headPosition * i);
		uintptr_t entity = *(uintptr_t*)(entityList + 0x4 * i);

		uintptr_t entityTeam = *(uintptr_t*)(entity + offsets::Team);
		uintptr_t entityHealth = *(uintptr_t*)(entity + offsets::Health);
		BYTE entityOnScreen = *(BYTE*)(moduleBase + offsets::EntityDrawen);
		Vec3 entityHeadPos = *(Vec3*)(entity + offsets::X_headPosition);

		if (entityHealth < 0 || entityHealth < 100)
			continue;

		if (entityOnScreen == 192)
			continue;

		if (localTeam == entityTeam)
			continue;

		if ((localHeadPos - entityHeadPos).hypo3() < distance)
		{
			bestEntity = entity;
			distance = (localHeadPos - entityHeadPos).hypo3();
		}

		Vec3 delta = (*(Vec3*)(bestEntity + offsets::X_headPosition) - localHeadPos);
		float dx = atan2f(delta.y, delta.x) * 180 / M_PI + 90;
		float dy = atan2f(delta.z, sqrt(delta.x * delta.x + delta.y * delta.y)) * 180 / M_PI;
		dy += 0.2f;

		float smooth = config::Value::aimbotSmoothness;
		float fov = config::Value::aimbotFov;

		if (GetAsyncKeyState(VK_CONTROL)) 
		{
			if (std::abs(*(float*)(localplayer + offsets::X_view) - dx) <= fov &&
				std::abs(*(float*)(localplayer + offsets::Y_view) - dy) <= fov) 
			{
				*(float*)(localplayer + offsets::X_view) = (1.0 - smooth) * *(float*)(localplayer + offsets::X_view) + smooth * dx;
				*(float*)(localplayer + offsets::Y_view) = (1.0 - smooth) * *(float*)(localplayer + offsets::Y_view) + smooth * dy;
			}
		}
	}
}}

		if ((localHeadPos - entityHeadPos).hypo3() < distance && localTeam != entityTeam)
		{
			BestEntity = entity;
			distance = (localHeadPos - entityHeadPos).hypo3();
		}
	}

	Vec3 delta = (*(Vec3*)(BestEntity + offsets::X_headPosition) - localHeadPos);

	float yaw = atan2f(delta.y, delta.x) * 180 / M_PI;
	float hyp = sqrt(delta.x * delta.x + delta.y * delta.y);
	float pitch = atan2f(delta.z, hyp) * 180 / M_PI;

	pitch + 90;

	if (GetAsyncKeyState(VK_CONTROL))
	{
		*(float*)(localplayer + offsets::X_view) = yaw + 90;
		*(float*)(localplayer + offsets::Y_view) = pitch;
	}
}
>>>>>>> 7821238166c5cb2234721295fe7d67d1257c116d
