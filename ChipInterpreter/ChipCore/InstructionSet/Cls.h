//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_CLS_H
#define CHIPEMULATOR_CLS_H

#include "Instruction.h"
class Cls : public Instruction{
public:
    explicit Cls(uint16_t machineCode): Instruction(machineCode){};

    ~Cls() override = default;

    void execute(ChipCore &core) override {
        core.display->reset();
    }

    std::string toAsm() const override {
        return {"CLS"};
    }
};


#endif //CHIPEMULATOR_CLS_H
