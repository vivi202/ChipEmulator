//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDBVX_H
#define CHIPEMULATOR_LDBVX_H
#include "Instruction.h"
class LdBVx : public Instruction{
public:

    explicit LdBVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdBVx() override = default;

    void execute(ChipCore &core) override {
        uint8_t number=core.registerBank[x];
        uint8_t units=number % 10;
        uint8_t tens= (number / 10) % 10;
        uint8_t hundreds=(number / 100 ) % 10;
        uint16_t address=core.registerBank.iReg;
        core.ram.write(address+0,hundreds);
        core.ram.write(address+1,tens);
        core.ram.write(address+2,units);
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDBVX_H
