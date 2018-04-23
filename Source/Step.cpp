#pragma once

#include "Step.h"

void Step::setNoteOn(Note n) {
	noteOn = &n;
}

void Step::setNoteOff(Note n) {
	noteOn = &n;
}

Note Step::getNoteOn() {
	return *noteOn;
}

Note Step::getNoteOff() {
	return *noteOff;
}

bool Step::isEmpty() {
	if (noteOn == nullptr) {
		return true;
	}
	else {
		return false;
	}
}