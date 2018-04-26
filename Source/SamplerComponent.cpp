//[Headers] 
//[/Headers]

#include "SamplerComponent.h"

/*
	Our SamplerComponent holds our sampler audio source as well as
	displays vital information about the sample.
*/

SamplerComponent::SamplerComponent ()
{
    //[Constructor_pre]
	synth = samplerSource.getSynth();
	addAndMakeVisible(chooseFileButton);
	chooseFileButton.setButtonText("SELECT FILE");
	chooseFileButton.setColour(TextButton::buttonColourId, Colours::black);
	chooseFileButton.addListener(this);
	formatManager.registerBasicFormats();
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
	// send noteOn message to our synth
	synth->noteOn(1, note.getMidiNote(), 1);
}

void SamplerComponent::noteOff(Note note)
{
	// send noteOff message to our synth
	synth->noteOff(1, note.getMidiNote(), 0, true);
}

void SamplerComponent::buttonClicked(Button * button)
{

	if (button == &chooseFileButton) {

		FileChooser sampleChooser("choose the sample you want to load!",
			File::getSpecialLocation(File::userHomeDirectory),
			"*.wav");

		if (sampleChooser.browseForFileToOpen())
		{
			File f = sampleChooser.getResult();
			samplerSource.setUsingSampleSound(f);
			
			WavAudioFormat wavFormat;

			InputStream* is = f.createInputStream();
		}
	}
}

void SamplerComponent::reset() {
	samplerSource.reset();
}
void SamplerComponent::paint (Graphics& g)
{
    //[UserPrePaint]
    //[/UserPrePaint]

    g.fillAll (Colours::black);
	g.setColour(Colours::white);
	g.drawRect(0, 0, getWidth(), getHeight(), 3);

    //[UserPaint]
    //[/UserPaint]
}

void SamplerComponent::resized()
{
    //[UserPreResize] 
    //[/UserPreResize]

    //[UserResized] 
	chooseFileButton.setBounds(0 + 15, 0 + 15, getWidth() / 15, getWidth() / 25);
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