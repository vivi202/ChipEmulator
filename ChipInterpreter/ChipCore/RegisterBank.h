//
// Created by vincenzo on 27/09/22.
//

#ifndef CHIPEMULATOR_REGISTERBANK_H
#define CHIPEMULATOR_REGISTERBANK_H
#include <array>
#include "ResettableComponent.h"
class RegisterBank: public ResettableComponent{
public:
    static const int GpRegisterNum=16;
    RegisterBank();
    //Special purpose registers
    uint16_t iReg;
    uint16_t pcReg;
    //timers registers
    uint8_t delay;
    uint8_t sound;
    uint8_t& operator[](int i);

    void reset() override;

private:
    //GeneralPurpose registers V0 to VF
    std::array<uint8_t,GpRegisterNum>vRegisters{};
};


#endif //CHIPEMULATOR_REGISTERBANK_H
