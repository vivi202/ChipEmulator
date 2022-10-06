//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ARITHMETICINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_ARITHMETICINSTRUCTIONFACTORY_H

#include "InstructionFactory.h"
#include "InstructionSet/LdVxVy.h"
#include "InstructionSet/OrVxVy.h"
#include "InstructionSet/AndVxVy.h"
#include "InstructionSet/XorVxVy.h"
#include "InstructionSet/AddVxVy.h"
#include "InstructionSet/SubVxVy.h"
#include "InstructionSet/ShrVxVy.h"
#include "InstructionSet/SubnVxVy.h"
#include "InstructionSet/ShlVxVy.h"
class ArithmeticInstructionFactory : public InstructionFactory{
public:
    ~ArithmeticInstructionFactory() override = default;

    Instruction *createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_ARITHMETICINSTRUCTIONFACTORY_H
