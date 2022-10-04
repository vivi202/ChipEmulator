//
// Created by vincenzo on 04/10/22.
//

#ifndef CHIPEMULATOR_LDIADDR_H
#define CHIPEMULATOR_LDIADDR_H

#include "Instruction.h"
class LdIAddr: public Instruction{
public:
    explicit LdIAddr(uint16_t machineCode): Instruction(machineCode){};
    void execute(ChipCore &core) override {
        core.registerBank.iReg=nnn;
    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDIADDR_H
