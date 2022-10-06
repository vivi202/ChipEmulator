//
// Created by vincenzo on 28/09/22.
//
#include "gtest/gtest.h"
#include "ChipCore.h"
#include "Keyboard.h"
#include "Ret.h"
#include "JpAddr.h"
#include "CallAddr.h"
#include "SeVxByte.h"
#include "SneVxByte.h"
#include "SeVxVy.h"
#include "LdVxByte.h"
#include "AddVxByte.h"
#include "LdVxVy.h"
#include "OrVxVy.h"
#include "AndVxVy.h"
#include "XorVxVy.h"
#include "AddVxVy.h"
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

TEST_F(InstructionTests,Ret) {
    uint16_t callingAddress=0x255;
    core.callStack.push(callingAddress);//push fake address to stack
    auto retInstruction= std::make_unique<Ret>(0x00EE);
    retInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,callingAddress);
}

TEST_F(InstructionTests, jpAddr) {
    auto jpInstruction= std::make_unique<JpAddr>(0x1250);
    jpInstruction->execute(core);
    EXPECT_EQ(core.registerBank.pcReg,0x250);
}

TEST_F(InstructionTests, CallAddr) {
    uint16_t callingAddr=0x220;
    core.registerBank.pcReg=callingAddr;//address that is going to the stack.
    auto callAddrInstruction= std::make_unique<CallAddr>(0x2335);
    callAddrInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x335);
    ASSERT_EQ(core.callStack.empty(), false);
    uint16_t stackAddr=core.callStack.top();
    ASSERT_EQ(callingAddr,stackAddr);
}

TEST_F(InstructionTests, SeVxByte) {
    core.registerBank.pcReg=0x200;
    core.registerBank[0]=0x22;
    auto seVxByteInstruction= std::make_unique<SeVxByte>(0x3022);
    seVxByteInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
    core.registerBank[0]=0x00;
    seVxByteInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
}

TEST_F(InstructionTests, SneVxByte) {
    core.registerBank.pcReg=0x200;
    core.registerBank[0]=0x25;
    auto sneVxByteInstruction= std::make_unique<SneVxByte>(0x4022);
    sneVxByteInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
    core.registerBank[0]=0x22;
    sneVxByteInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
}

TEST_F(InstructionTests, SeVxVy) {
    core.registerBank.pcReg=0x200;
    core.registerBank[0]=0x15;
    core.registerBank[2]=0x15;
    auto seVxVyInstruction= std::make_unique<SeVxVy>(0x5020);
    seVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
    core.registerBank[0]=0x33;
    seVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x202);
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
        ASSERT_EQ(core.registerBank[i],15);
    }
}

TEST_F(InstructionTests,LdVxVy){
    core.registerBank[5]=0x55;
    core.registerBank[1]=0x33;
    auto ldVxVyInstruction=std::make_unique<LdVxVy>(0x8150);
    ldVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[1],0x55);
}

TEST_F(InstructionTests,OrVxVy){
    core.registerBank[3]=0x18;
    core.registerBank[6]=0x63;
    auto orVxVyInstruction=std::make_unique<OrVxVy>(0x8361);
    orVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[3],0x7B);
}

TEST_F(InstructionTests,AndVxVy){
    core.registerBank[7]=0x75;
    core.registerBank[8]=0x26;
    auto andVxVyInstruction= std::make_unique<AndVxVy>(0x8782);
    andVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[7],0x24);
}

TEST_F(InstructionTests,XorVxVy){
    core.registerBank[6]=0x38;
    core.registerBank[0xA]=0x86;
    auto xorVxVyInstruction= std::make_unique<XorVxVy>(0x86A3);
    xorVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[6],0xBE);
}

TEST_F(InstructionTests,AddVxVy){
    core.registerBank[0xC]=220;
    core.registerBank[5]=40;
    auto addVxVyInstruction= std::make_unique<AddVxVy>(0x8C55);
    addVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],1);
    ASSERT_EQ(core.registerBank[0xC],4);
    core.registerBank[0xC]=20;
    addVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],0);
    ASSERT_EQ(core.registerBank[0xC],60);
}

TEST_F(InstructionTests,LdIAddr){
    uint16_t machineCode=0xA112;
    auto ldIAddrInstruction= std::make_unique<LdIAddr>(machineCode);
    ldIAddrInstruction->execute(core);
    ASSERT_EQ(core.registerBank.iReg,0x112);
}


