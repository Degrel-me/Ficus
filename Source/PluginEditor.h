#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"

class Ficus_VST3AudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit Ficus_VST3AudioProcessorEditor(Ficus_VST3AudioProcessor&);
    ~Ficus_VST3AudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    Ficus_VST3AudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Ficus_VST3AudioProcessorEditor)
};