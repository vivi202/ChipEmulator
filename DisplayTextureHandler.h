//
// Created by vincenzo on 08/10/22.
//

#ifndef CHIPEMULATOR_DISPLAYTEXTUREHANDLER_H
#define CHIPEMULATOR_DISPLAYTEXTUREHANDLER_H

#include "Drawable.h"
#include "SDL.h"
#include "Window.h"
#include "SdlChipDisplay.h"
class DisplayTextureHandler : public Drawable{
public:
    virtual ~DisplayTextureHandler();
    DisplayTextureHandler();
    void updateTexture(const uint32_t *frameBuff);
    void draw() override;
private:
    SDL_Texture* texture;
};


#endif //CHIPEMULATOR_DISPLAYTEXTUREHANDLER_H
