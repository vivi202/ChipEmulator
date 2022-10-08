//
// Created by vincenzo on 05/10/22.
//

#include "SdlChipDisplay.h"


Display *SdlChipDisplay::clone() const {
    //TODO implement clone method
    return nullptr;
}

bool SdlChipDisplay::readPixel(int x, int y) {
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
    std::fill(frameBuff,frameBuff+(width*height),0);
}

SdlChipDisplay::~SdlChipDisplay() {
    delete frameBuff;
}

SdlChipDisplay::SdlChipDisplay(uint32_t backgroundColor, uint32_t pixelColor):
Display(SDL_CHIP_DISPLAY_WIDTH,SDL_CHIP_DISPLAY_HEIGHT),backgroundColor(backgroundColor),pixelColor(pixelColor){
    frameBuff=new uint32_t[width*height];
    std::fill(frameBuff,frameBuff+(width*height),backgroundColor);
}
