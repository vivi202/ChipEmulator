//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_SEVXVY_H
#define CHIPEMULATOR_SEVXVY_H
#include "Instruction.h"
//TODO Implement SeVxVy
class SeVxVy : public Instruction{
public:

    explicit SeVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~SeVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_SEVXVY_H
