#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
	// you add any child components.

	for (int i = 0; i < numberOfChannels; i++) {
		channels.add(new ChannelComponent());
		if (i == currentChannel) {
			addAndMakeVisible(channels[i]);
		}
		else {
			addChildComponent(channels[i]);
		}
		beatTimer.addActionListener(channels[i]);
		mixer.addInputSource(channels[i]->getSamplerComponent()->getAudioSource(), false);
	}

	beatTimer.setBPM(120.0);
	beatTimer.startTimerByBPM();

    setSize (1280, 720);

    // specify the number of input and output channels that we want to open
	setAudioChannels(2, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.
	mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);

}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!
	mixer.getNextAudioBlock(bufferToFill);
    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
	mixer.releaseResources();
}

void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

    // You can add your drawing code here!
}

void MainComponent::resized()
{
	for (ChannelComponent *c : channels) {
		c->setBounds(getLocalBounds());
	}
}
