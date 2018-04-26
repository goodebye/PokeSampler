//[Headers] 
//[/Headers]

#include "SamplerComponent.h"

/*
	Our SamplerComponent holds our sampler audio source as well as
	displays vital information about the sample.
*/

SamplerComponent::SamplerComponent() : thumbnailCache(5), thumbnail(2048, formatManager, thumbnailCache)
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
			
			thumbnail.setSource(new FileInputSource(f));
			repaint();
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

	Rectangle<int> thumbnailBounds(getWidth() / 7, getHeight() / 7, getWidth() - getWidth() / 2, getHeight() / 5 * 4);

	g.setColour(Colours::red);                                   
	thumbnail.drawChannels(g,                                    
		thumbnailBounds,
		0.0,                                    // start time
		thumbnail.getTotalLength(),             // end time
		1.0f);                                  // vertical zoom

    //[UserPaint]
    //[/UserPaint]
}

void SamplerComponent::resized()
{
    //[UserPreResize] 
    //[/UserPreResize]

    //[UserResized] 
	chooseFileButton.setBounds(0 + getHeight() / 10, 0 + getHeight() / 7, getWidth() / 15, getHeight() / 5 * 4);
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