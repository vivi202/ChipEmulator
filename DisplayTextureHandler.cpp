//
// Created by vincenzo on 08/10/22.
//

#include "DisplayTextureHandler.h"

void DisplayTextureHandler::draw() {
    SDL_RenderCopy(Window::getInstance()->getRenderer(),texture, nullptr, nullptr);
}

DisplayTextureHandler::~DisplayTextureHandler() {
    SDL_DestroyTexture(texture);
}

DisplayTextureHandler::DisplayTextureHandler() {
    texture= SDL_CreateTexture(Window::getInstance()->getRenderer(),SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING,SdlChipDisplay::SDL_CHIP_DISPLAY_WIDTH,
                               SdlChipDisplay::SDL_CHIP_DISPLAY_HEIGHT);

}

void DisplayTextureHandler::updateTexture(const uint32_t *frameBuff) {
    int pitch;
    uint32_t *pixels;
    SDL_LockTexture(texture, nullptr,(void **)&pixels,&pitch);
    //Do things on pixel;
    for (int y = 0; y < SdlChipDisplay::SDL_CHIP_DISPLAY_HEIGHT; ++y) {
        for (int x = 0;  x < SdlChipDisplay::SDL_CHIP_DISPLAY_WIDTH ; ++x) {
            pixels[y * SdlChipDisplay::SDL_CHIP_DISPLAY_WIDTH + x]=frameBuff[y* SdlChipDisplay::SDL_CHIP_DISPLAY_WIDTH + x];
        }
    }
    SDL_UnlockTexture(texture);
}
