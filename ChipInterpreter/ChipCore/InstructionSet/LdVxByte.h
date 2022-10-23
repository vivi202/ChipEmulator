//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_LDVXBYTE_H
#define CHIPEMULATOR_LDVXBYTE_H

#include "Instruction.h"
class LdVxByte : public Instruction{
public:
    explicit LdVxByte(uint16_t machineCode): Instruction(machineCode){};
    void execute(ChipCore &core) override {
        core.registerBank[x]=kk;
    }

    std::string toAsm() const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXBYTE_H
