#pragma once

#include <vector>
#include "Step.h"

class Pattern {
public:
	int getNumberOfSteps();
	std::vector<Step> getSteps();
	void initializePattern();
private:
	int numberOfSteps;
	const int defaultNumberOfSteps = 16;
	std::vector<Step> steps;
};