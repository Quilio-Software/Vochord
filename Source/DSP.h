#pragma once
#include <JuceHeader.h>
#include "MidiTranslator.h"
using namespace juce;

class DSP : public DSPBase
{
    MidiTranslator midiTranslator;
public:
    
    DSP (ParameterizedAudioProcessor* _processor)
    {
    }
    
    void initialize()
    {
    }
    
    void prepare (double sampleRate, int samplesPerBlock)
    {
    }
    
    std::vector<ParameterizedAudioProcessor::ParamInfo> getParamInfo ()
    {
        return
        {
        };
    }
    
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
    {
        juce::ScopedNoDenormals noDenormals;
        juce::dsp::AudioBlock<float> block (buffer);
        juce::dsp::ProcessContextReplacing<float> context (block);
        for (auto i = numInputChannels; i < numOutputChannels; ++i)
            buffer.clear (i, 0, buffer.getNumSamples());
        
        midiTranslator.process (midiMessages);
    }
};
