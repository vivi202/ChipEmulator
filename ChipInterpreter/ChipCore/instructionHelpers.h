//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_INSTRUCTIONHELPERS_H
#define CHIPEMULATOR_INSTRUCTIONHELPERS_H
#include <cstdint>

uint16_t getNnn(uint16_t machineCode);
uint16_t getN(uint16_t machineCode);
uint8_t getX(uint16_t machineCode);
uint8_t getY(uint16_t machineCode);
uint8_t getKk(uint16_t machineCode);


#endif //CHIPEMULATOR_INSTRUCTIONHELPERS_H
