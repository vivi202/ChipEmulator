//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_JPV0ADDR_H
#define CHIPEMULATOR_JPV0ADDR_H
#include "Instruction.h"
class JpV0Addr : public Instruction{
public:

    explicit JpV0Addr(uint16_t machineCode): Instruction(machineCode){};

    ~JpV0Addr() override = default;

    void execute(ChipCore &core) override {
        core.registerBank.pcReg=nnn+core.registerBank[0];
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_JPV0ADDR_H
