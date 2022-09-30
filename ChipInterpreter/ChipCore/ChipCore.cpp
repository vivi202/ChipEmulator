//
// Created by vincenzo on 28/09/22.
//

#include "ChipCore.h"

void ChipCore::reset() {
    //Reset all components.
    ram.reset();
    registerBank.reset();
    display->reset();

}
