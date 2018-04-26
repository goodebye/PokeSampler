#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include <set>
#include "ChannelComponent.h"
#include "ChannelSelectorComponent.h"
#include "BeatTimer.h"
#include "LoopableSamplerVoice.h"
#include "Util.h"

class MainComponent   : public AudioAppComponent, Button::Listener, MidiInputCallback,
							MidiKeyboardStateListener, ActionListener, Slider::Listener
{
public:
    MainComponent();
    ~MainComponent();

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
	void buttonClicked(Button* button) override;
	void sliderValueChanged(Slider* slider) override;
	void setActiveChannel(int channelNumber);
	ChannelComponent* getActiveChannel();
	void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) override;
	bool noteIsReservedNote(int note);
	bool noteIsOnKeyboard(int note);
	void handleNoteOn(MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override;
	void handleNoteOff(MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override;
	void actionListenerCallback(const String &message) override;

    void paint (Graphics& g) override;
    void resized() override;

private:
	struct RecordingNote {
		RecordingNote() {
			noData = true;
		}
		RecordingNote(Note* _n, int _duration, int _startStep) {
			note = _n;
			duration = _duration;
			startStep = _startStep;
			noData = false;
		}
		Note* note;
		bool noData = true;
		int duration = 0;
		int startStep = 0;
	};

	BeatTimer beatTimer;
	OwnedArray<ChannelComponent> channels;
	OwnedArray<TextButton> channelSelectorButtons;
	TextButton playButton;
	TextButton recordButton;
	std::vector<SamplerAudioSource*> samplerAudioSources;
	MixerAudioSource mixer;
	int currentChannel = 0;
	int numberOfChannels = 8;
	enum TransportKeys { PLAY_TOGGLE = 18, RECORD };
	std::set<int> transportKeySet = { 18, 19 };
	const int channelKeyStart = 10;
	int noteNumberToChannel(int noteNumber);
	void toggleRecording();
	void beginRecording();
	void stopRecording();
	void togglePlaying();
	bool isPlaying();
	void startPlaying();
	void stopPlaying();
	bool recording = false;
	RecordingNote* recordingNote = new RecordingNote();
	Slider bpmDial;
	Slider reverbDial;
	int64 lastBeatTime;
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};