//
// Created by vincenzo on 08/10/22.
//

#include "ChipInterpreterHandler.h"
void ChipInterpreterHandler::draw() {
    textureHandler.draw();
}

void ChipInterpreterHandler::handleExecution() {
    currentTime=SDL_GetPerformanceCounter();
    if((currentTime - lastExecution)/(float)SDL_GetPerformanceFrequency() >= executionPeriodMs){
        interpreter.cycle();
        lastExecution=currentTime;
    }
    if((currentTime - lastTimerUpdate)/(float)SDL_GetPerformanceFrequency() >= timerRefreshPeriod){
        interpreter.handleTimers();
        lastTimerUpdate=currentTime;
    }

}

void ChipInterpreterHandler::handleEvents(SDL_Event &e) {
    if(interpreter.isWaitingForRelease()){
        switch (e.type) {
            case SDL_KEYUP:
                interpreter.release();
                break;
        }
    }
    const uint8_t* state= SDL_GetKeyboardState(nullptr);
    for (int chipKey = 0; chipKey < Keyboard::NUMBER_OF_KEYS; ++chipKey) {
        keyboard.setKeyState(chipKey,state[keyBindings.getRemappedKey(chipKey)]);
    }
}

void ChipInterpreterHandler::loadRom(Rom &rom) {
    auto &path=rom.getPath();
    std::ifstream romFile(path,std::ifstream::binary);
    if(romFile.is_open()){
        romFile.seekg(0,std::ifstream::end);
        long size=romFile.tellg();
        auto buff=std::unique_ptr<char>(new char[size]);
        romFile.seekg(0,std::ifstream::beg);
        romFile.read(buff.get(),size);
        interpreter.loadProgramData(reinterpret_cast<uint8_t*>(buff.get()),size);
        romFile.close();
    }
}
