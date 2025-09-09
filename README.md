# Ficus_VST3

## Overview (概述)
Ficus_VST3 is an open-source VST3 audio plugin developed using the JUCE framework for music editing and processing. This initial debugged version successfully builds a VST3 plugin, ready for further development of features like file tree and history GUI.

Ficus_VST3 是一个基于 JUCE 框架开发的开源 VST3 音频插件，用于音乐编辑和处理。此初始调试版本成功构建 VST3 插件，准备进行文件树和历史 GUI 等功能的进一步开发。

## Features (功能)
- VST3 plugin format compatible with DAWs like Ableton Live.
- Basic project structure with PluginProcessor and PluginEditor.

- 支持 VST3 插件格式，兼容 Ableton Live 等数字音频工作站。
- 包含 PluginProcessor 和 PluginEditor 的基本项目结构。

## Build Instructions (构建说明)
1. Clone the repository: `git clone https://github.com/Degrel-me/Ficus`
2. Ensure JUCE is installed at `C:/Users/step4/Documents/JUCE`.
3. Use CMake (version 3.15 or higher) to configure and build.
4. Open in CLion, select `Ficus_VST3` target, and build.
5. Copy `Ficus_VST3.vst3` from `C:\Users\step4\Documents\GitHub\Ficus\cmake-build-debug\Ficus_artefacts\Debug\VST3\` to `C:\Program Files\Common Files\VST3\`

1. 克隆仓库：`git clone https://github.com/Degrel-me/Ficus`
2. 确保 JUCE 安装在 `C:/Users/step4/Documents/JUCE`。
3. 使用 CMake（版本 3.15 或更高）进行配置和构建。
4. 在 CLion 中打开，选择 `Ficus_VST3` 目标并构建。
5. 将 `Ficus_VST3.vst3` 从 `cmake-build-debug/Ficus_VST3_artefacts/Debug` 复制到 `C:\Program Files\Common Files\VST3\Ficus_VST3.vst3\Contents\x86_64-win`。
6. 将 `Resources` 文件夹从 `cmake-build-debug/Ficus_VST3_artefacts/Debug/Resources` 复制到 `C:\Program Files\Common Files\VST3\Ficus_VST3.vst3\Contents\Resources`。

## License (许可证)
MIT License

MIT 许可证