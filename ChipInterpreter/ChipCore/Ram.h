//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_RAM_H
#define CHIPEMULATOR_RAM_H

#include "ResettableComponent.h"
#include <array>
class Ram :public ResettableComponent{
public:
    //chip8 can address memory from 0x000 to 0xFFF
    static const int MEMORY_SIZE=4096;
    void reset() override;
    void write(uint16_t address,uint8_t value);
    uint8_t read(uint16_t address)const;
private:
    static const int FONT_START_ADDRESS=0x000;
    //space occupied by default font in bytes.
    static const int FONT_SIZE=80;
    //TODO create an array that contains font sprites to load them in memory.

    //TODO Implement this method!
    void loadFontSprites();
    std::array<uint8_t,MEMORY_SIZE>memory;
};


#endif //CHIPEMULATOR_RAM_H
