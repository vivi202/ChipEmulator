//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SUBVXVY_H
#define CHIPEMULATOR_SUBVXVY_H
#include "Instruction.h"


class SubVxVy : public Instruction{
public:

    explicit SubVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SubVxVy() override = default;

    void execute(ChipCore &core) override {
        if(core.registerBank[x]>core.registerBank[y])
            core.registerBank[0xF]=1;
        else
            core.registerBank[0xF]=0;
        core.registerBank[x]-=core.registerBank[y];
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBVXVY_H
