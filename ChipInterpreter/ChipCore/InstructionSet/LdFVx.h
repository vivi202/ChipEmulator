//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_LDFVX_H
#define CHIPEMULATOR_LDFVX_H
#include "Instruction.h"
class LdFVx : public Instruction{
public:
    explicit LdFVx(uint16_t machineCode): Instruction(machineCode){};

    ~LdFVx() override = default;

    void execute(ChipCore &core) override {
        core.registerBank.iReg=Ram::FONT_START_ADDRESS + core.registerBank[x]*Ram::FONT_OFFSET;
    }

    std::string toAsm() override {
        return {""};
    }

};


#endif //CHIPEMULATOR_LDFVX_H
