//
// Created by vincenzo on 05/10/22.
//

#include "ZeroInstructionFactory.h"
#include "instructionHelpers.h"
std::unique_ptr<Instruction> ZeroInstructionFactory::createInstruction(uint16_t machineCode) {
    uint8_t lastByte= getKk(machineCode);
    uint8_t firstByte=machineCode >> 8;
    std::unique_ptr<Instruction>instructionPtr;
    if(firstByte !=0x00)
        return nullptr;
    switch (lastByte) {
        case 0xE0:
            instructionPtr=std::make_unique<Cls>(machineCode);
            break;
        case 0xEE:
            instructionPtr=std::make_unique<Ret>(machineCode);
            break;
        default:
            instructionPtr= nullptr;
    }
    return instructionPtr;
}
