#pragma once

#include <vector>
#include <map>
#include <utility>
#include "Util.h"
#include "Step.h"

class Pattern {
public:
	int getNumberOfSteps();
	std::vector<Step*> getSteps();
	Step* getStep(int index);
	void addStep(int index, Step* step);
	void addNoteOff(int index, Note n);
	bool noteOffExists(int index);
	Note * getNoteOff(int index);
	Note * getNoteOn(int index);
	std::pair<Note*, Note*> noteEventsAtStep(int stepNumber);
	void initializePattern();
	void serialize();
	void deserialize();
private:
	const int defaultNumberOfSteps = 16;
	int numberOfSteps = defaultNumberOfSteps;
	std::vector<Step*> steps;
	std::map<int, Note> notesOff;
};