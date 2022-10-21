//
// Created by vincenzo on 05/10/22.
//

#include "FirstNibbleDecodedInstructionFactory.h"

#include <memory>
//TODO FIND A BETTER NAME :)
std::unique_ptr<Instruction> FirstNibbleDecodedInstructionFactory::createInstruction(uint16_t machineCode) {
    std::unique_ptr<Instruction>instructionPtr;
    uint8_t firstMsbNibble= getfirstMsbNibble(machineCode);
    switch (firstMsbNibble) {
        case 0x1:
            instructionPtr=std::make_unique<JpAddr>(machineCode);
            break;
        case 0x2:
            instructionPtr=std::make_unique<CallAddr>(machineCode);
            break;
        case 0x3:
            instructionPtr=std::make_unique<SeVxByte>(machineCode);
            break;
        case 0x4:
            instructionPtr=std::make_unique<SneVxByte>(machineCode);
            break;
        case 0x5:
            instructionPtr=std::make_unique<SeVxVy>(machineCode);
            break;
        case 0x6:
            instructionPtr=std::make_unique<LdVxByte>(machineCode);
            break;
        case 0x7:
            instructionPtr=std::make_unique<AddVxByte>(machineCode);
            break;
        case 0x9:
            instructionPtr= std::make_unique<SneVxVy>(machineCode);
            break;
        case 0xA:
            instructionPtr=std::make_unique<LdIAddr>(machineCode);
            break;
        case 0xB:
            instructionPtr=std::make_unique<JpV0Addr>(machineCode);
            break;
        case 0xC:
            instructionPtr=std::make_unique<RndVxByte>(machineCode);
            break;
        case 0xD:
            instructionPtr=std::make_unique<DrwVxVyNibble>(machineCode);
            break;
        default:
            instructionPtr= nullptr;
    }
    return instructionPtr;
}
