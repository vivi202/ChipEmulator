//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SUBNVXVY_H
#define CHIPEMULATOR_SUBNVXVY_H

#include "Instruction.h"
class SubnVxVy : public Instruction{
public:

    explicit SubnVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SubnVxVy() override = default;

    void execute(ChipCore &core) override {
        if(core.registerBank[y] > core.registerBank[x])
            core.registerBank[0xF]=1;
        else
            core.registerBank[0xF]=0;
        core.registerBank[x]=core.registerBank[y] - core.registerBank[x];
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBNVXVY_H
