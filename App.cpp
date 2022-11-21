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
    Rom rom(argParser->getRomPath());
    chipInterpreterHandler=std::make_unique<ChipInterpreterHandler>(argParser->getFrequency());
    chipInterpreterHandler->loadRom(rom);
}

void App::setupRenderEngine() {
    engine.addDrawable(chipInterpreterHandler.get());
    crtFilter.setCrossingLineEnabled(argParser->isCrossingLineEnabled());
    crtFilter.setCrossingLineDirection(argParser->isCrossingLineDirection());
    crtFilter.setHorizontalScanLinesEnabled(argParser->isHorizontalScanLinesEnabled());
    crtFilter.setVerticalScanLinesEnabled(argParser->isVerticalScanLinesEnabled());
    engine.addDrawable(&crtFilter);
}

void App::setupCommandlineParser(int argc, char *argv[]) {
    argParser=std::make_unique<ArgParser>(argc, argv);
    argParser->parse();
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
