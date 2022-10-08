//
// Created by vincenzo on 07/10/22.
//

#ifndef CHIPEMULATOR_CHIPINTERPRETER_H
#define CHIPEMULATOR_CHIPINTERPRETER_H

#include "InstructionDecoder.h"
#include "ResettableComponent.h"
class ChipInterpreter : public ResettableComponent{
public:
    ChipInterpreter(Display* display, Keyboard* keyboard);
    void reset() override;
    void cycle();
    void handleTimers();
    void loadProgramData(uint8_t* data,long programSize);
private:
    InstructionDecoder instructionDecoder;
    std::unique_ptr<ChipCore> core;
    uint16_t fetch();
};


#endif //CHIPEMULATOR_CHIPINTERPRETER_H
