//
// Created by vincenzo on 05/10/22.
//

#include "InstructionDecoder.h"

InstructionDecoder::InstructionDecoder() {
instructionFactories={new ZeroInstructionFactory,new FirstNibbleDecodedInstructionFactory};
}

InstructionDecoder::~InstructionDecoder() {
    for (auto &factory: instructionFactories) {
        delete factory;
    }
}

Instruction *InstructionDecoder::decode(uint16_t machineCode) {
    Instruction* instruction= nullptr;
    for (auto itr=instructionFactories.begin();itr!= instructionFactories.end() && instruction == nullptr;itr++) {
        instruction=(*itr)->createInstruction(machineCode);
    }
    return instruction;
}
