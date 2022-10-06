//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_CALLADDR_H
#define CHIPEMULATOR_CALLADDR_H

#include "Instruction.h"
//TODO Implement CallAddr
class CallAddr: public Instruction{
public:
    explicit CallAddr(uint16_t machineCode): Instruction(machineCode){};

    ~CallAddr() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_CALLADDR_H
