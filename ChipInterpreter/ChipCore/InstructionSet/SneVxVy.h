//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SNEVXVY_H
#define CHIPEMULATOR_SNEVXVY_H
#include "Instruction.h"
class SneVxVy : public Instruction{
public:
    explicit SneVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SneVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SNEVXVY_H
