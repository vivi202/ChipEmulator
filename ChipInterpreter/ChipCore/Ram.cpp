//
// Created by vincenzo on 28/09/22.
//

#include "Ram.h"

void Ram::reset() {
    memory.fill(0);
    //TODO After memory reset, font sprites should be reloaded.
}

void Ram::write(uint16_t address, uint8_t value) {
    memory[address]=value;
}

uint8_t Ram::read(uint16_t address) const {
    return memory[address];
}
