//
// Created by vincenzo on 05/10/22.
//

#ifndef CHIPEMULATOR_INSTRUCTIONDECODER_H
#define CHIPEMULATOR_INSTRUCTIONDECODER_H

#include <vector>
#include "instructionFactories/InstructionFactory.h"
#include "instructionFactories/FirstNibbleDecodedInstructionFactory.h"
#include "instructionFactories/ZeroInstructionFactory.h"
#include "instructionFactories/ArithmeticInstructionFactory.h"
#include "Instruction.h"
class InstructionDecoder {
public:
    InstructionDecoder();
    Instruction* decode(uint16_t machineCode);

    virtual ~InstructionDecoder();

private:
    std::vector<InstructionFactory*>instructionFactories;
};


#endif //CHIPEMULATOR_INSTRUCTIONDECODER_H
