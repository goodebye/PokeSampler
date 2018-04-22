//[Headers] You can add your own extra header files here...
#include "Util.h"
#include <math.h>
//[/Headers]

#include "SequencerComponent.h"

//==============================================================================
SequencerComponent::SequencerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	pattern.initializePattern();

	int stepNum = 0;

	for (Step step : pattern.getSteps()) {
		StepComponent sc;
		sc.setComponentID("STEP" + stepNum);
		sc.setStepNumber(stepNum);
		sc.setStep(&step);
		addAndMakeVisible(sc);
	}
    //[/Constructor]
}

SequencerComponent::~SequencerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SequencerComponent::paint(Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(Colours::darkolivegreen);
	g.setColour(Colours::green);
	g.drawLine(0, getHeight() / 2, getWidth(), getHeight() / 2, 5);


	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void SequencerComponent::resized() {
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	int stepsPerRow = pattern.getNumberOfSteps() / rows;
	int w = getWidth() / stepsPerRow;
	int h = getHeight() / rows;

	for (int stepNum = 0; stepNum < pattern.getNumberOfSteps(); stepNum++) {
		int row = floor(stepNum / stepsPerRow);
		int col = stepNum % stepsPerRow;

		getChildren()[stepNum]->setBounds(col * w, row * h, w, h);
	}
    //[/UserResized]
}

void SequencerComponent::trigger()
{
	activateStepComponent(currentStepNumber);
	// Step s = getCurrentStep();
	// TODO: hand step over to sampler;
	deactivateStepComponent(previousStepNumber());
	currentStepNumber = nextStepNumber();
}

void SequencerComponent::activateStepComponent(int stepNumber)
{
	
}

int SequencerComponent::previousStepNumber() 
{
	return Util::wrappingModulo(currentStepNumber - 1, pattern.getNumberOfSteps());
}

int SequencerComponent::nextStepNumber() {
	return Util::wrappingModulo(currentStepNumber + 1, pattern.getNumberOfSteps());
}

void SequencerComponent::deactivateStepComponent(int stepNumber) 
{
	
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SequencerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
