//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ADDIVX_H
#define CHIPEMULATOR_ADDIVX_H
#include "Instruction.h"
//TODO implement AddIVx
class AddIVx: public Instruction{
public:

    explicit AddIVx(uint16_t machineCode): Instruction(machineCode){};

    ~AddIVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ADDIVX_H
