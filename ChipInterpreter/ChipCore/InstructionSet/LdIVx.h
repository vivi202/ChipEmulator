//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDIVX_H
#define CHIPEMULATOR_LDIVX_H
#include "Instruction.h"
//TODO implement LdIVx
class LdIVx: public Instruction{
public:

    explicit LdIVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdIVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDIVX_H
