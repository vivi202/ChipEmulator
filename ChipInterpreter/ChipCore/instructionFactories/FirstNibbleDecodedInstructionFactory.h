//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_FIRSTNIBBLEDECODEDINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_FIRSTNIBBLEDECODEDINSTRUCTIONFACTORY_H

#include "InstructionFactory.h"
#include "InstructionSet/AddVxByte.h"
#include "InstructionSet/JpAddr.h"
#include "InstructionSet/LdIAddr.h"
#include "InstructionSet/LdVxByte.h"
#include "InstructionSet/DrwVxVyNibble.h"
class FirstNibbleDecodedInstructionFactory: public InstructionFactory{
public:
    Instruction *createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_FIRSTNIBBLEDECODEDINSTRUCTIONFACTORY_H
