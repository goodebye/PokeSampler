#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SequencerComponent.h"

/* 
	this is the header for our BeatTimer class, a subclass of both
	TImer and ActionBroadcaster, for sending and receiving Actions
*/

class BeatTimer : public HighResolutionTimer, public ActionBroadcaster {
	public: 
		void setBPM(float _bpm);
		void startTimerByBPM();
		void hiResTimerCallback() override;
		int bpmToMilliseconds(float _bpm);
		float getBpm();

private:
		float bpm;
};