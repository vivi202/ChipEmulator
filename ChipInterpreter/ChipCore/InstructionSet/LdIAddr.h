//
// Created by vincenzo on 04/10/22.
//

#ifndef CHIPEMULATOR_LDIADDR_H
#define CHIPEMULATOR_LDIADDR_H

#include "Instruction.h"
class LdIAddr: public Instruction{
public:
    explicit LdIAddr(uint16_t machineCode): Instruction(machineCode){};

    ~LdIAddr() override = default;

    void execute(ChipCore &core) override {
        core.registerBank.iReg=nnn;
    }

    std::string toAsm()const override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDIADDR_H
