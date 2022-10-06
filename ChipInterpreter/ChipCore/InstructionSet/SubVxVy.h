//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SUBVXVY_H
#define CHIPEMULATOR_SUBVXVY_H
#include "Instruction.h"

//TODO implement SubVxVy
class SubVxVy : public Instruction{
public:

    explicit SubVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SubVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SUBVXVY_H
