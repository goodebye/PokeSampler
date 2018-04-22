//[Headers]
//[/Headers]

#include "ChannelComponent.h"


//[MiscUserDefs]
//[/MiscUserDefs]

//==============================================================================
ChannelComponent::ChannelComponent ()
{
    //[Constructor_pre]
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (getWidth(), getHeight());


    //[Constructor] You can add your own custom stuff here..
	addAndMakeVisible(sequencer);

	DBG("I'm a channel and I've been created!");
    //[/Constructor]
    //[/Constructor]
}

ChannelComponent::~ChannelComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

void ChannelComponent::computePadding()
{
	SequencerPadding sp = SequencerPadding();
	sp.padX = getWidth() / padFactor;
	sp.padY = sp.padX;
	padding = sp;
}

//==============================================================================
void ChannelComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::skyblue);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ChannelComponent::resized()
{
	//[UserPreResize] Add your own custom resize )code here..
	//[/UserPreResize]
	computePadding();
	sequencer.setBounds(0 + padding.padX, getHeight() / 2 + padding.padY, getWidth() - padding.padX * 2, getHeight() / 2 - padding.padY * 2);
	
	DBG(sequencer.getBounds().getX() << ", " << sequencer.getBounds().getY() << "\n");


    //[UserResized] Add your own custom resize handling here..
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

<JUCER_COMPONENT documentType="Component" className="ChannelComponent" componentName=""
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
