#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include "ChannelComponent.h"
#include "BeatTimer.h"
#include "LoopableSamplerVoice.h"

class MainComponent   : public AudioAppComponent
{
public:
    MainComponent();
    ~MainComponent();

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void paint (Graphics& g) override;
    void resized() override;

private:
	BeatTimer beatTimer;
	OwnedArray<ChannelComponent> channels;
	std::vector<SamplerAudioSource*> samplerAudioSources;
	MixerAudioSource mixer;
	int currentChannel = 0;
	int numberOfChannels = 2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
