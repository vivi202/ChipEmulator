//
// Created by vincenzo on 07/10/22.
//

#include "ChipInterpreter.h"
#include "iostream"
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
    if(isCoreHalted())
        return;
    //Fetch instruction
    uint16_t machineCode=fetch();
    //Decode instruction
    try {
        auto instruction = instructionDecoder.decode(machineCode);
        instruction->execute(*core);
    }catch (IllegalInstructionException &e){
        std::cout<<"Instruction  execution Failed:"<< std::hex<<e.machineCode<<"\n";
    }
}

void ChipInterpreter::handleTimers() {
    if(core->registerBank.delay > 0)
        core->registerBank.delay-=1;
    if(core->registerBank.sound > 0)
        core->registerBank.sound-=1;
}

void ChipInterpreter::loadProgramData(uint8_t *data, long programSize) {
    core->reset();
    for (int i = 0; i < programSize; ++i) {
        core->ram.write(ChipCore::PROGRAM_START_ADDRESS + i,data[i]);
    }
}

bool ChipInterpreter::isWaitingForRelease() {
    return core->waitingForRelease;
}

bool ChipInterpreter::isCoreHalted() {
    return core->halted;
}

void ChipInterpreter::release() {
    core->halted= false;
    core->waitingForRelease= false;
}


