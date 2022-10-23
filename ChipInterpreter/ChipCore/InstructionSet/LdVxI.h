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
        uint16_t address=core.registerBank.iReg;
        for (int offset = 0; offset <= x; ++offset) {
            core.registerBank[offset]=core.ram.read(address+offset);
        }
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXI_H
