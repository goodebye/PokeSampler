/*
	This file is the implementation of BeatTimer, a subclass of Timer. 
	This allows us to keep time in our sequencer.
*/

#include "BeatTimer.h"

void BeatTimer::setBPM(float _bpm)
{
	bpm = _bpm;
}

void BeatTimer::startTimerByBPM()
{
	// converts our BPM to millis, which is what a Timer expects
	int millis = bpmToMilliseconds(bpm);
	startTimer(millis);
}

void BeatTimer::hiResTimerCallback() 
{
	// this is an action message passed to listeners of our timer,
	// to distinguish them from other events
	sendActionMessage("BEAT SENT");
}

int BeatTimer::bpmToMilliseconds(float _bpm)
{
	// converts bpm to milliseconds
	return floor(60000 / _bpm);
}