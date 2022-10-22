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
        uint16_t address=core.registerBank.iReg;
        for (uint8_t offset = 0; offset <= x ; ++offset) {
            core.ram.write(address+offset,core.registerBank[offset]);
        }
    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDIVX_H
