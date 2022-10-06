//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_FINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_FINSTRUCTIONFACTORY_H
#include "InstructionFactory.h"
#include "InstructionSet/LdVxDt.h"
#include "InstructionSet/LdVxK.h"
#include "InstructionSet/LdDtVx.h"
#include "InstructionSet/LdStVx.h"
#include "InstructionSet/AddIVx.h"
#include "InstructionSet/LdFVx.h"
#include "InstructionSet/LdBVx.h"
#include "InstructionSet/LdIVx.h"
#include "InstructionSet/LdVxI.h"
class FInstructionFactory : public InstructionFactory{
public:
    ~FInstructionFactory() override = default;

    std::unique_ptr<Instruction> createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_FINSTRUCTIONFACTORY_H
