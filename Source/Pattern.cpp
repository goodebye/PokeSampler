/*
  ==============================================================================

    Pattern.cpp
    Created: 21 Apr 2018 7:53:31pm
    Author:  goode bye

  ==============================================================================
*/

#include "Pattern.h"

int Pattern::getNumberOfSteps()
{
	return numberOfSteps;
}

std::vector<Step> Pattern::getSteps()
{
	return steps;
}

void Pattern::initializePattern()
{
	for (int n = 0; n < defaultNumberOfSteps; n++) {
		steps.push_back(Step());
	}
}
