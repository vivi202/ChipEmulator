//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_ADDVXBYTE_H
#define CHIPEMULATOR_ADDVXBYTE_H

#include "Instruction.h"
class AddVxByte : public Instruction {
public:
    explicit AddVxByte(uint16_t machineCode): Instruction(machineCode){};

    ~AddVxByte() override = default;

    void execute(ChipCore &core) override {
        core.registerBank[x]+=kk;
    }

    std::string toAsm() const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ADDVXBYTE_H
