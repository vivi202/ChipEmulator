//
// Created by vincenzo on 06/10/22.
//

#include "EInstructionFactory.h"

std::unique_ptr<Instruction> EInstructionFactory::createInstruction(uint16_t machineCode) {
    if(getfirstMsbNibble(machineCode)!=0xE)
        return nullptr;
    std::unique_ptr<Instruction>instructionPtr;
    switch (getKk(machineCode)) {
        case 0x9E:
            instructionPtr= std::make_unique<SkpVx>(machineCode);
            break;
        case 0xA1:
            instructionPtr=std::make_unique<SknpVx>(machineCode);
            break;
        default:
            instructionPtr= nullptr;
    }
    return instructionPtr;
}
