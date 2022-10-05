//
// Created by vincenzo on 05/10/22.
//

#include "FirstNibbleDecodedInstructionFactory.h"
//TODO FIND A BETTER NAME :)
Instruction *FirstNibbleDecodedInstructionFactory::createInstruction(uint16_t machineCode) {
    Instruction* instruction;
    uint8_t firstNibble=machineCode >> 12;
    switch (firstNibble) {
        case 0x1:
            instruction=new JpAddr(machineCode);
            break;
        case 0x6:
            instruction=new LdVxByte(machineCode);
            break;
        case 0x7:
            instruction=new AddVxByte(machineCode);
            break;
        case 0xA:
            instruction=new LdIAddr(machineCode);
            break;
        case 0xD:
            instruction=new DrwVxVyNibble(machineCode);
            break;
        default:
            instruction= nullptr;
    }
    return instruction;
}
