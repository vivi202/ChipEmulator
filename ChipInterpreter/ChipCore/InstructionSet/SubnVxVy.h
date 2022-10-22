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
        uint8_t flag;
        if(core.registerBank[y] > core.registerBank[x])
            flag=1;
        else
            flag=0;
        core.registerBank[x]=core.registerBank[y] - core.registerBank[x];
       core.registerBank[0xF]=flag;
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBNVXVY_H
