//
// Created by vincenzo on 28/09/22.
//

#include "ChipCore.h"

void ChipCore::reset() {
    //Reset all components.
    ram.reset();
    registerBank.reset();
    display->reset();
    keyboard->reset();
    //TODO check if there is a better way to clear the stack.
    while (!callStack.empty())
        callStack.pop();
}
