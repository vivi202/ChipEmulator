//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ANDVXVY_H
#define CHIPEMULATOR_ANDVXVY_H
#include "Instruction.h"
class AndVxVy : public Instruction{
public:

    explicit AndVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~AndVxVy() override = default;

    void execute(ChipCore &core) override {
        core.registerBank[x]&=core.registerBank[y];
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ANDVXVY_H
