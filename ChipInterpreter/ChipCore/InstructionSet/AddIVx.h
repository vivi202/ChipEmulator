//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ADDIVX_H
#define CHIPEMULATOR_ADDIVX_H
#include "Instruction.h"

class AddIVx: public Instruction{
public:
    explicit AddIVx(uint16_t machineCode): Instruction(machineCode){};

    ~AddIVx() override = default;

    void execute(ChipCore &core) override {
        core.registerBank.iReg+=core.registerBank[x];
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ADDIVX_H
