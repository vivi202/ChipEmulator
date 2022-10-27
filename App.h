//
// Created by vincenzo on 27/10/22.
//

#ifndef CHIPEMULATOR_APP_H
#define CHIPEMULATOR_APP_H
#include "Window.h"
#include "RenderEngine.h"
#include "ChipInterpreterHandler.h"
#include "SoundEngine.h"
#include "Synth/SquareWaveTableSynth.h"
#include "CommandLineArgParser.h"
#include <memory>
class App {
public:
    virtual ~App();
    App(int argc, char *argv[]);
    void run();
private:
    std::unique_ptr<CommandLineArgParser> commandLine;
    Window* window= nullptr;
    SoundEngine* soundEngine= nullptr;
    SquareWaveTableSynth synth=SquareWaveTableSynth(SoundEngine::samplePerSecond);
    std::unique_ptr<ChipInterpreterHandler> chipInterpreterHandler= nullptr;
    RenderEngine engine;
    uint32_t lastInputPoll=0;
    uint32_t currentTime=0;
    const uint32_t inputPollPeriod=5;
    void setupCommandlineParser(int argc, char *argv[]);
    void setupWindow();
    void setupSoundEngine();
    void setupInterpreter();
    void setupRenderEngine();
};


#endif //CHIPEMULATOR_APP_H
