#include "MainComponent.h"

/*
	The MainComponent is a subclass of AudioAppComponent, and thus
	it handles all of the audio processing done in the other components
	via their AudioSources, which are backpropagated here.

	Additionally, this class also hosts multiple ChannelComponents,
	which in turn house a Sampler and Sequencer. Pretty much anything
	that is seen on the screen is a child component of this object.
*/

MainComponent::MainComponent()
{
	for (int i = 0; i < numberOfChannels; i++) {
		//  instantiate our channels
		channels.add(new ChannelComponent());

		if (i == currentChannel) {
			// if our current channel is the one we're currently looking at,
			// we need to make it visible
			addAndMakeVisible(channels[i]);
		}
		else {
			// since this channel isn't the current channel, we
			// can just add it as a child and not show it just yet
			// to save on performance overhead!
			addChildComponent(channels[i]);
		}
		// adds channel as a listener to our beat triggered event!
		beatTimer.addActionListener(channels[i]);

		// adds our channel as an input source to our mixer
		mixer.addInputSource(channels[i]->getSamplerComponent()->getAudioSource(), false);
	}

	// initialize our beatTimer with a default BPM of 120 (common value) and start it
	beatTimer.setBPM(50.0);
	beatTimer.startTimerByBPM();

    setSize (1280, 720);

    // how many channels our device has (2 by default)
	setAudioChannels(2, 2);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // when the audio device starts, this function is called. so we need to
	// call this same method on all of our AudioSources, which is handled by
	// our MixerAudioSource, which calls it on all conected AudioSources

	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	// passes our buffer to the various AudioSources connected to our mixer
	mixer.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
	// this gets called when our Audio device closes
	mixer.releaseResources();
}

void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, as it doesn't hold any visuals of its own,
	// so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
}

void MainComponent::resized()
{
	for (ChannelComponent *c : channels) {
		// when the parent component is resized, we need to tell the subcomponents
		// to recalculate their bounds as well
		c->setBounds(getLocalBounds());
	}
}
