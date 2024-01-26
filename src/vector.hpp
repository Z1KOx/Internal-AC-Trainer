#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

struct Vec3 
{
public:
	float x{};
	float y{};
	float z{};

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3() {}

	Vec3 operator+ (const Vec3& a) const {
		return Vec3(x + a.x, y + a.y, z + a.z);
	}

	Vec3 operator- (const Vec3& a) const {
		return Vec3(x - a.x, y - a.y, z - a.z);
	}

	Vec3 operator/ (const Vec3& a) const {
		return Vec3(x / a.x, y / a.y, z / a.z);
	}

	Vec3 operator* (const Vec3& a) const {
		return Vec3(x * a.x, y * a.y, z * a.z);
	}

	float hypo3() const {
		return sqrt(x * x + y * y + z * z);
	}
};

struct Vec2
{
public:
	float x{};
	float y{};

	Vec2(float x, float y) : x(x), y(y) {}
	Vec2() {}

	Vec2 operator+ (const Vec2& a) const {
		return Vec2(x + a.x, y + a.y);
	}

	Vec2 operator- (const Vec2& a) const {
		return Vec2(x - a.x, y - a.y);
	}

	Vec2 operator/ (const Vec2& a) const {
		return Vec2(x / a.x, y / a.y);
	}

	Vec2 operator* (const Vec2& a) const {
		return Vec2(x * a.x, y * a.y);
	}
};

#endif