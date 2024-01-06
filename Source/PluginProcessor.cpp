/*
 ==============================================================================
 
 This file contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MaestroAudioProcessor::MaestroAudioProcessor() : ParameterizedAudioProcessor()

{
    init();
    dsp = std::make_unique<DSP> (this);
    dsp->initialize();
} 

MaestroAudioProcessor::~MaestroAudioProcessor()
{
}

std::vector<ParameterizedAudioProcessor::ParamInfo> MaestroAudioProcessor::getParamInfo ()
{    
    return dsp->getParamInfo();
}

juce::AudioProcessorEditor* MaestroAudioProcessor::createEditor()
{
    auto editor = new MaestroAudioProcessorEditor (*this, *parameters, undoManager);
    
#ifdef SET_ROUNDED_WINDOW_CORNERS
    if (wrapperType == wrapperType_Standalone)
    {
        if (TopLevelWindow::getNumTopLevelWindows () == 1)
        {
            TopLevelWindow* w = TopLevelWindow::getTopLevelWindow (0);
            w->setUsingNativeTitleBar (true);
            
#if JUCE_WINDOWS || JUCE_MAC
            if (editor->getApplicationWindowRounded())
                if (auto peer = editor->getPeer ())
                    setRoundedCorners (peer->getNativeHandle (), false);
#endif
        }
    }
#endif
    
    return editor;
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MaestroAudioProcessor();
}
