//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXI_H
#define CHIPEMULATOR_LDVXI_H
#include "Instruction.h"
class LdVxI : public Instruction{
public:

    explicit LdVxI(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxI() override = default;

    void execute(ChipCore &core) override {
        uint16_t startAddress=core.registerBank.iReg;
        for (core.registerBank.iReg; core.registerBank.iReg <= startAddress+x; ++core.registerBank.iReg) {
            core.registerBank[core.registerBank.iReg-startAddress]=core.ram.read(core.registerBank.iReg);
        }
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXI_H
