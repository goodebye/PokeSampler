#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/*
	This file defines our Synthesizer and SamplerVoices. These are used by our SamplerComponent et al.
	to make sounds based on MIDI messages.
*/

class SamplerAudioSource : public AudioSource
{
public:
	SamplerAudioSource()
	{
		for (auto i = 0; i < 1; ++i)
			// add voice to synth for monophonic playback
			synth.addVoice(new SamplerVoice());

		// setUsingSampleSound();
	}

	void setUsingSampleSound(File f)
	{
		// loading sample
		WavAudioFormat wavFormat;
		
		InputStream* is = f.createInputStream();
		ScopedPointer<AudioFormatReader> audioReader(wavFormat.createReaderFor(is, true));

		// setting range of sample
		BigInteger allNotes;
		allNotes.setRange(0, 128, true);

		// adding the sample to the synthesizer
		synth.clearVoices();
		synth.clearSounds();
		synth.addSound(new SamplerSound(
			"example sound", *audioReader, allNotes, 45, 0.1, 1, 10.0
		));

		for (auto i = 0; i < 1; ++i)
			// add voices to synth for polyphonic playback
			synth.addVoice(new SamplerVoice());
	}

	void prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate) override
	{
		// setting playback rate for our synthesizer based on the call
		// in the MainComponent
		synth.setCurrentPlaybackSampleRate(sampleRate);
	}

	void reset() {
		// clear voices so any dangling notes vanish
		synth.clearVoices();

		for (auto i = 0; i < 1; ++i)
			// add voices to synth for monophonic playback
			synth.addVoice(new SamplerVoice());
	}

	void releaseResources() override {}

	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override
	{
		// fill our audio buffer with sound!
		bufferToFill.clearActiveBufferRegion();
		MidiBuffer* midiBuff = new MidiBuffer();
		synth.renderNextBlock(*bufferToFill.buffer, *midiBuff, bufferToFill.startSample, bufferToFill.numSamples);
	}

	Synthesiser* getSynth() {
		// this method exists so we can have an outside reference to our synthesizer,
		// which allows us to send it messages from outside the SamplerComponent

		return &synth;
	}

private:
	Synthesiser synth;
};