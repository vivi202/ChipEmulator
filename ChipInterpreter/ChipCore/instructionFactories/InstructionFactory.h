//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_INSTRUCTIONFACTORY_H
#define CHIPEMULATOR_INSTRUCTIONFACTORY_H

#include "Instruction.h"
#include <memory>
class InstructionFactory {
public:
    virtual ~InstructionFactory()=default;
    virtual std::unique_ptr<Instruction> createInstruction(uint16_t machineCode)=0;
};


#endif //CHIPEMULATOR_INSTRUCTIONFACTORY_H
