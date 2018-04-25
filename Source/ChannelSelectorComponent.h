#pragma once

//[Headers]  
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]

//==============================================================================
/**
                                                                    //[Comments]
                                                                    //[/Comments]
*/
class ChannelSelectorComponent  : public Component
{
public:
    ChannelSelectorComponent ();
    ~ChannelSelectorComponent();

    //[UserMethods]    
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
private:
    //[UserVariables]
	OwnedArray<TextButton> selectorButtons;
    //[/UserVariables]
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChannelSelectorComponent)
};

//[EndFile]
//[/EndFile]
