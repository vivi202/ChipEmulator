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
        uint8_t flag;
        if(core.registerBank[x]>core.registerBank[y])
            flag=1;
        else
            flag=0;
        core.registerBank[x]-=core.registerBank[y];
        core.registerBank[0xF]=flag;

    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBVXVY_H
