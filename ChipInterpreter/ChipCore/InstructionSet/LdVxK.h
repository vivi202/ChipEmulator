//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXK_H
#define CHIPEMULATOR_LDVXK_H
#include "Instruction.h"
//TODO implement this better
class LdVxK : public Instruction{
public:

    explicit LdVxK(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxK() override = default;

    void execute(ChipCore &core) override {
        uint8_t key;
        bool state;
        for (key = 0,state= false; key < Keyboard::NUMBER_OF_KEYS && !state; ++key) {
            state=core.keyboard->getKeyState(key);
        }
        if(state)
            core.registerBank[x]=key-1;
        else
            core.registerBank.pcReg-=2;
    }
    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXK_H
