//
// Created by vincenzo on 28/09/22.
//

#include "ChipCore.h"

void ChipCore::reset() {
    //Reset all components.
    ram.reset();
    registerBank.reset();
    registerBank.pcReg=PROGRAM_START_ADDRESS;
    if(display)
        display->reset();
    if(keyboard)
        keyboard->reset();
    //TODO check if there is a better way to clear the stack.
    while (!callStack.empty())
        callStack.pop();
}

uint8_t ChipCore::getRandomByte() {
    return dist(RandomEngine);
}
