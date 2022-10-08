//
// Created by vincenzo on 03/10/22.
//

#include "instructionHelpers.h"
//Return lowest 12 bits of instruction
uint16_t getNnn(uint16_t machineCode){
    return machineCode & 0xFFF;
}

//Return lower 4 bits of the high byte of the instruction
uint8_t getX(uint16_t machineCode) {
    return (machineCode >> 8) & 0xF;
}

//Return the upper 4 bits of the low byte of the instruction
uint8_t getY(uint16_t machineCode) {
    return (machineCode >> 4) & 0xF;
}

//Return the lowest 8 bits of the instruction
uint8_t getKk(uint16_t machineCode) {
    return machineCode & 0xFF;
}
//Return the lowest 4 bits of the instruction
uint16_t getN(uint16_t machineCode) {
    return machineCode & 0xF;
}
