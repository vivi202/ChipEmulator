//
// Created by vincenzo on 28/09/22.
//
#include "gtest/gtest.h"
#include "ChipCore.h"
#include "Keyboard.h"
#include "JpAddr.h"
#include "LdVxByte.h"
class InstructionTests : public ::testing::Test {
protected:
    void SetUp() override {
        core.reset();
    }

    void TearDown() override {
    }
protected:
    Keyboard keyboard;
    ChipCore core=ChipCore(nullptr,&keyboard);

};

TEST_F(InstructionTests, jpAddr) {
    auto jpInstruction= std::make_unique<JpAddr>(0x1250);
    jpInstruction->execute(core);
    EXPECT_EQ(core.registerBank.pcReg,0x250);
}

TEST_F(InstructionTests,LdVxByte){
    for (int i = 0; i < RegisterBank::GpRegisterNum; ++i) {
        //construct instruction
        uint16_t machineCode = ((0x60 | i) << 8) | i;
        auto ldVxByteInstruction = std::make_unique<LdVxByte>(machineCode);
        ldVxByteInstruction->execute(core);
    }
    for (int i=0;i<RegisterBank::GpRegisterNum;i++){
        ASSERT_EQ(core.registerBank[i],i);
    }
}
