//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXVY_H
#define CHIPEMULATOR_LDVXVY_H
#include "Instruction.h"
//TODO implement LdVxVy
class LdVxVy : public Instruction{
public:

    explicit LdVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXVY_H
