#pragma once

#include <string>

/*
	our Note class allows us a robust way of representing
	musical notes in a way that allows us to denormalize them into
	Steps in Patterns. 
*/

class Note {
public:
	Note(int _midiNote) {
		midiNote = _midiNote;
		velocity = 127;
		empty = false;
	}

	Note() {
		empty = true;
		midiNote = -1;
		velocity = 0;
	}

	bool isEmpty() {
		if (empty) {
			return true;
		}
		return false;
	}

	int getMidiNote() {
		return midiNote;
	}

	int getVelocity() {
		return velocity;
	}

	std::string toString() {
		return "note: " + midiNote;
	}

private:
	int midiNote = -1;
	int velocity = 127;
	bool empty = true;
	const int defaultVelocity = 30;
};