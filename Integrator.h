#pragma once

class Integrator
{
private:
	float sum;
public:
	float integrate(float input)
	{
		sum = sum + input * 0.25; 
		return sum;
	}
	Integrator(float initialCondition);
};
Integrator::Integrator(float initialCondition)
{
	sum = initialCondition;
};
