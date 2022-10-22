//
// Created by vincenzo on 22/10/22.
//

#ifndef CHIPEMULATOR_KEYBINDINGS_H
#define CHIPEMULATOR_KEYBINDINGS_H
#include "Keyboard.h"
#include "SDL.h"
#include <array>
class KeyBindings {
public:
    KeyBindings();
    uint8_t getRemappedKey(uint8_t key)const;
private:
    std::array<uint8_t,Keyboard::NUMBER_OF_KEYS> keyBinds{};
};


#endif //CHIPEMULATOR_KEYBINDINGS_H
