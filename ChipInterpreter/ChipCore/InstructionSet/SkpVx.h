//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SKPVX_H
#define CHIPEMULATOR_SKPVX_H
#include "Instruction.h"
class SkpVx :public Instruction{
public:
    explicit SkpVx(uint16_t machineCode): Instruction(machineCode){};

    ~SkpVx() override = default;

    void execute(ChipCore &core) override {
        if(core.keyboard->getKeyState(core.registerBank[x]))
            core.registerBank.pcReg+=2;
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SKPVX_H
