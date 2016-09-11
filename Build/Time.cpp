#include "Time.h"

float Time::delta = 0;

std::chrono::steady_clock::time_point Time::getTime()
{
	return std::chrono::high_resolution_clock::now();
}

float Time::getDelta()
{
	return delta;
}

void Time::setDelta(float delta)
{
	Time::delta = delta;
}