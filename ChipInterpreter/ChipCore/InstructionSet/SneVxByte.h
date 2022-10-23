//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SNEVXBYTE_H
#define CHIPEMULATOR_SNEVXBYTE_H
#include "Instruction.h"
class SneVxByte : public Instruction{
public:

    explicit SneVxByte(uint16_t machineCode): Instruction(machineCode){};

    ~SneVxByte() override = default;

    void execute(ChipCore &core) override {
        if(core.registerBank[x] != kk)
            core.registerBank.pcReg+=2;
    }

    std::string toAsm()const override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SNEVXBYTE_H
