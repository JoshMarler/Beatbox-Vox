/*
  ==============================================================================

    OnsetDetector.h
    Created: 28 Jun 2016 6:40:26pm
    Author:  joshua

  ==============================================================================
*/

#ifndef ONSETDETECTOR_H_INCLUDED
#define ONSETDETECTOR_H_INCLUDED

#include <atomic>
#include "../AudioClassifyOptions/AudioClassifyOptions.h"
#include "../../MathHelpers/MathHelpers.h"
#include "../../Gist/src/onset-detection-functions/OnsetDetectionFunction.h"


template<typename T>
class OnsetDetector
{
    public:
        OnsetDetector(int bufferSize);
        ~OnsetDetector();
        
        bool checkForOnset(T featureValue);

        void setUsingLocalMaximum(bool newUsingLocalMaximum);
        bool getUsingLocalMaximum();
        
        void setCurrentODFType(AudioClassifyOptions::ODFType newODFType);
        
    private:
       int numPreviousValues;
       bool usingLocalMaximum;      
       
       T threshold;
       T meanCoeff;

       std::vector<T> previousValues;

       std::unique_ptr<OnsetDetectionFunction<T>> onsetDetectionFunction;

       std::atomic<AudioClassifyOptions::ODFType> currentODFType {AudioClassifyOptions::ODFType::spectralDifference};
};



#endif  // ONSETDETECTOR_H_INCLUDED
