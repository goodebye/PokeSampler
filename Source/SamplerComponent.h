#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "LoopableSamplerVoice.h"
#include "Note.h"
//[/Headers]

class SamplerComponent  : public Component, Button::Listener
{
public:
     SamplerComponent ();
    ~SamplerComponent();

    //[UserMethods]
	SamplerAudioSource* getAudioSource();
	void noteOn(Note note);
	void noteOff(Note note);
	void buttonClicked(Button* button) override;
	File getSampleToLoad();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
private:
    //[UserVariables]
	Synthesiser* synth;
	TextButton chooseFileButton;
	Random random;
	SamplerAudioSource samplerSource;
    //[/UserVariables]    

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerComponent)
};