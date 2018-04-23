#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "SamplerComponent.h"
#include "SequencerComponent.h"
//[/Headers]

/**
                                                                    //[Comments]
    This component is one of the main components in this application. It holds
	both a SequencerComponent and a SamplerComponent, as well as listens for
	ticks from the BeatTimer, to be sent to the Sequencer. Each tick to the
	Sequencer should return a Step, either empty or full. If the step has content,
	we send it to the SamplerComponent, where it will be sent to the SamplerSynthesizer
	and play a note.
                                                                    //[/Comments]
*/
class ChannelComponent  : public Component, public ActionListener
{
public:
     ChannelComponent ();
    ~ChannelComponent();

    //[UserMethods]
	void computePadding();
	void actionListenerCallback(const String &message) override;
	SamplerComponent* getSamplerComponent();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

private:
    //[UserVariables] 

	struct SequencerPadding {
		int padX = 0;
		int padY = 0;
	};
	SequencerComponent sequencer;
	SamplerComponent samplerComponent;
	SequencerPadding padding;
	int padFactor = 70;
	int noteToTurnOff = 60;
	Random random;
    //[/UserVariables]

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
