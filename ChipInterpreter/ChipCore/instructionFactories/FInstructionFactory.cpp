//
// Created by vincenzo on 06/10/22.
//

#include "FInstructionFactory.h"

std::unique_ptr<Instruction> FInstructionFactory::createInstruction(uint16_t machineCode) {
    if(getfirstMsbNibble(machineCode) != 0xF)
        return nullptr;
    std::unique_ptr<Instruction>instructionPtr;
    switch (getKk(machineCode)) {
        case 0x07:
            instructionPtr= std::make_unique<LdVxDt>(machineCode);
            break;
        case 0x0A:
            instructionPtr= std::make_unique<LdVxK>(machineCode);
            break;
        case 0x15:
            instructionPtr= std::make_unique<LdDtVx>(machineCode);
            break;
        case 0x18:
            instructionPtr= std::make_unique<LdStVx>(machineCode);
            break;
        case 0x1E:
            instructionPtr=std::make_unique<AddIVx>(machineCode);
            break;
        case 0x29:
            instructionPtr= std::make_unique<LdFVx>(machineCode);
            break;
        case 0x33:
            instructionPtr= std::make_unique<LdBVx>(machineCode);
            break;
        case 0x55:
            instructionPtr= std::make_unique<LdIVx>(machineCode);
            break;
        case 0x65:
            instructionPtr= std::make_unique<LdVxI>(machineCode);
            break;
        default:
            instructionPtr= nullptr;
    }
    return instructionPtr;
}
