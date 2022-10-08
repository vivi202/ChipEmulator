//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
#define CHIPEMULATOR_CHIPINTERPRETERHANDLER_H

#include "ChipInterpreter.h"
#include "SdlChipDisplay.h"
#include "DisplayTextureHandler.h"
class ChipInterpreterHandler : public Drawable{
public:
    explicit ChipInterpreterHandler(int frequency):frequency(frequency){};
    void handleExecution();
    void handleEvents(SDL_Event &e);
    void draw() override;
private:
    Keyboard keyboard;
    DisplayTextureHandler textureHandler;
    SdlChipDisplay display=SdlChipDisplay(&textureHandler);
    ChipInterpreter interpreter=ChipInterpreter(&display,&keyboard);
    int frequency;
};


#endif //CHIPEMULATOR_CHIPINTERPRETERHANDLER_H
