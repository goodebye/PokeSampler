#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "LoopableSamplerVoice.h"
#include "Note.h"
//[/Headers]

class SamplerComponent  : public Component
{
public:
     SamplerComponent ();
    ~SamplerComponent();

    //[UserMethods]
	SamplerAudioSource* getAudioSource();
	void noteOn(Note note);
	void noteOff(Note note);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
private:
    //[UserVariables]
	Synthesiser* synth;
	SamplerAudioSource samplerSource;
    //[/UserVariables]    

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerComponent)
};