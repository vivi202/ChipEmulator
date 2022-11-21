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
#include "SubVxVy.h"
#include "ShrVxVy.h"
#include "LdIAddr.h"
#include "SubnVxVy.h"
#include "ShlVxVy.h"
#include "SneVxVy.h"
#include "JpV0Addr.h"
#include "SkpVx.h"
#include "SknpVx.h"
#include "LdVxDt.h"
#include "LdDtVx.h"
#include "LdStVx.h"
#include "AddIVx.h"
#include "LdBVx.h"
#include "LdIVx.h"
#include "LdVxI.h"
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
    auto addVxVyInstruction= std::make_unique<AddVxVy>(0x8C54);
    addVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],1);
    ASSERT_EQ(core.registerBank[0xC],4);
    core.registerBank[0xC]=20;
    addVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],0);
    ASSERT_EQ(core.registerBank[0xC],60);
}

TEST_F(InstructionTests,SubVxVy){
    core.registerBank[3]=3;
    core.registerBank[5]=6;
    auto subVxVyInstruction=std::make_unique<SubVxVy>(0x8355);
    subVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[3],253);
    ASSERT_EQ(core.registerBank[0xF],0);
    core.registerBank[3]=10;
    subVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[3],4);
    ASSERT_EQ(core.registerBank[0xF],1);
}

TEST_F(InstructionTests,ShrVxVy){
    core.registerBank[3]=0xA1;
    auto shrVxVyInstruction=std::make_unique<ShrVxVy>(0x8236);
    shrVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],1);
    ASSERT_EQ(core.registerBank[2],0x50);
    core.registerBank[3]=0xB0;
    shrVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],0);
    ASSERT_EQ(core.registerBank[2],0x58);
}

TEST_F(InstructionTests,SubnVxVy){
    core.registerBank[6]=10;//Vx
    core.registerBank[3]=5;//Vy
    auto subnVxVyInstruction= std::make_unique<SubnVxVy>(0x8637);
    subnVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],0);
    ASSERT_EQ(core.registerBank[0x6],251);
    core.registerBank[6]=2;
    subnVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],1);
    ASSERT_EQ(core.registerBank[0x6],3);
}

TEST_F(InstructionTests,ShlVxVy){
    core.registerBank[3]=0x80;
    auto shlVxVyInstruction=std::make_unique<ShlVxVy>(0x873E);
    shlVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],1);
    ASSERT_EQ(core.registerBank[0x7],0x00);
    core.registerBank[3]=0x40;
    shlVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0xF],0);
    ASSERT_EQ(core.registerBank[0x7],0x80);
}

TEST_F(InstructionTests,SneVxVy){
    core.registerBank.pcReg=0x300;
    core.registerBank[0x4]=0x44;
    core.registerBank[0x2]=0x22;
    auto sneVxVyInstruction= std::make_unique<SneVxVy>(0x9420);
    sneVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
    core.registerBank[0x2]=0x44;
    sneVxVyInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
}

TEST_F(InstructionTests,LdIAddr){
    uint16_t machineCode=0xA112;
    auto ldIAddrInstruction= std::make_unique<LdIAddr>(machineCode);
    ldIAddrInstruction->execute(core);
    ASSERT_EQ(core.registerBank.iReg,0x112);
}

TEST_F(InstructionTests,JpV0Addr){
    core.registerBank.pcReg=0x200;
    core.registerBank[0]=0x30;
    auto jpV0AddrInstruction=std::make_unique<JpV0Addr>(0xB300);
    jpV0AddrInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x330);
}


TEST_F(InstructionTests,SkpVx){
    core.registerBank[7]=0xA;
    keyboard.pressKey(0xA);
    core.registerBank.pcReg=0x300;
    auto skpVxInstruction=std::make_unique<SkpVx>(0xE79E);
    skpVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
    keyboard.releaseKey(0xA);
    skpVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
}

TEST_F(InstructionTests,SknpVx){
    core.registerBank.pcReg=0x300;
    core.registerBank[8]=0x1;
    keyboard.releaseKey(0x1);
    auto sknpVxInstruction= std::make_unique<SknpVx>(0xE8A1);
    sknpVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
    keyboard.pressKey(0x1);
    sknpVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.pcReg,0x302);
}

TEST_F(InstructionTests,LdVxDt){
    core.registerBank.delay=15;
    auto ldVxDtInstruction = std::make_unique<LdVxDt>(0xF307);
    ldVxDtInstruction->execute(core);
    ASSERT_EQ(core.registerBank[0x3],15);
}

//TODO Fx0A

TEST_F(InstructionTests,LdDtVx){
    core.registerBank[0x4]=30;
    auto ldDtVxInstruction = std::make_unique<LdDtVx>(0xF415);
    ldDtVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.delay,30);
}

TEST_F(InstructionTests,LdStVx){
    core.registerBank[0x6]=22;
    auto ldStVxInstruction=std::make_unique<LdStVx>(0xF618);
    ldStVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.sound,22);
}

TEST_F(InstructionTests,AddIVx){
    core.registerBank.iReg=0x400;
    core.registerBank[0xA]=0x40;
    auto addIVxInstruction=std::make_unique<AddIVx>(0xFA1E);
    addIVxInstruction->execute(core);
    ASSERT_EQ(core.registerBank.iReg,0x440);
}
//TODO Fx29

TEST_F(InstructionTests,LdBVx){
    uint16_t startAddress=0x400;
    core.registerBank[3]=123;
    core.registerBank.iReg=startAddress;
    auto ldBVxInstruction = std::make_unique<LdBVx>(0xF333);
    ldBVxInstruction->execute(core);
    ASSERT_EQ(core.ram.read(startAddress),1);
    ASSERT_EQ(core.ram.read(startAddress+1),2);
    ASSERT_EQ(core.ram.read(startAddress+2),3);
}

TEST_F(InstructionTests,LdIVx){
    uint16_t startAddress=0x300;
    for (int regIndex = 0; regIndex < RegisterBank::GpRegisterNum; ++regIndex) {
        core.registerBank[regIndex]=regIndex;
    }
    core.registerBank.iReg=startAddress;
    auto ldIVxInstruction=std::make_unique<LdIVx>(0xFF55);
    ldIVxInstruction->execute(core);
    for (int addressOffset = 0; addressOffset < RegisterBank::GpRegisterNum; ++addressOffset) {
        ASSERT_EQ(core.ram.read(startAddress+addressOffset),addressOffset);
    }
}

TEST_F(InstructionTests,LdVxI){
    uint16_t startAddress=0x300;
    for (int offset = 0; offset < RegisterBank::GpRegisterNum; ++offset) {
        core.ram.write(startAddress+offset,offset);
    }
    core.registerBank.iReg=startAddress;
    auto ldVxIInstruction = std::make_unique<LdVxI>(0xFF65);
    ldVxIInstruction->execute(core);

    for (int regIndex = 0; regIndex < RegisterBank::GpRegisterNum; ++regIndex) {
        ASSERT_EQ(core.registerBank[regIndex],core.ram.read(startAddress+regIndex));
    }
}


