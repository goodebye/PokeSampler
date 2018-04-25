//[Headers]
#include "Util.h"
#include <math.h>
//[/Headers]

#include "SequencerComponent.h"
#include <utility>

SequencerComponent::SequencerComponent ()
{
    //[Constructor_pre]
	// we initialize our pattern to empty Steps
	pattern.initializePattern();

	// for each of the steps...
	for (int stepNum = 0; stepNum < 16; stepNum++) {
		if (stepNum % 2 == 0) {
			int noteValue = random.nextInt(20) + 64;

			Step* newStep = new Step(Note(noteValue), 1);
			pattern.addStep(stepNum, newStep);
		}
		else {
			pattern.addStep(stepNum, new Step());
		}

		// create new step component
		StepComponent* sc = new StepComponent();

		// set our step number for display
		sc->setStepNumber(stepNum);
		// add reference to step to our StepComponent
		sc->setStep(pattern.getStep(stepNum));
		// add reference to pattern
		sc->storePatternReference(&pattern);

		// add stepComponent to our container of components for later reference
		stepComponents.add(sc);
		// add as child and display
		addAndMakeVisible(sc);
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

		// since we're splitting our steps across multiple rows,
		// this is robust code for calculating position based on 
		// arbitrary rows, columns, and so on.

		int stepsPerRow = pattern.getNumberOfSteps() / rows;
		int w = getWidth() / stepsPerRow;
		int h = getHeight() / rows;
		int padding = getWidth() / 30;

		int stepNum = 0;
		
		// for each step component...
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
	repaint();
}

std::pair<Note*, Note*> SequencerComponent::trigger()
{
	int stepToPlay = currentStepNumber;
	activateStepComponent(currentStepNumber);
	deactivateStepComponent(previousStepNumber());
	currentStepNumber = nextStepNumber();
	//repaint();
	return pattern.noteEventsAtStep(stepToPlay);
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
