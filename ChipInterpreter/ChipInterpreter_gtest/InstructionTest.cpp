//
// Created by vincenzo on 28/09/22.
//
#include "gtest/gtest.h"
#include "ChipCore.h"
#include "Keyboard.h"
#include "JpAddr.h"
#include "LdVxByte.h"
#include "AddVxByte.h"
#include "LdIAddr.h"
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
        EXPECT_EQ(core.registerBank[i],i);
    }
}
TEST_F(InstructionTests,AddVxByte){
    for (int i = 0; i < RegisterBank::GpRegisterNum; ++i) {
        core.registerBank[i]=10;
    }

    for (int i = 0; i < RegisterBank::GpRegisterNum; ++i) {
        uint16_t machineCode=((0x70 | i) << 8) | 0x5 ;
        auto addVxByteInstruction=std::make_unique<AddVxByte>(machineCode);
        addVxByteInstruction->execute(core);
    }
    for (int i = 0; i < RegisterBank::GpRegisterNum; ++i) {
        EXPECT_EQ(core.registerBank[i],15);
    }

}

TEST_F(InstructionTests,LdIAddr){
    uint16_t machineCode=0xA112;
    auto ldIAddrInstruction= std::make_unique<LdIAddr>(machineCode);
    ldIAddrInstruction->execute(core);
    EXPECT_EQ(core.registerBank.iReg,0x112);
}


