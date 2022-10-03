//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_INSTRUCTION_H
#define CHIPEMULATOR_INSTRUCTION_H


#include <cstdint>
#include "ChipCore.h"
#include "instructionHelpers.h"
class Instruction {
public:
    explicit Instruction(uint16_t machineCode){
        nnn = getNnn(machineCode);
        n   = getN(machineCode);
        x   = getX(machineCode);
        y   = getY(machineCode);
        kk  = getKk(machineCode);
    };
    virtual void execute(ChipCore& core)=0;
    virtual std::string toAsm()=0;
protected:
    uint16_t nnn;
    uint8_t n;
    uint8_t x;
    uint8_t y;
    uint8_t kk;
};


#endif //CHIPEMULATOR_INSTRUCTION_H
