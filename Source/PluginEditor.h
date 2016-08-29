/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class BeatboxVoxAudioProcessorEditor  : public AudioProcessorEditor, 
                                        private ButtonListener,
                                        private Timer

{
public:
    BeatboxVoxAudioProcessorEditor (BeatboxVoxAudioProcessor&);
    ~BeatboxVoxAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback() override;

    void buttonClicked(Button* button) override;

private:
    BeatboxVoxAudioProcessor& getProcessor() const
    {
        return static_cast<BeatboxVoxAudioProcessor&> (processor);
    }

    //JWM - Test button to swich on classifier training for sound
    std::unique_ptr<TextButton> trainClassifierButton;

    OwnedArray<Button> soundButtons;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BeatboxVoxAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
