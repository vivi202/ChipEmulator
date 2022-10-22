//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SHRVXVY_H
#define CHIPEMULATOR_SHRVXVY_H
#include "Instruction.h"

class ShrVxVy : public Instruction{
public:

    explicit ShrVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~ShrVxVy() override = default;

    void execute(ChipCore &core) override {
        core.registerBank[0xF]=core.registerBank[x] & 0x01;//mask lsb
        core.registerBank[x]>>=1;
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SHRVXVY_H
