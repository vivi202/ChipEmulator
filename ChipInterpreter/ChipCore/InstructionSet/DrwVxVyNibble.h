//
// Created by vincenzo on 04/10/22.
//

#ifndef CHIPEMULATOR_DRWVXVYNIBBLE_H
#define CHIPEMULATOR_DRWVXVYNIBBLE_H

#include "Instruction.h"
class DrwVxVyNibble: public Instruction{
public:
    const int spriteWidth=8;
    explicit DrwVxVyNibble(uint16_t machineCode): Instruction(machineCode){};

    ~DrwVxVyNibble() override = default;

    void execute(ChipCore &core) override {
        uint16_t startAddress=core.registerBank.iReg;//base address of sprite data.
        uint8_t spriteHeight=n;//height of sprite
        uint8_t startXCoord=core.registerBank[x];
        uint8_t startYCoord=core.registerBank[y];
        //wrap coordinates using modulo operator.
        startXCoord= startXCoord % core.display->getWidth();
        startYCoord= startYCoord % core.display->getHeight();
        uint8_t flag=0;
        for (int  spriteIndex = 0; spriteIndex < spriteHeight &&
            startYCoord + spriteIndex < core.display->getHeight();spriteIndex++) {
            //get sprite byte from ram.
            uint8_t spriteByte=core.ram.read(startAddress+spriteIndex);
            for (int currentPixelIndex = 0; currentPixelIndex < spriteWidth &&
                                            startXCoord + currentPixelIndex < core.display->getWidth(); currentPixelIndex++) {

                uint8_t spritePixel= (spriteByte >> ((spriteWidth-1) - currentPixelIndex)) & 0x01;
                uint8_t oldPixel=core.display->readPixel(startXCoord + currentPixelIndex,
                                                         startYCoord + spriteIndex);
                uint8_t xoredPixel= spritePixel ^ oldPixel;

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
                flag|=spritePixel & !xoredPixel;
            }
        }
        core.registerBank[0xF]=flag;
        core.display->notifySpriteDrawn();
    }

    std::string toAsm()const override {
        return {""};
    }

};


#endif //CHIPEMULATOR_DRWVXVYNIBBLE_H
