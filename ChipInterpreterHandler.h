//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
#define CHIPEMULATOR_CHIPINTERPRETERHANDLER_H

#include "ChipInterpreter.h"
#include "SdlChipDisplay.h"
#include "DisplayTextureHandler.h"
#include "Rom.h"
#include "KeyBindings.h"
#include "SoundEngine.h"
#include <fstream>
class ChipInterpreterHandler : public Drawable, private SoundObserver{
public:
    explicit ChipInterpreterHandler(int frequency){
        executionPeriodMs=(1/(float)frequency);
    };
    void loadRom(Rom& rom);
    void handleExecution();
    void handleEvents(SDL_Event &e);
    void draw() override;
private:
    void startSound() override;
    void stopSound() override;
    Keyboard keyboard;
    KeyBindings keyBindings;
    DisplayTextureHandler textureHandler;
    SdlChipDisplay display=SdlChipDisplay(&textureHandler);
    ChipInterpreter interpreter=ChipInterpreter(&display,&keyboard, this);
    uint64_t currentTime=SDL_GetPerformanceCounter();
    float timerRefreshPeriod=1/(float)60;
    uint64_t lastExecution=0;
    uint64_t lastTimerUpdate=0;
    float executionPeriodMs;
};


#endif //CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
