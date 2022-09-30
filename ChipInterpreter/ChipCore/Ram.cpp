//
// Created by vincenzo on 28/09/22.
//

#include "Ram.h"

void Ram::reset() {
    memory.fill(0);
    //After memory reset, font sprites should be reloaded.
    loadFontSprites();
}

void Ram::write(uint16_t address, uint8_t value) {
    memory[address]=value;
}

uint8_t Ram::read(uint16_t address) const {
    return memory[address];
}

void Ram::loadFontSprites() {
    for (int i = 0; i < FONT_SIZE; i++) {
        memory[FONT_START_ADDRESS + i]=fontSprites[i];
    }
}

Ram::Ram(): memory({0}) {
    loadFontSprites();
}
