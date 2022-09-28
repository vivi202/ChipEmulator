//
// Created by vincenzo on 27/09/22.
//

#include "RegisterBank.h"

RegisterBank::RegisterBank():iReg(0),pcReg(0),delay(0),sound(0){
    //clear all general purpose registers
    vRegisters.fill(0);
}

uint8_t &RegisterBank::operator[](int i) {
    return vRegisters[i];
}

void RegisterBank::reset() {
    iReg=0;
    pcReg=0;
    delay=0;
    sound=0;
    vRegisters.fill(0);
}
