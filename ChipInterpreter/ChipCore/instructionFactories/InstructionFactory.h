//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_INSTRUCTIONFACTORY_H
#define CHIPEMULATOR_INSTRUCTIONFACTORY_H

#include "Instruction.h"
class InstructionFactory {
public:
    virtual ~InstructionFactory()=default;
    virtual Instruction* createInstruction(uint16_t machineCode)=0;
};


#endif //CHIPEMULATOR_INSTRUCTIONFACTORY_H
