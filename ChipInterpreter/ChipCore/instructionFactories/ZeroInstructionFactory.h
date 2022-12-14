//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H

#include "InstructionFactory.h"
#include "InstructionSet/Cls.h"
#include "InstructionSet/Ret.h"
class ZeroInstructionFactory : public InstructionFactory{
public:
    std::unique_ptr<Instruction> createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_ZEROINSTRUCTIONFACTORY_H
