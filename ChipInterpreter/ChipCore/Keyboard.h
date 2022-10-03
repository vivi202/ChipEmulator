//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_KEYBOARD_H
#define CHIPEMULATOR_KEYBOARD_H

#include <array>
#include "ResettableComponent.h"



class Keyboard : public ResettableComponent{
public:
    static const int NUMBER_OF_KEYS = 16;
    void pressKey(uint8_t key);
    void releaseKey(uint8_t key);
    bool getKeyState(uint8_t key);
    void reset() override;

private:
    std::array<bool, NUMBER_OF_KEYS>keyBuffer={false};
};


#endif //CHIPEMULATOR_KEYBOARD_H
