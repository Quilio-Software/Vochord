#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MaestroAudioProcessorEditor::MaestroAudioProcessorEditor (ParameterizedAudioProcessor& p, juce::AudioProcessorValueTreeState& vts, juce::UndoManager& um)
: PluginEditor (p, vts, um)
{    
    editorScaledComponent = std::make_unique<CustomUserInterface>(p, vts, um);
    initialize (2928, 1832);
}
