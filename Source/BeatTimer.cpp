/*
  ==============================================================================

    BeatTimer.cpp
    Created: 21 Apr 2018 2:57:12am
    Author:  goode bye

  ==============================================================================
*/

#include "BeatTimer.h"

void BeatTimer::setBPM(float _bpm)
{
	bpm = _bpm;
}

void BeatTimer::startTimerByBPM()
{
	int millis = bpmToMilliseconds(bpm);
	startTimer(millis);
}

void BeatTimer::timerCallback() 
{
	sendActionMessage("great! fantastic!");
}

int BeatTimer::bpmToMilliseconds(float bpm)
{
	return floor(60000 / bpm);
}