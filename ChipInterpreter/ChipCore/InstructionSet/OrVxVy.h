//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ORVXVY_H
#define CHIPEMULATOR_ORVXVY_H
#include "Instruction.h"
//TODO implement OrVxVy
class OrVxVy : public Instruction{
public:

    explicit OrVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~OrVxVy() override = default;

    void execute(ChipCore &core) override {

    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ORVXVY_H
