//
// Created by vincenzo on 05/10/22.
//

#include "ZeroInstructionFactory.h"
#include "instructionHelpers.h"
Instruction *ZeroInstructionFactory::createInstruction(uint16_t machineCode) {
    uint8_t lastByte= getKk(machineCode);
    uint8_t firstByte=machineCode >> 8;
    Instruction* instruction;
    if(firstByte !=0x00)
        return nullptr;
    switch (lastByte) {
        case 0xE0:
            instruction=new Cls(machineCode);
            break;
        default:
            instruction= nullptr;
    }
    return instruction;
}
