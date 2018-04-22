#pragma once

struct Note {
	int midiNote;
	int velocity;
	const int defaultVelocity = 127;
};