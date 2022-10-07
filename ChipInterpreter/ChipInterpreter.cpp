//
// Created by vincenzo on 07/10/22.
//

#include "ChipInterpreter.h"

void ChipInterpreter::reset() {
    core->reset();
}

ChipInterpreter::ChipInterpreter(Display *display, Keyboard *keyboard){
    core=std::make_unique<ChipCore>(display,keyboard);
}

uint16_t ChipInterpreter::fetch() {
    uint8_t highByte=core->ram.read(core->registerBank.pcReg);
    uint8_t lowByte=core->ram.read(core->registerBank.pcReg+1);
    core->registerBank.pcReg+=2;
    return (highByte << 8) | lowByte;
}

void ChipInterpreter::cycle() {
    //Fetch instruction
    uint16_t machineCode=fetch();
    //Decode instruction
    auto instruction = instructionDecoder.decode(machineCode);
    //TODO handle when machine code is invalid and leads to a null instruction.
    //execute instruction
    instruction->execute(*core);
}

void ChipInterpreter::handleTimers() {
    if(core->registerBank.delay > 0)
        core->registerBank.delay-=1;
    if(core->registerBank.sound > 0)
        core->registerBank.sound-=1;
}

