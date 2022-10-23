//
// Created by vincenzo on 05/10/22.
//

#include "SdlChipDisplay.h"



bool SdlChipDisplay::readPixel(int x, int y)const  {
    return frameBuff[y*width + x]==pixelColor;
}

void SdlChipDisplay::writePixel(int x, int y, bool value) {
    if(value){
        frameBuff[y*width + x]=pixelColor;
    }else{
        frameBuff[y*width + x]=backgroundColor;
    }
}

void SdlChipDisplay::reset() {
    std::fill(frameBuff,frameBuff+(width*height),backgroundColor);
    notifyTextureHandler();
}

SdlChipDisplay::~SdlChipDisplay() {
    delete frameBuff;
}

SdlChipDisplay::SdlChipDisplay(DisplayTextureHandler* textureHandler,uint32_t backgroundColor, uint32_t pixelColor):
Display(SDL_CHIP_DISPLAY_WIDTH,SDL_CHIP_DISPLAY_HEIGHT),backgroundColor(backgroundColor),
pixelColor(pixelColor),textureHandler(textureHandler){

    frameBuff=new uint32_t[width*height];
    std::fill(frameBuff,frameBuff+(width*height),backgroundColor);
}

void SdlChipDisplay::notifyTextureHandler() {
    textureHandler->updateTexture(frameBuff);
}

void SdlChipDisplay::notify() {
    notifyTextureHandler();
}
