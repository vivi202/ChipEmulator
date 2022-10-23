//
// Created by vincenzo on 07/10/22.
//

#ifndef CHIPEMULATOR_CHIPINTERPRETER_H
#define CHIPEMULATOR_CHIPINTERPRETER_H

#include "InstructionDecoder.h"
#include "ResettableComponent.h"
#include "SoundObserver.h"
class ChipInterpreter : public ResettableComponent{
public:
    ChipInterpreter(Display* display, Keyboard* keyboard,SoundObserver* soundObserver);
    void reset() override;
    void cycle();
    void handleTimers();
    void loadProgramData(uint8_t* data,long programSize);
    bool isWaitingForRelease()const;
    void release();
    bool isCoreHalted()const;
private:
    InstructionDecoder instructionDecoder;
    std::unique_ptr<ChipCore> core;
    SoundObserver* soundObserver;
    bool isPlayingSound= false;
    uint16_t fetch();
};


#endif //CHIPEMULATOR_CHIPINTERPRETER_H
