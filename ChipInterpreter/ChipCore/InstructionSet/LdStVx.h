//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDSTVX_H
#define CHIPEMULATOR_LDSTVX_H
#include "Instruction.h"
class LdStVx : public Instruction{
public:

    explicit LdStVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdStVx() override = default;

    void execute(ChipCore &core) override {
        core.registerBank.sound=core.registerBank[x];
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDSTVX_H
