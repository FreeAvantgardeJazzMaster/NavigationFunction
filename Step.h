#pragma once

float currentTime = 0;

float step(float startTime)
{
	if (currentTime > startTime)
	{
		return 1;
	}
	else
	{
		currentTime = currentTime + 0.25;
		return 0;
	}
}