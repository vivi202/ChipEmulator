//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXDT_H
#define CHIPEMULATOR_LDVXDT_H
#include "Instruction.h"
//TODO implement LdVxDt
class LdVxDt : public Instruction{
public:

    explicit LdVxDt(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxDt() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXDT_H