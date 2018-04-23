//[Headers] 
//[/Headers]

#include "SamplerComponent.h"

SamplerComponent::SamplerComponent ()
{
    //[Constructor_pre]
	synth = samplerSource.getSynth();
    //[/Constructor_pre]

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] 
    //[/Constructor]
}

SamplerComponent::~SamplerComponent()
{
    //[Destructor_pre]. 
    //[/Destructor_pre]

    //[Destructor]. 
    //[/Destructor]
}

SamplerAudioSource* SamplerComponent::getAudioSource() {
	return &samplerSource;
}

void SamplerComponent::noteOn(Note note)
{
	synth->noteOn(1, note.midiNote, 127);
}

void SamplerComponent::noteOff(Note note)
{
	synth->noteOn(1, note.midiNote, 127);
}

void SamplerComponent::paint (Graphics& g)
{
    //[UserPrePaint]
    //[/UserPrePaint]

    g.fillAll (Colours::skyblue);

    //[UserPaint]
    //[/UserPaint]
}

void SamplerComponent::resized()
{
    //[UserPreResize] 
    //[/UserPreResize]

    //[UserResized] 
    //[/UserResized]
}
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SamplerComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif