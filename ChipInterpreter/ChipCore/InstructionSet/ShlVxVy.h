//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SHLVXVY_H
#define CHIPEMULATOR_SHLVXVY_H
#include "Instruction.h"
class ShlVxVy : public Instruction{
public:

    explicit ShlVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~ShlVxVy() override = default;

    void execute(ChipCore &core) override {
        uint8_t flag=(core.registerBank[y] >> 7 );
        core.registerBank[x]=core.registerBank[y]<<1;
        core.registerBank[0xF]=flag;
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SHLVXVY_H
