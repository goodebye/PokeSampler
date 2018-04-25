#pragma once

#include "Note.h"
#include <string>

class Step {
public:
	Step();
	Step(Note n, int duration);
	Step(Note * n, int duration);
	void setNoteOn(Note n, int _stepsUntilNoteOff);
	Note getNoteOn();
	int getStepsUntilNoteOff();
	void setStepsUntilNoteOff(int _stepsUntilNoteOff);
	bool isEmpty();
	void setEmpty();
private:
	Note *noteOn = nullptr;
	bool empty = true;
	int stepsUntilNoteOff = 0;
};