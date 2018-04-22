#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include "ChannelComponent.h"
#include "BeatTimer.h"

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
	int currentChannel = 0;
	int numberOfChannels = 8;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
