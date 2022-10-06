//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXK_H
#define CHIPEMULATOR_LDVXK_H
#include "Instruction.h"
//TODO implement LdVxK
class LdVxK : public Instruction{
public:

    explicit LdVxK(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxK() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXK_H
