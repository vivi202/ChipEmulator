//
// Created by vincenzo on 28/09/22.
//

#ifndef CHIPEMULATOR_INSTRUCTION_H
#define CHIPEMULATOR_INSTRUCTION_H


#include <cstdint>
#include "ChipCore.h"
class Instruction {
public:
    explicit Instruction(uint16_t machineCode):machineCode(machineCode){};
    virtual void execute(ChipCore& core)=0;
    virtual std::string toAsm()=0;
protected:
    uint16_t machineCode;
};


#endif //CHIPEMULATOR_INSTRUCTION_H
