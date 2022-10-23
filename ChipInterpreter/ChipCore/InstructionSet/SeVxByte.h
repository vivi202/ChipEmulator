//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SEVXBYTE_H
#define CHIPEMULATOR_SEVXBYTE_H
#include "Instruction.h"

class SeVxByte : public Instruction{
public:

    explicit SeVxByte(uint16_t machineCode): Instruction(machineCode){};

    ~SeVxByte() override = default;

    void execute(ChipCore &core) override {
        if(core.registerBank[x] == kk)
            core.registerBank.pcReg+=2;
    }

    std::string toAsm()const override {
        return {""};
    }

};


#endif //CHIPEMULATOR_SEVXBYTE_H
