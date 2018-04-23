#pragma once

#include <string>

class Note {
public:
	Note(int _midiNote) {
		midiNote = _midiNote;
		velocity = 127;
	}

	Note() {
		midiNote = -1;
		velocity = 0;
	}

	bool isEmpty() {
		if (midiNote == -1) {
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
	int midiNote;
	int velocity;
	const int defaultVelocity = 127;
};