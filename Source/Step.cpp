#pragma once

#include "Step.h"

Step::Step() {}

Step::Step(Note n, int duration) {
	setNoteOn(n, duration);
}

Step::Step(Note* n, int duration) {
	Note newNote = Note(n->getMidiNote());
	setNoteOn(newNote, duration);
}


void Step::setNoteOn(Note n, int _stepsUntilNoteOff) {
	noteOn = &n;
	setStepsUntilNoteOff(_stepsUntilNoteOff);
	empty = false;
}

Note Step::getNoteOn() {
	return *noteOn;
}

int Step::getStepsUntilNoteOff() {
	return stepsUntilNoteOff;
}

void Step::setStepsUntilNoteOff(int _stepsUntilNoteOff) {
	stepsUntilNoteOff = _stepsUntilNoteOff;
}

bool Step::isEmpty() {
	if (empty) {
		return true;
	}
	return false;
}

void Step::setEmpty() {
	empty = true;
	noteOn = nullptr;
}