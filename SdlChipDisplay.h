//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_SDLCHIPDISPLAY_H
#define CHIPEMULATOR_SDLCHIPDISPLAY_H
#include "Display.h"
#include <cstdint>
#include <algorithm>
#include "DisplayTextureHandler.h"
class DisplayTextureHandler;
class SdlChipDisplay : public Display{
public:
    static const int SDL_CHIP_DISPLAY_WIDTH=64;
    static const int SDL_CHIP_DISPLAY_HEIGHT=32;
    explicit SdlChipDisplay(DisplayTextureHandler* textureHandler,uint32_t backgroundColor=0x0,uint32_t pixelColor=0x0FFFFFF);

    ~SdlChipDisplay() override;

    Display *clone() const override;

    bool readPixel(int x, int y) override;

    void writePixel(int x, int y, bool value) override;

    void reset() override;

    void notify() override;

    void notifyTextureHandler();
private:
    uint32_t *frameBuff;
    uint32_t backgroundColor;
    uint32_t pixelColor;
    DisplayTextureHandler* textureHandler;
};


#endif //CHIPEMULATOR_SDLCHIPDISPLAY_H
