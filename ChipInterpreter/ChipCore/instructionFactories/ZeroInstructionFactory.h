//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H

#include "InstructionFactory.h"
#include "InstructionSet/Cls.h"
class ZeroInstructionFactory : public InstructionFactory{
public:
    Instruction *createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H
