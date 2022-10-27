//
// Created by vincenzo on 27/10/22.
//

#include "App.h"

App::~App() {
    delete window;
    soundEngine->removeSynth(&synth);
    engine.removeDrawable(&crtFilter);
    engine.removeDrawable(chipInterpreterHandler.get());
    delete soundEngine;
}


App::App(int argc, char *argv[]) {
    setupCommandlineParser(argc,argv);
    setupWindow();
    setupSoundEngine();
    setupInterpreter();
    setupRenderEngine();
}

void App::setupWindow() {
    window=Window::getInstance();
}
void App::setupSoundEngine() {
    soundEngine=SoundEngine::getInstance();
    synth.setAmplitude(0.5);
    soundEngine->addSynth(&synth,220);
}


void App::setupInterpreter() {
    Rom rom(commandLine->getRomPath());
    chipInterpreterHandler=std::make_unique<ChipInterpreterHandler>(commandLine->getFrequency());
    chipInterpreterHandler->loadRom(rom);
}

void App::setupRenderEngine() {
    engine.addDrawable(chipInterpreterHandler.get());
    crtFilter.setCrossingLineEnabled(commandLine->isCrossingLineEnabled());
    crtFilter.setCrossingLineDirection(commandLine->isCrossingLineDirection());
    crtFilter.setHorizontalScanLinesEnabled(commandLine->isHorizontalScanLinesEnabled());
    crtFilter.setVerticalScanLinesEnabled(commandLine->isVerticalScanLinesEnabled());
    engine.addDrawable(&crtFilter);
}

void App::setupCommandlineParser(int argc, char *argv[]) {
    commandLine=std::make_unique<CommandLineArgParser>(argc,argv);
    commandLine->parse();
}

void App::run() {
    while (window->isRunning()){
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0) {
                window->events(e);
                chipInterpreterHandler->handleEvents(e);
            }
        chipInterpreterHandler->handleExecution();
        engine.render();
        }

    }
