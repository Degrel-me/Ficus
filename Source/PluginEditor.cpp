#include "PluginProcessor.h"
#include "PluginEditor.h"

Ficus_VST3AudioProcessorEditor::Ficus_VST3AudioProcessorEditor(Ficus_VST3AudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p) {
    setSize(400, 300);
}

Ficus_VST3AudioProcessorEditor::~Ficus_VST3AudioProcessorEditor() {}

void Ficus_VST3AudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawText("Ficus_VST3 - Music Editor", getLocalBounds(), juce::Justification::centred);
}

void Ficus_VST3AudioProcessorEditor::resized() {}