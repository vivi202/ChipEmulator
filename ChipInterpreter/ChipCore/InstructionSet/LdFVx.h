//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDFVX_H
#define CHIPEMULATOR_LDFVX_H
#include "Instruction.h"
//TODO implement LdFVx
class LdFVx : public Instruction{
public:
    explicit LdFVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdFVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDFVX_H
