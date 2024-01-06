/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once
#include "DSP.h"
#include <JuceHeader.h>

class MaestroAudioProcessor : public ParameterizedAudioProcessor
{
public:
    //==============================================================================
    MaestroAudioProcessor ();
    ~MaestroAudioProcessor () override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override
    {
        dsp->setTotalNumInputChannels (getTotalNumInputChannels());
        dsp->setTotalNumOutputChannels (getTotalNumOutputChannels());
        dsp->prepare (sampleRate, samplesPerBlock);
    }
    
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
    {
        dsp->processBlock (buffer, midiMessages);
    }
    //==============================================================================

    juce::AudioProcessorEditor* createEditor () override;
    std::vector<ParamInfo> getParamInfo () override;
    
    DSP& getDSP() { return *dsp.get(); }

private:

    std::unique_ptr<DSP> dsp;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MaestroAudioProcessor)
};
