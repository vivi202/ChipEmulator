//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SNEVXBYTE_H
#define CHIPEMULATOR_SNEVXBYTE_H
#include "Instruction.h"
//TODO Implement SneVxByte
class SneVxByte : public Instruction{
public:

    explicit SneVxByte(uint16_t machineCode): Instruction(machineCode){};

    ~SneVxByte() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SNEVXBYTE_H
