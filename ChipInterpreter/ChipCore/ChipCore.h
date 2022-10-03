//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_CHIPCORE_H
#define CHIPEMULATOR_CHIPCORE_H
#include <stack>
#include "RegisterBank.h"
#include "Ram.h"
#include "Display.h"
#include "Keyboard.h"
#include "ResettableComponent.h"
class ChipCore: public ResettableComponent{
public:
    ChipCore(Display *display,Keyboard *keyboard):display(display),keyboard(keyboard){
        ram.reset();
        registerBank.reset();
        if(display)
            display->reset();
        if(keyboard)
            keyboard->reset();
    };
    //MEMORY
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
private:
    //RNG and other things
};


#endif //CHIPEMULATOR_CHIPCORE_H
