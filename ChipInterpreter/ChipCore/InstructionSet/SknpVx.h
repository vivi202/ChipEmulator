//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SKNPVX_H
#define CHIPEMULATOR_SKNPVX_H
#include "Instruction.h"

class SknpVx :public Instruction{
public:

    explicit SknpVx(uint16_t machineCode): Instruction(machineCode){};

    ~SknpVx() override = default;

    void execute(ChipCore &core) override {
        if(!core.keyboard->getKeyState(core.registerBank[x]))
            core.registerBank.pcReg+=2;
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SKNPVX_H
