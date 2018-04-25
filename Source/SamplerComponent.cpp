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
	chooseFileButton.setColour(Label::backgroundColourId, Colours::magenta);
	chooseFileButton.setColour(Label::textColourId, Colours::black);
	chooseFileButton.addListener(this);
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
	synth->noteOn(1, note.getMidiNote(), note.getVelocity());
}

void SamplerComponent::noteOff(Note note)
{
	// send noteOff message to our synth
	DBG("I RAN");

	synth->noteOff(1, note.getMidiNote(), 0, false);
}

void SamplerComponent::buttonClicked(Button * button)
{
	DBG("I RAN");

	if (button == &chooseFileButton) {
		File f = getSampleToLoad();

		if (f.existsAsFile()) {
			samplerSource.setUsingSampleSound(f);
		}
	}
}

File SamplerComponent::getSampleToLoad() {
	FileChooser sampleChooser("choose the sample you want to load!",
		File::getSpecialLocation(File::userHomeDirectory),
		"*.wav");
	DBG("I RAN TOO");
	if (sampleChooser.browseForFileToOpen())
	{
		File f = sampleChooser.getResult();
		return f;
	}
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