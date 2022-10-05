//
// Created by vincenzo on 04/10/22.
//

#ifndef CHIPEMULATOR_DRWVXVYNIBBLE_H
#define CHIPEMULATOR_DRWVXVYNIBBLE_H

#include "Instruction.h"
class DrwVxVyNibble: public Instruction{
public:
    explicit DrwVxVyNibble(uint16_t machineCode): Instruction(machineCode){};

    void execute(ChipCore &core) override {
        uint16_t startAddress=core.registerBank.iReg;//base address of sprite data.
        uint8_t spriteSize=n;//size of sprite expressed in bytes
        uint8_t startXCoord=x;
        uint8_t startYCoord=y;
        //wrap coordinates using modulo operator.
        startXCoord= startXCoord % core.display->getWidth();
        startYCoord= startYCoord % core.display->getHeight();
        for (int  spriteIndex = 0;  spriteIndex < spriteSize &&
            startYCoord + spriteIndex < core.display->getHeight();spriteIndex++) {
            //get sprite byte from ram.
            uint8_t spriteByte=core.ram.read(startAddress+spriteIndex);
            for (int currentPixelIndex = 0; currentPixelIndex < 8 &&
                                            startXCoord + currentPixelIndex < core.display->getWidth(); currentPixelIndex++) {
                uint8_t spritePixel= (spriteByte >> (7 - currentPixelIndex)) & 0x01;
                uint8_t xoredPixel= spritePixel ^ core.display->readPixel(startXCoord + currentPixelIndex,
                                                                          startYCoord + spriteIndex);

                core.display->writePixel(startXCoord + currentPixelIndex,
                                         startYCoord + spriteIndex
                                         , xoredPixel);

                /*if xor operation causes pixel to be erased then general purpose register 0xF is set to 1, 0 otherwise.
                 * spritePixel | xoredPixel | erasedPixelFlag
                 * ------------|------------|----------------
                 *     0       |    0       |       0
                 *     0       |    1       |       0
                 *     1       |    0       |       1  => erasedPixelFlag= spritePixel AND !xoredPixel
                 *     1       |    1       |       0
                 *-------------------------------------------
                 */
                core.registerBank[0xF]=spritePixel & !xoredPixel;

            }
        }
        
    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_DRWVXVYNIBBLE_H
