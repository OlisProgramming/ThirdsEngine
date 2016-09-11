#pragma once

#include <chrono>

class Time
{
public:
	static float delta;

	static std::chrono::steady_clock::time_point getTime();
	static float getDelta();
	static void setDelta(float delta);
};