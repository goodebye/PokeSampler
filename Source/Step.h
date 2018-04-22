/*
  ==============================================================================

    Step.h
    Created: 21 Apr 2018 4:54:29am
    Author:  goode bye

  ==============================================================================
*/

#pragma once

#include "Note.h"
#include <string>

class Step {
public:
	bool isEmpty();
	const enum StepState { EMPTY, NONEMPTY };
	std::string test = "test";
private:
	Note note;
	StepState state = EMPTY;
};