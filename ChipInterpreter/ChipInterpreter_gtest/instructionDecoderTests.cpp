//
// Created by vincenzo on 05/10/22.
//
#include "gtest/gtest.h"
#include "InstructionDecoder.h"
#include "Instruction.h"
class InstructionDecoderTests : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
protected:
    InstructionDecoder decoder= InstructionDecoder();
};

TEST_F(InstructionDecoderTests, JpAddrDecodingTest) {
    for (int i = 0x200; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x1000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto jpAddrInstruction=dynamic_cast<JpAddr*>(decodedInst);
        ASSERT_NE(jpAddrInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, LdVxByteDecodingTest) {
    for (int i = 0; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x6000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxByteInstruction=dynamic_cast<LdVxByte*>(decodedInst);
        ASSERT_NE(ldVxByteInstruction, nullptr);
        delete decodedInst;
    }
}

TEST_F(InstructionDecoderTests, AddVxByteDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0x7000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto addVxByteInstruction=dynamic_cast<AddVxByte*>(decodedInst);
        ASSERT_NE(addVxByteInstruction, nullptr);
        delete decodedInst;
    }
}

TEST_F(InstructionDecoderTests, LdIAddrDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xA000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto ldIAddrInstruction=dynamic_cast<LdIAddr*>(decodedInst);
        ASSERT_NE(ldIAddrInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, DrwVxVyNibbleDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xD000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto drwVxVyNibbleInstruction=dynamic_cast<DrwVxVyNibble*>(decodedInst);
        ASSERT_NE(drwVxVyNibbleInstruction, nullptr);
        delete decodedInst;
    }
}

TEST_F(InstructionDecoderTests, ClsDecodingTest) {
    auto decodedInst=decoder.decode(0x00E0);
    auto clsInstruction=dynamic_cast<Cls*>(decodedInst);
    ASSERT_NE(clsInstruction, nullptr);
    delete decodedInst;
}

