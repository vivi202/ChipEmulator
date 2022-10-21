//
// Created by vincenzo on 06/10/22.
//

#include "ArithmeticInstructionFactory.h"
std::unique_ptr<Instruction> ArithmeticInstructionFactory::createInstruction(uint16_t machineCode) {
    if(getfirstMsbNibble(machineCode) != 0x8)
        return nullptr;
    std::unique_ptr<Instruction>instructionPtr;
    switch (getN(machineCode)) {
        case 0x0:
            instructionPtr= std::make_unique<LdVxVy>(machineCode);
            break;
        case 0x1:
            instructionPtr= std::make_unique<OrVxVy>(machineCode);
            break;
        case 0x2:
            instructionPtr= std::make_unique<AndVxVy>(machineCode);
            break;
        case 0x3:
            instructionPtr= std::make_unique<XorVxVy>(machineCode);
            break;
        case 0x4:
            instructionPtr= std::make_unique<AddVxVy>(machineCode);
            break;
        case 0x5:
            instructionPtr= std::make_unique<SubVxVy>(machineCode);
            break;
        case 0x6:
            instructionPtr= std::make_unique<ShrVxVy>(machineCode);
            break;
        case 0x7:
            instructionPtr= std::make_unique<SubnVxVy>(machineCode);
            break;
        case 0xE:
            instructionPtr= std::make_unique<ShlVxVy>(machineCode);
            break;
        default:
            instructionPtr= nullptr;
    }
    return instructionPtr;
}
