/*
	POKESAMPLER v0.1!

	by several great people
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

class PokeSamplerApplication  : public JUCEApplication
{
public:
    PokeSamplerApplication() {}

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    void initialise (const String& commandLine) override
    {
        // this method instantiates a window with our application name

        mainWindow = new MainWindow (getApplicationName());
    }

    void shutdown() override
    {
        // shutdown code to avoid memory leaks

        mainWindow = nullptr; // (deletes our window)
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {
		// because this is a pure virtual function we are required to handle an override
		// but! since we don't need to account for this case, we're leaving it blank
    }

    /*
        This class implements the desktop window that contains an instance of
        our MainComponent class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow (String name)  : DocumentWindow (name,
                                                    Desktop::getInstance().getDefaultLookAndFeel()
                                                                          .findColour (ResizableWindow::backgroundColourId),
                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, true);

            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

		void closeButtonPressed() override
		{
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    ScopedPointer<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (PokeSamplerApplication)
