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

		// adds buttons to select channel
		TextButton* channelButton = new TextButton();
		channelButton->setButtonText("#" + std::to_string(i + 1));
		channelButton->addListener(this);

		if (i == currentChannel) {
			channelButton->setColour(TextButton::buttonColourId, Colours::white);
			channelButton->setColour(TextButton::textColourOnId, Colours::black);
			channelButton->setColour(TextButton::textColourOffId, Colours::black);

		}
		else {
			channelButton->setColour(TextButton::buttonColourId, Colours::black);
			channelButton->setColour(TextButton::textColourOnId, Colours::white);
			channelButton->setColour(TextButton::textColourOffId, Colours::white);
		}

		addAndMakeVisible(channelButton);

		channelSelectorButtons.add(channelButton);

		// adds our channel as an input source to our mixer
		mixer.addInputSource(channels[i]->getSamplerComponent()->getAudioSource(), false);
	}

	// initialize connected MIDI controllers

	// find all connected MIDI devices
	auto midiInputs = MidiInput::getDevices();
	

	for (auto midiInput : midiInputs) {
		// enable midi device if it isn't already
		if (!deviceManager.isMidiInputEnabled(midiInput)) {
			deviceManager.setMidiInputEnabled(midiInput, true);
		}
		// add our device to trigger callback
		deviceManager.addMidiInputCallback(midiInput, this);

		DBG(midiInput << " is now connected");
	}

	// initialize our beatTimer with a default BPM of 120 (common value) and start it
	beatTimer.setBPM(120);
	beatTimer.startTimerByBPM();
	beatTimer.addActionListener(this);

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

void MainComponent::actionListenerCallback(const String &message) {
	if (recording) {
		recordingNote->duration = recordingNote->duration + 1;
		lastBeatTime = Time::currentTimeMillis();
	}
}


void MainComponent::resized()
{
	for (ChannelComponent *c : channels) {
		// when the parent component is resized, we need to tell the subcomponents
		// to recalculate their bounds as well
		c->setBounds(0, getHeight() / 40, getWidth(), getHeight() - getHeight() / 30);
	}

	int buttonNumber = 0;
	int numberOfButtons = channelSelectorButtons.size();

	for (Button* button : channelSelectorButtons) {
		button->setBounds(getWidth() / numberOfButtons * buttonNumber, 0, 
			getWidth() / numberOfButtons, getHeight() / 30);
		buttonNumber++;
	}
}

int MainComponent::noteNumberToChannel(int noteNumber)
{
	return noteNumber - channelKeyStart;
}

void MainComponent::toggleRecording() {
	if (recording) {
		stopRecording();
	}
	else {
		beginRecording();
	}
}

void MainComponent::beginRecording() {
	recording = true;
	startPlaying();
}

void MainComponent::stopRecording() {
	recording = false;
}

void MainComponent::togglePlaying() {
	if (beatTimer.isTimerRunning()) {
		stopPlaying();
	}
	else {
		startPlaying();
	}
}

void MainComponent::startPlaying() {
	if (!beatTimer.isTimerRunning()) {
		beatTimer.startTimerByBPM();
	}
}

void MainComponent::stopPlaying() {
	const MessageManagerLock mmLock;

	if (beatTimer.isTimerRunning()) {
		for (ChannelComponent* c : channels) {
			c->restartSequencer();
		}
		beatTimer.stopTimer();
	}

	if (recording) {
		stopRecording();
	}
}

void MainComponent::buttonClicked(Button * button) {
	int channel = 0;

	for (Button* b : channelSelectorButtons) {
		if (b == button) {
			setActiveChannel(channel);
		}
		channel++;
	}
}

