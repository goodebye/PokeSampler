//[Headers]
#include "Util.h"
#include <math.h>
//[/Headers]

#include "SequencerComponent.h"

SequencerComponent::SequencerComponent ()
{
    //[Constructor_pre]
	pattern.initializePattern();

	int stepNum = 0;

	for (Step step : pattern.getSteps()) {
		DBG("NEW STEP CREATED");
		if (stepNum % 2 == 0) {
			step.setNoteOn(Note(60));
		}
		else {
			step.setNoteOff(Note(60));
		}
		StepComponent* sc = new StepComponent();
		sc->setStepNumber(stepNum);
		sc->setStep(&step);

		stepComponents.add(sc);
		addAndMakeVisible(sc);

		stepNum++;
	}
    //[/Constructor_pre]

    //[UserPreSize]
    //[/UserPreSize]

    setSize (0, 0);

    //[Constructor]
    //[/Constructor]
}

SequencerComponent::~SequencerComponent()
{
    //[Destructor_pre].
    //[/Destructor_pre]
    //[Destructor].
    //[/Destructor]
}

void SequencerComponent::paint(Graphics& g)
{
	//[UserPrePaint]
	//[/UserPrePaint]

	g.fillAll(Colours::white);

	//[UserPaint]
	//[/UserPaint]
}

void SequencerComponent::resized() {
    //[UserPreResize] 
    //[/UserPreResize]

    //[UserResized] 
	if (isVisible()) {
		int stepsPerRow = pattern.getNumberOfSteps() / rows;
		int w = getWidth() / stepsPerRow;
		int h = getHeight() / rows;
		int padding = getWidth() / 30;

		int stepNum = 0;

		for (Component* sc : stepComponents) {
			int row = floor(stepNum / stepsPerRow);
			int col = stepNum % stepsPerRow;

			Point<double> topLeft;
			topLeft.setX(col * w);
			topLeft.setY(row * h);

			Point <double> bottomRight;
			bottomRight.setX(w);
			bottomRight.setY(h);

			sc->setBounds(topLeft.getX() + padding / 4, topLeft.getY() + padding / 4, w - padding / 2, h - padding / 2);
			stepNum++;
		}
	}
    //[/UserResized]
}

void SequencerComponent::visibilityChanged()
{
	resized();
}

Step SequencerComponent::trigger()
{
	activateStepComponent(currentStepNumber);
	deactivateStepComponent(previousStepNumber());
	currentStepNumber = nextStepNumber();
	repaint();
	return Step();
}

void SequencerComponent::activateStepComponent(int stepNumber)
{
	stepComponents[stepNumber]->activate();
}

void SequencerComponent::deactivateStepComponent(int stepNumber)
{
	stepComponents[stepNumber]->deactivate();
}

int SequencerComponent::previousStepNumber() 
{
	return Util::wrappingModulo(currentStepNumber - 1, pattern.getNumberOfSteps());
}

int SequencerComponent::nextStepNumber() {
	return Util::wrappingModulo(currentStepNumber + 1, pattern.getNumberOfSteps());
}

//[MiscUserCode] 
//[/MiscUserCode]


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
