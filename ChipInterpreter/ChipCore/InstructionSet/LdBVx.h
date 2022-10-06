//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDBVX_H
#define CHIPEMULATOR_LDBVX_H
#include "Instruction.h"
//TODO implement LdBVx
class LdBVx : public Instruction{
public:

    explicit LdBVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdBVx() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_LDBVX_H
