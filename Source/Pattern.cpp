#include "Pattern.h"

int Pattern::getNumberOfSteps()
{
	return numberOfSteps;
}

std::vector<Step> Pattern::getSteps()
{
	return steps;
}

Step Pattern::getStep(int index) {
	return steps[index];
}

void Pattern::initializePattern()
{
	for (int n = 0; n < defaultNumberOfSteps; n++) {
		steps.push_back(Step());
	}
}
