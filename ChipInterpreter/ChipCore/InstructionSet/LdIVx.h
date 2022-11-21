//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDIVX_H
#define CHIPEMULATOR_LDIVX_H
#include "Instruction.h"
class LdIVx: public Instruction{
public:

    explicit LdIVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdIVx() override = default;

    void execute(ChipCore &core) override {
        uint16_t startAddress=core.registerBank.iReg;
        for (core.registerBank.iReg; core.registerBank.iReg <= startAddress+x ; ++core.registerBank.iReg) {
            core.ram.write(core.registerBank.iReg,core.registerBank[core.registerBank.iReg-startAddress]);
        }
    }

    std::string toAsm() const override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDIVX_H
