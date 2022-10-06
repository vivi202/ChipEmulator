//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDSTVX_H
#define CHIPEMULATOR_LDSTVX_H
#include "Instruction.h"
//TODO implement LdStVx
class LdStVx : public Instruction{
public:

    explicit LdStVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdStVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDSTVX_H
