/*
  ==============================================================================

    BeatTimer.h
    Created: 21 Apr 2018 2:57:12am
    Author:  goode bye

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class BeatTimer : public Timer {
	public: 
		void setBPM(float bpm);
		void startTimerByBPM();
		void timerCallback() override;
		int bpmToMilliseconds(float bpm);

	private:
		float bpm;
};