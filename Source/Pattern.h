#pragma once

#include <vector>
#include "Step.h"

class Pattern {
public:
	int getNumberOfSteps();
	std::vector<Step> getSteps();
	Step getStep(int index);
	void initializePattern();
	void serialize();
	void deserialize();
private:
	const int defaultNumberOfSteps = 16;
	int numberOfSteps = defaultNumberOfSteps;
	std::vector<Step> steps;
};