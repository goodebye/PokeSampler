//[Headers]
//[/Headers]

#include "ChannelComponent.h"

ChannelComponent::ChannelComponent ()
{
    //[Constructor_pre]
    //[/Constructor_pre]

    //[UserPreSize]
    //[/UserPreSize]

    setSize (getWidth(), getHeight());

    //[Constructor]
	addAndMakeVisible(sequencer);
	addAndMakeVisible(samplerComponent);

	DBG("I'm a channel and I've been created!");
    //[/Constructor]
}

ChannelComponent::~ChannelComponent()
{
    //[Destructor_pre].
    //[/Destructor_pre]
    //[Destructor].	
    //[/Destructor]
}

void ChannelComponent::computePadding()
{
	SequencerPadding sp = SequencerPadding();
	sp.padX = getWidth() / padFactor;
	sp.padY = sp.padX;
	padding = sp;
}

void ChannelComponent::actionListenerCallback(const String & message)
{
	Step s = sequencer.trigger();
	int noteValue = random.nextInt(10) + 50;
	Note testNote = Note(noteValue);
	samplerComponent.noteOff(Note(noteToTurnOff));
	samplerComponent.noteOn(testNote);
	//samplerComponent.noteOff(Note(noteToTurnOff));
	noteToTurnOff = noteValue;
}

SamplerComponent * ChannelComponent::getSamplerComponent()
{
	return &samplerComponent;
}

void ChannelComponent::paint (Graphics& g)
{
    //[UserPrePaint]
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint]
    //[/UserPaint]
}

void ChannelComponent::resized()
{
	//[UserPreResize]
	//[/UserPreResize]

    //[UserResized]
	computePadding();
	sequencer.setBounds(0 + padding.padX, getHeight() / 2 + padding.padY, getWidth() - padding.padX * 2, getHeight() / 2 - padding.padY * 2);
	samplerComponent.setBounds(0 + padding.padX, 0 + padding.padY, getWidth() - padding.padX * 2, getHeight() / 2 - padding.padY * 2);

	DBG(sequencer.getBounds().getX() << ", " << sequencer.getBounds().getY() << "\n");
    //[/UserResized]
}

//[MiscUserCode] 
//[/MiscUserCode]

#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ChannelComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
