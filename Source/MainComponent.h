#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include "ChannelComponent.h"
#include "ChannelSelectorComponent.h"
#include "BeatTimer.h"
#include "LoopableSamplerVoice.h"

class MainComponent   : public AudioAppComponent, Button::Listener
{
public:
    MainComponent();
    ~MainComponent();

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
	void buttonClicked(Button* button) override;
	void setActiveChannel(int channelNumber);

    void paint (Graphics& g) override;
    void resized() override;

private:
	BeatTimer beatTimer;
	OwnedArray<ChannelComponent> channels;
	OwnedArray<TextButton> channelSelectorButtons;
	std::vector<SamplerAudioSource*> samplerAudioSources;
	MixerAudioSource mixer;
	int currentChannel = 0;
	int numberOfChannels = 4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
