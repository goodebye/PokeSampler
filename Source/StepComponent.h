#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Step.h"
//[/Headers]

//==============================================================================
/**
                                                                    //[Comments]
    The StepComponent class is a subclass of component and basically functions
	as the 'view' for Steps in a Pattern. Multiple instances of StepComponents
	are created in a SequencerComponent. This class is mostly responsible for
	displaying data associated with a given Step, such as what it contains and
	whether or not it is playing, or empty, or whathaveyou.
                                                                    //[/Comments]
*/
class StepComponent  : public Component
{
public:
    //==============================================================================
    StepComponent ();
    ~StepComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void activate();
	void deactivate();
	void setHighlight(bool on);
	void setStep(Step *_step);
	void setStepNumber(int _stepNum);
	Step* step;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool highlighted = false;
	bool hasContent = false;
	int stepNumber = 0;
	//[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
