//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_CHIPCORE_H
#define CHIPEMULATOR_CHIPCORE_H

#include "RegisterBank.h"
#include "ResettableComponent.h"
class ChipCore: public ResettableComponent{
public:
    //TODO MEMORY

    //REGISTERS
    RegisterBank registerBank;

    //TODO STACK

    //TODO DISPLAY

    //TODO KEYBOARD

    //
    void reset() override;
private:
    //RNG and other things
};


#endif //CHIPEMULATOR_CHIPCORE_H
