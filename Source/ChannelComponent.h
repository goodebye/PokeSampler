#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
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

        //[UserMethods]     -- You can add your own custom methods in this section.
	void computePadding();
	void actionListenerCallback(const String &message) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	struct SequencerPadding {
		int padX = 0;
		int padY = 0;
	};
	SequencerComponent sequencer;
	SequencerPadding padding;
	int padFactor = 70;
    //[/UserVariables]

    

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
