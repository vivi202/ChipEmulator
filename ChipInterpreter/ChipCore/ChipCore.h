//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_CHIPCORE_H
#define CHIPEMULATOR_CHIPCORE_H
#include "RegisterBank.h"
#include "Ram.h"
#include "Display.h"
#include "Keyboard.h"
#include "ResettableComponent.h"
#include <stack>
#include <random>
#include <cmath>
class ChipCore: public ResettableComponent{
public:
    ChipCore(Display *display,Keyboard *keyboard):display(display),keyboard(keyboard){
        ram.reset();
        registerBank.reset();
        registerBank.pcReg=PROGRAM_START_ADDRESS;
        if(display)
            display->reset();
        if(keyboard)
            keyboard->reset();
    };
    //MEMORY
    static const int PROGRAM_START_ADDRESS=0x200;
    Ram ram;
    //REGISTERS
    RegisterBank registerBank;
    //STACK
    std::stack<uint16_t>callStack;
    //DISPLAY
    Display* display;
    //KEYBOARD
    Keyboard* keyboard;
    void reset() override;
    uint8_t getRandomByte();
    bool waitingForRelease= false;
    bool halted= false;
private:
    //RNG and other things
    std::random_device rd;
    std::uniform_int_distribution<uint8_t> dist=std::uniform_int_distribution<uint8_t>(0,255);
    std::default_random_engine RandomEngine=std::default_random_engine(rd());
};


#endif //CHIPEMULATOR_CHIPCORE_H
