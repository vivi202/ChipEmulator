//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_XORVXVY_H
#define CHIPEMULATOR_XORVXVY_H
#include "Instruction.h"

class XorVxVy : public Instruction{
public:

    explicit  XorVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~XorVxVy() override = default;

    void execute(ChipCore &core) override {
        core.registerBank[x]^=core.registerBank[y];
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_XORVXVY_H
