//[Headers] 
//[/Headers]

#include "StepComponent.h"

StepComponent::StepComponent ()
{
    //[Constructor_pre] 
	addAndMakeVisible(stepButton);
	stepButton.addListener(this);
    //[/Constructor_pre]
    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] 
    //[/Constructor]
}

StepComponent::~StepComponent()
{
    //[Destructor_pre]. 
    //[/Destructor_pre]
    //[Destructor]. 
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
	repaint();
}

void StepComponent::setStep(Step *_step)
{
	step = _step;
}

void StepComponent::setStepNumber(int _stepNum)
{
	stepNumber = _stepNum;
}

void StepComponent::paint (Graphics& g)
{
    //[UserPrePaint]
    //[/UserPrePaint]

    //[UserPaint]
		Colour fillColor = Colours::white;
		Colour textColor = Colours::black;
		if (highlighted) {
			if (step->isEmpty()) {
				fillColor = Colours::dimgrey;
				textColor = Colours::black;
			}
			else {
				fillColor = Colours::black;
				textColor = Colours::white;
			}
		}
		else if (!(step->isEmpty())) {
			// DBG("I'M NOT EMPTY?");
			fillColor = Colours::skyblue;
		}

		stepButton.setColour(TextButton::buttonColourId, fillColor);
		stepButton.setColour(TextButton::textColourOnId, textColor);
		stepButton.setColour(TextButton::textColourOffId, textColor);

		g.fillAll(Colours::green);

		//g.setColour(Colours::black);

		//g.drawRect(0, 0, getWidth(), getHeight());
		if (!step->isEmpty()) {
			stepButton.setButtonText("DUR: " + std::to_string(step->getStepsUntilNoteOff()) + "\n"
				+ "NOTE: " + std::to_string(step->getNoteOn().getMidiNote()));
		}
		else {
			stepButton.setButtonText("");
		}

    //[/UserPaint]
}

void StepComponent::storePatternReference(Pattern* p) {
	pattern = p;
}

void StepComponent::buttonClicked(Button * button)
{
	if (step->isEmpty()) {
		pattern->addStep(stepNumber, new Step(Note(random.nextInt(10) + 60), 1));
	}
	else {
		pattern->clearStep(stepNumber);
	}
	DBG("ive been cliked");
	repaint();
}

void StepComponent::resized()
{
    //[UserPreResize] 
    //[/UserPreResize]
    //[UserResized] 
	stepButton.setBounds(0, 0, getWidth(), getHeight());
    //[/UserResized]
}

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
