//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_RET_H
#define CHIPEMULATOR_RET_H
#include "Instruction.h"
//TODO Implement Ret
class Ret : public Instruction{
public:

    explicit Ret(uint16_t machineCode): Instruction(machineCode){};

    ~Ret() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_RET_H
