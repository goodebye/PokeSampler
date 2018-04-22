#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SequencerComponent.h"

class BeatTimer : public Timer, public ActionBroadcaster {
	public: 
		void setBPM(float bpm);
		void startTimerByBPM();
		void timerCallback() override;
		int bpmToMilliseconds(float bpm);

	private:

		float bpm;
};