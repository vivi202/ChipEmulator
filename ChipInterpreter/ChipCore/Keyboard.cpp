//
// Created by vincenzo on 03/10/22.
//

#include "Keyboard.h"

void Keyboard::pressKey(uint8_t key) {
    keyBuffer[key]= true;
}

void Keyboard::releaseKey(uint8_t key) {
    keyBuffer[key]= false;
}

bool Keyboard::getKeyState(uint8_t key)const{
    return keyBuffer[key];
}

void Keyboard::reset() {
    keyBuffer.fill(false);
}

void Keyboard::setKeyState(uint8_t key, bool state) {
    keyBuffer[key]=state;
}
