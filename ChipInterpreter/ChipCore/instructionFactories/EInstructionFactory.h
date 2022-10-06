//
// Created by vincenzo on 06/10/22.
//

#ifndef CHIPEMULATOR_EINSTRUCTIONFACTORY_H
#define CHIPEMULATOR_EINSTRUCTIONFACTORY_H

#include "InstructionFactory.h"
#include "InstructionSet/SkpVx.h"
#include "InstructionSet/SknpVx.h"
class EInstructionFactory : public InstructionFactory {
public:
    ~EInstructionFactory() override = default;

    std::unique_ptr<Instruction> createInstruction(uint16_t machineCode) override;
};


#endif //CHIPEMULATOR_EINSTRUCTIONFACTORY_H
