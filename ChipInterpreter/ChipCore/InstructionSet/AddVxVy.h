//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_ADDVXVY_H
#define CHIPEMULATOR_ADDVXVY_H
#include "Instruction.h"
class AddVxVy : public Instruction{
public:

    explicit AddVxVy(uint16_t machineCode): Instruction(machineCode){};

    ~AddVxVy() override = default;

    void execute(ChipCore &core) override {
        uint16_t sum;
        sum=core.registerBank[x]+core.registerBank[y];
        core.registerBank[x]=static_cast<uint8_t>(sum);
        if(sum > 255){//overflow detected
            core.registerBank[0xF]=1;
        }else{
            core.registerBank[0xF]=0;
        }
    }

    std::string toAsm() override {
        return {""};
    }
};


#endif //CHIPEMULATOR_ADDVXVY_H
