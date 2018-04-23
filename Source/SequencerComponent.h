#pragma once

//[Headers]
#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include "StepComponent.h"
#include "Pattern.h"
#include "Step.h"
//[/Headers]

/**
                                                                    //[Comments]
    SequencerComponent: a clas which derives from JUCE's component class. This
	class displays the step sequencer as well as holds the Pattern currently being
	played. It accepts a trigger() method, called in the MainComponent, which returns
	a Step to be passed to the Sampler.
                                                                    //[/Comments]
*/
class SequencerComponent  : public Component
{
public:
     SequencerComponent ();
    ~SequencerComponent();

        //[UserMethods]

	void paint(Graphics& g) override;
	void resized() override;
	void visibilityChanged() override;
	Step trigger();
	void activateStepComponent(int stepNum);
	void deactivateStepComponent(int stepNum);
	int previousStepNumber();
	int nextStepNumber();

    //[/UserMethods]

private:
    //[UserVariables]
	Pattern pattern;
	OwnedArray<StepComponent> stepComponents;
	const int rows = 2;
	int currentStepNumber = 0;
    //[/UserVariables]

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerComponent)
};
