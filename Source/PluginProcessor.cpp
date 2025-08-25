#include "PluginProcessor.h"
#include "PluginEditor.h"

Ficus_VST3AudioProcessor::Ficus_VST3AudioProcessor() {}
Ficus_VST3AudioProcessor::~Ficus_VST3AudioProcessor() {}

void Ficus_VST3AudioProcessor::prepareToPlay([[maybe_unused]] double sampleRate, [[maybe_unused]] int samplesPerBlock) {}
void Ficus_VST3AudioProcessor::releaseResources() {}
void Ficus_VST3AudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, [[maybe_unused]] juce::MidiBuffer& midiMessages) {
    buffer.clear(); // Пример: очистка буфера
}

juce::AudioProcessorEditor* Ficus_VST3AudioProcessor::createEditor() {
    return new Ficus_VST3AudioProcessorEditor(*this);
}

// Регистрация плагина
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Ficus_VST3AudioProcessor();
}