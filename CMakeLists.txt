cmake_minimum_required(VERSION 3.15)
project(Ficus_VST3 VERSION 1.0.0)

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_C_FLAGS_DEBUG: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "Configuring Ficus_VST3 plugin")

# Путь к JUCE
set(JUCE_DIR "C:/Users/step4/Documents/JUCE")
message(STATUS "JUCE_DIR: ${JUCE_DIR}")

# Проверка существования JUCE
if(NOT EXISTS "${JUCE_DIR}")
    message(FATAL_ERROR "JUCE directory not found at ${JUCE_DIR}. Please ensure JUCE is installed correctly.")
endif()

# Добавление JUCE
add_subdirectory(${JUCE_DIR} JUCE)

# Переопределяем флаги JUCE для предотвращения конфликта /Zi и /Z7
set_target_properties(juce_recommended_config_flags PROPERTIES
        COMPILE_OPTIONS ""
        INTERFACE_COMPILE_OPTIONS ""
)

# Определение плагина
juce_add_plugin(Ficus_VST3
        VERSION 1.0.0
        COMPANY_NAME "YourCompany"
        PLUGIN_NAME "Ficus_VST3"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT TRUE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        FORMATS VST3
        PRODUCT_NAME "Ficus_VST3"
        VST3_CATEGORIES "Fx"
        PLUGIN_CODE "Fics"
        MANUFACTURER_CODE "Yrco"
)

# Исходные файлы
target_sources(Ficus_VST3
        PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp
        ${JUCE_DIR}/modules/juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp
)

# Макросы компиляции
target_compile_definitions(Ficus_VST3
        PRIVATE
        JUCE_VST3_CAN_REPLACE_VST2=0
        JucePlugin_Build_VST=0
        JucePlugin_Build_AAX=0
        JucePlugin_Build_AU=0
        JucePlugin_Build_AUv3=0
        JucePlugin_Build_LV2=0
        JucePlugin_Build_Standalone=0
        JucePlugin_Build_Unity=0
        JUCE_MODAL_LOOPS_PERMITTED=1
)

# Линковка с модулями JUCE
target_link_libraries(Ficus_VST3
        PRIVATE
        juce::juce_audio_utils
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_basics
        juce::juce_core
        juce::juce_dsp
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# Явная линковка для VST3
target_link_libraries(Ficus_VST3
        PRIVATE
        Ficus_VST3_SharedCode
        juce::juce_audio_plugin_client
)

# Настройки для MSVC
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /EHsc /MP" CACHE STRING "Debug flags" FORCE)
    set(CMAKE_C_FLAGS_DEBUG "/Zi /Od" CACHE STRING "Debug flags" FORCE)
    string(REGEX REPLACE "/Z7" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
    string(REGEX REPLACE "/Z7" "" CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
    string(REGEX REPLACE "/Z7" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "/Z7" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    target_compile_options(Ficus_VST3 PRIVATE /Zi /EHsc /MP /Od)
    target_link_options(Ficus_VST3 PRIVATE /DEBUG /DLL)
endif()

# Путь для вывода плагина
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Ficus_VST3_artefacts/Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Ficus_VST3_artefacts/Debug")

# Явно задаём выходной путь и имя для VST3
set_target_properties(Ficus_VST3 PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Ficus_VST3_artefacts/Debug"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Ficus_VST3_artefacts/Debug"
        OUTPUT_NAME "Ficus_VST3"
        SUFFIX ".vst3"
)

# Диагностика линковки
message(STATUS "Linking Ficus_VST3 as shared library")