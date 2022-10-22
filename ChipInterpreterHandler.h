//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
#define CHIPEMULATOR_CHIPINTERPRETERHANDLER_H

#include "ChipInterpreter.h"
#include "SdlChipDisplay.h"
#include "DisplayTextureHandler.h"
#include "Rom.h"
#include <fstream>
class ChipInterpreterHandler : public Drawable{
public:
    explicit ChipInterpreterHandler(int frequency){
        executionPeriodMs=1/frequency * (float)1000;
    };
    void loadRom(Rom& rom);
    void handleExecution();
    void handleEvents(SDL_Event &e);
    void draw() override;
private:
    Keyboard keyboard;
    DisplayTextureHandler textureHandler;
    SdlChipDisplay display=SdlChipDisplay(&textureHandler);
    ChipInterpreter interpreter=ChipInterpreter(&display,&keyboard);
    uint64_t currentTime=SDL_GetTicks();
    const uint32_t timerRefreshPeriod=1/60 * (float)1000;
    uint32_t lastExecution=0;
    uint32_t lastTimerUpdate=0;
    uint32_t executionPeriodMs;
};


#endif //CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
