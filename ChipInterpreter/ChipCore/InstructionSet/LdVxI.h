//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDVXI_H
#define CHIPEMULATOR_LDVXI_H
#include "Instruction.h"
//TODO implement LdVxI
class LdVxI : public Instruction{
public:

    explicit LdVxI(uint16_t machineCode): Instruction(machineCode){};

    ~LdVxI() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDVXI_H
