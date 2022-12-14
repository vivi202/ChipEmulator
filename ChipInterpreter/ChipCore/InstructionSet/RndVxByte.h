//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_RNDVXBYTE_H
#define CHIPEMULATOR_RNDVXBYTE_H
#include "Instruction.h"
class RndVxByte : public Instruction{
public:

    explicit RndVxByte(uint16_t machineCode): Instruction(machineCode){};

    ~RndVxByte() override = default;

    void execute(ChipCore &core) override {
        core.registerBank[x]=core.getRandomByte() & kk;
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_RNDVXBYTE_H
