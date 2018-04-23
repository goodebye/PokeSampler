#pragma once

#include "Note.h"
#include <string>

class Step {
public:
	bool isEmpty();
	void setNoteOn(Note n);
	void setNoteOff(Note n);
	Note getNoteOn();
	Note getNoteOff();
private:
	Note *noteOn = nullptr;
	Note *noteOff = nullptr;
};