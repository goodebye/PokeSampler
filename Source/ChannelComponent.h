#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "SamplerComponent.h"
#include "SequencerComponent.h"
//[/Headers]

/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
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
    //[/UserVariables]

    

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
