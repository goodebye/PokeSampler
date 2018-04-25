#include "Pattern.h"
#include "../JuceLibraryCode/JuceHeader.h"


/*
	Patterns hold a vector of Steps, which themselves contain note data.
	Pattern is used by our sequencer to hold steps with notes
	to be given off to the sampler.
*/

int Pattern::getNumberOfSteps()
{
	return numberOfSteps;
}

std::vector<Step*> Pattern::getSteps()
{
	return steps;
}

Step* Pattern::getStep(int index) {
	return steps[index];
}

void Pattern::addStep(int index, Step* step)
{
	if (!step->isEmpty()) {
		addNoteOff(Util::wrappingModulo(index + step->getStepsUntilNoteOff(), numberOfSteps), step->getNoteOn());
	}
	steps[index] = step;
}

void Pattern::addNoteOff(int index, Note n) {
	notesOff.insert({ index, n });
}

bool Pattern::noteOffExists(int index) {
	if (notesOff.count(index) > 0) {
		return true;
	}
	return false;
}

Note* Pattern::getNoteOff(int index) {
	if (noteOffExists(index)) {
		return &notesOff[index];
	}
	return nullptr;
}

Note* Pattern::getNoteOn(int index) {
	if (!steps[index]->isEmpty()) {
		return &steps[index]->getNoteOn();
	}
	return nullptr;
}

std::pair<Note*, Note*> Pattern::noteEventsAtStep(int stepNumber) {
	DBG("HEY BITCH: ");
	DBG(getNoteOn(stepNumber)->toString());
	return std::pair <Note*, Note*> (getNoteOn(stepNumber), getNoteOff(stepNumber));
}

void Pattern::initializePattern()
{
	for (int n = 0; n < defaultNumberOfSteps; n++) {
		steps.push_back(new Step());
	}
}
