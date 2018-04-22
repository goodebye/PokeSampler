//[Headers] You can add your own extra header files here...
//[/Headers]

#include "StepComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StepComponent::StepComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

StepComponent::~StepComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

void StepComponent::activate() {
	setHighlight(true);

}

void StepComponent::deactivate() {
	setHighlight(false);
}

void StepComponent::setHighlight(bool on)
{
	if (on) {
		highlighted = true;
	}
	else {
		highlighted = false;
	}
}

void StepComponent::setStep(Step *_step)
{
	step = _step;
}

void StepComponent::setStepNumber(int _stepNum)
{
	stepNumber = _stepNum;
}

//==============================================================================
void StepComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

	Colour fillColor = Colours::grey;
	if (highlighted) {
		if (step->isEmpty()) {
			Colours::orange;
		}
		else {
			Colours::yellow;
		}
	}
	
    g.fillAll (fillColor);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StepComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
	setBounds(0, 0, getWidth(), getHeight());
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StepComponent" componentName=""
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
