//
// Created by vincenzo on 03/10/22.
//

#ifndef CHIPEMULATOR_CLS_H
#define CHIPEMULATOR_CLS_H

#include "Instruction.h"
class Cls : public Instruction{
public:
    void execute(ChipCore &core) override {
        core.display->reset();
    }

    std::string toAsm() override {
        return {"CLS"};
    }
};


#endif //CHIPEMULATOR_CLS_H
