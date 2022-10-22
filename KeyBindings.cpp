//
// Created by vincenzo on 22/10/22.
//

#include "KeyBindings.h"

KeyBindings::KeyBindings() {
    //TODO load from config file
    keyBinds[0x1]=SDL_SCANCODE_1;
    keyBinds[0x2]=SDL_SCANCODE_2;
    keyBinds[0x3]=SDL_SCANCODE_3;
    keyBinds[0xC]=SDL_SCANCODE_4;
    keyBinds[0x4]=SDL_SCANCODE_Q;
    keyBinds[0x5]=SDL_SCANCODE_W;
    keyBinds[0x6]=SDL_SCANCODE_E;
    keyBinds[0xD]=SDL_SCANCODE_R;
    keyBinds[0x7]=SDL_SCANCODE_A;
    keyBinds[0x8]=SDL_SCANCODE_S;
    keyBinds[0x9]=SDL_SCANCODE_D;
    keyBinds[0xE]=SDL_SCANCODE_F;
    keyBinds[0xA]=SDL_SCANCODE_Z;
    keyBinds[0x0]=SDL_SCANCODE_X;
    keyBinds[0xB]=SDL_SCANCODE_C;
    keyBinds[0xF]=SDL_SCANCODE_V;
}

uint8_t KeyBindings::getRemappedKey(uint8_t key) const {
    return keyBinds[key];
}

