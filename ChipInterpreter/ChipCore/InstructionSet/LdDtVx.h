//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDDTVX_H
#define CHIPEMULATOR_LDDTVX_H
#include "Instruction.h"
//TODO implement LdDtVx
class LdDtVx : public Instruction{
public:
    explicit LdDtVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdDtVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDDTVX_H