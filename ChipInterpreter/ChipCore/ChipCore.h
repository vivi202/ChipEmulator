//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_CHIPCORE_H
#define CHIPEMULATOR_CHIPCORE_H

#include "RegisterBank.h"
#include "Ram.h"
#include "Display.h"
#include "ResettableComponent.h"
class ChipCore: public ResettableComponent{
public:
    //TODO MEMORY
    Ram ram;
    //REGISTERS
    RegisterBank registerBank;

    //TODO STACK

    //TODO DISPLAY
    Display* display;
    //TODO KEYBOARD

    //
    void reset() override;
private:
    //RNG and other things
};


#endif //CHIPEMULATOR_CHIPCORE_H
