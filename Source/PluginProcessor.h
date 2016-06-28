/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/
#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <atomic>
#include "mlpack/core.hpp"
#include "mlpack/methods/naive_bayes/naive_bayes_classifier.hpp"
#include "Gist/src/Gist.h"
#include "OnsetDetection/OnsetDetector.h"

using namespace mlpack::naive_bayes;
using namespace arma;


//==============================================================================
/**
*/
class BeatboxVoxAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    BeatboxVoxAudioProcessor();
    ~BeatboxVoxAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //JWM - Test function to get spectral centroid value in GUI
    float getSpectralCentroid() const;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BeatboxVoxAudioProcessor);

    //Onset Detector object for peak picking.
    OnsetDetector onsetDetector;
    
    //Vector to hold mag spectrum
    std::vector<float> magSpectrum;

    //Gist audio feature extraction / analysis objects.
    Gist<float> gistMFCC;
    Gist<float> gistOnset;
    
    //Previous spectral difference value for last audio frame
    float prevSpecDiff = 0.0;

    NaiveBayesClassifier<> nbc;
    std::atomic<float> spectralCentroid;

    //Test matrix for prototyping - 3 rows (2 features and last row for labels) - 2 cols (2 instances)
    fmat::fixed<3, 2> testMatrix;
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
