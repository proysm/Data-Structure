#include "Timer.h"

void Timer::start()
{
	startTime = clock();
}

void Timer::stop()
{
	stopTime = clock();
}

double Timer::getElapsedTime() const
{
	return ((double)(stopTime - startTime) / (CLOCKS_PER_SEC));
}