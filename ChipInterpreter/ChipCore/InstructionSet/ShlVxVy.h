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

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SHLVXVY_H