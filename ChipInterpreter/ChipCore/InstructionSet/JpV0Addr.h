//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_JPV0ADDR_H
#define CHIPEMULATOR_JPV0ADDR_H
#include "Instruction.h"
//TODO implement Jpv0Addr
class JpV0Addr : public Instruction{
public:

    explicit JpV0Addr(uint16_t machineCode): Instruction(machineCode){};

    ~JpV0Addr() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_JPV0ADDR_H
