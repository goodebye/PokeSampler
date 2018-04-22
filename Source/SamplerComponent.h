#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]

class SamplerComponent  : public Component
{
public:
     SamplerComponent ();
    ~SamplerComponent();

    //[UserMethods]
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
private:
    //[UserVariables]
    //[/UserVariables]    

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerComponent)
};