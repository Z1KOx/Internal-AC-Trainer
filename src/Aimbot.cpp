#include "pch.hpp"
#include "vector.hpp"
#include "offsets.hpp"

#define M_PI 3.14159265358979323846

void Aimbot(uintptr_t moduleBase)
{
	uintptr_t localplayer = *reinterpret_cast<uintptr_t*>(moduleBase + offsets::LocalPlayerObject);
	uintptr_t entityList = *reinterpret_cast<uintptr_t*>(moduleBase + offsets::EntityList);
	uintptr_t playerCount = *(uintptr_t*)(moduleBase + offsets::EntityCount);

	Vec3 localHeadPos = *(Vec3*)(localplayer + offsets::X_headPosition);
	uintptr_t localTeam = *(uintptr_t*)(localplayer + offsets::Team);

	uintptr_t nEntity = localplayer;
	float dist = 1000;

	for (int i = 1; i < playerCount; i++)
	{
		uintptr_t entity = *(uintptr_t*)(entityList + offsets::X_headPosition * i);

		uintptr_t entityTeam = *(uintptr_t*)(entity + offsets::Team);
		uintptr_t entityState = *(uintptr_t*)(entity + offsets::IsDead);
		Vec3 entityHeadPos = *(Vec3*)(entity + offsets::X_headPosition);

		if ((localHeadPos - entityHeadPos).hypo3() < dist && localTeam != entityTeam)
		{
			nEntity = entity;
			dist = (localHeadPos - entityHeadPos).hypo3();
		}
	}

	Vec3 delta = (*(Vec3*)(nEntity + offsets::X_headPosition) - localHeadPos);

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