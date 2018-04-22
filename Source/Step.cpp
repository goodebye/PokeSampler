/*
  ==============================================================================

    Step.cpp
    Created: 21 Apr 2018 4:54:29am
    Author:  goode bye

  ==============================================================================
*/

#include "Step.h"

bool Step::isEmpty() {
	if (state == StepState::EMPTY) {
		return true;
	}
	else {
		return false;
	}
}