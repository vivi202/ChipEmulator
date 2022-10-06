//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ADDVXVY_H
#define CHIPEMULATOR_ADDVXVY_H
#include "Instruction.h"
//TODO implement AddVxVy
class AddVxVy : public Instruction{
public:

    explicit AddVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~AddVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ADDVXVY_H
