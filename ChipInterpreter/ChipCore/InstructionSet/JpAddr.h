//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_JPADDR_H
#define CHIPEMULATOR_JPADDR_H

#include "Instruction.h"
class JpAddr: public Instruction{
public:
    explicit JpAddr(uint16_t machineCode): Instruction(machineCode){};
    void execute(ChipCore &core) override {
        core.registerBank.pcReg=nnn;
    }

    std::string toAsm() const override {
        return {"JP"};
    }
};


#endif //CHIPEMULATOR_JPADDR_H