void MainComponent::setActiveChannel(int channelNumber) {

	if (recording) {
		if (!recordingNote->noData) {
			getActiveChannel()->midiNoteOff(Note(recordingNote->note->getMidiNote()));
			getActiveChannel()->addStepToSequencer(recordingNote->startStep,
				Note(recordingNote->note->getMidiNote()), recordingNote->duration);
		}
		else {
			recordingNote = new RecordingNote();
		}

		recording = false;
	}
	channels[currentChannel]->setVisible(false);
	currentChannel = channelNumber;
	channels[currentChannel]->setVisible(true);

	for (int i = 0; i < channelSelectorButtons.size(); i++) {
		Button* b = channelSelectorButtons[i];

		if (i == currentChannel) {
			b->setColour(TextButton::buttonColourId, Colours::white);
			b->setColour(TextButton::textColourOnId, Colours::black);
			b->setColour(TextButton::textColourOffId, Colours::black);
		}
		else {
			b->setColour(TextButton::buttonColourId, Colours::black);
			b->setColour(TextButton::textColourOnId, Colours::white);
			b->setColour(TextButton::textColourOffId, Colours::white);
		}
	}
}

ChannelComponent * MainComponent::getActiveChannel()
{
	return channels[currentChannel];
}

void MainComponent::handleIncomingMidiMessage(MidiInput * source, const MidiMessage & message)
{
	if (message.isNoteOn()) {
		int noteNumber = message.getNoteNumber();

		if (noteIsOnKeyboard(noteNumber)) {
			if (recording) {
				int64 delta = Time::currentTimeMillis() - lastBeatTime;
				int offset = 0;

				if (delta < beatTimer.getTimerInterval() / 3 * 2) {
					offset = 1;
				}
				int stepToPlace = Util::wrappingModulo(getActiveChannel()->getCurrentStepFromSequencer() - offset,
					getActiveChannel()->getSequencerComponent()->getNumberOfSteps());
				getActiveChannel()->midiNoteOn(Note(message.getNoteNumber()));
				recordingNote = new RecordingNote(new Note(message.getNoteNumber()), 0, stepToPlace);
			}
			getActiveChannel()->midiNoteOn(Note(message.getNoteNumber()));
			return;
		}
		else if (noteIsReservedNote(noteNumber)) {
			if (noteNumber == TransportKeys::PLAY_TOGGLE) {
				// then we activate/deactivate the timer to stop/start playback!
				togglePlaying();
			}
			else if (noteNumber == TransportKeys::RECORD) {
				// send record message to current channel
				toggleRecording();
			}
			else {
				// otherwise, our note is a channel select (for now)
				const MessageManagerLock mmLock;
				setActiveChannel(noteNumberToChannel(noteNumber));
			}
		}
		DBG(" note on: " << message.getNoteNumber());
	}
	if (message.isNoteOff()) {
		int noteNumber = message.getNoteNumber();

		if (noteIsOnKeyboard(noteNumber)) {
			// then we are either changing which channel is active or we are stopping/starting/recording
			if (recording) {

				int64 delta = Time::currentTimeMillis() - lastBeatTime;
				int offset = 0;

				if (recordingNote->duration == 0) {
					recordingNote->duration = 1;
				}
				else if (delta < beatTimer.getTimerInterval() && recordingNote->duration != 0) {
					offset = 1;
				}
					getActiveChannel()->midiNoteOff(Note(message.getNoteNumber()));
					getActiveChannel()->addStepToSequencer(recordingNote->startStep,
						Note(recordingNote->note->getMidiNote()), recordingNote->duration);
			}
			getActiveChannel()->midiNoteOff(Note(message.getNoteNumber()));
			return;
		}
	}
}

bool MainComponent::noteIsReservedNote(int note) {
	if (note >= channelKeyStart && note <= channelKeyStart + numberOfChannels) {
		return true;
	}
	if (transportKeySet.count(note) > 0) {
		return true;
	}

	return false;
}

bool MainComponent::noteIsOnKeyboard(int note) {
	if (note > 35 && note < 69) {
		return true;
	}
	return false;
}

void MainComponent::handleNoteOn(MidiKeyboardState *, int midiChannel, int midiNoteNumber, float velocity)
{
	DBG("GOT NOTE " << midiNoteNumber);
}

void MainComponent::handleNoteOff(MidiKeyboardState *, int midiChannel, int midiNoteNumber, float velocity)
{

}
