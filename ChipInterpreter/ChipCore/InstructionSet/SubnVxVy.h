//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SUBNVXVY_H
#define CHIPEMULATOR_SUBNVXVY_H

#include "Instruction.h"
//TODO implement SubnVxVy
class SubnVxVy : public Instruction{
public:

    explicit SubnVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SubnVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBNVXVY_H
