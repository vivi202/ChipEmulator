//
// Created by vincenzo on 05/10/22.
//

#include "InstructionDecoder.h"

InstructionDecoder::InstructionDecoder() {
instructionFactories={new ZeroInstructionFactory,new FirstNibbleDecodedInstructionFactory,
                      new ArithmeticInstructionFactory,new EInstructionFactory,new FInstructionFactory};
}

InstructionDecoder::~InstructionDecoder() {
    for (auto &factory: instructionFactories) {
        delete factory;
    }
}

std::unique_ptr<Instruction> InstructionDecoder::decode(uint16_t machineCode) {
    std::unique_ptr<Instruction> instructionPtr= nullptr;
    for (auto itr=instructionFactories.begin();itr!= instructionFactories.end() && instructionPtr == nullptr;itr++) {
        instructionPtr=(*itr)->createInstruction(machineCode);
    }
    if(!instructionPtr)
        throw IllegalInstructionException(machineCode);
    return instructionPtr;
}
