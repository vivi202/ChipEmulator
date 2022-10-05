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
    auto decodedInst=decoder.decode(0x1222);
    auto jpAddrInstruction=dynamic_cast<JpAddr*>(decodedInst);
    ASSERT_NE(jpAddrInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, LdVxByteDecodingTest) {
    auto decodedInst=decoder.decode(0x6452);
    auto ldVxByteInstruction=dynamic_cast<LdVxByte*>(decodedInst);
    ASSERT_NE(ldVxByteInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, AddVxByteDecodingTest) {
    auto decodedInst=decoder.decode(0x7435);
    auto addVxByteInstruction=dynamic_cast<AddVxByte*>(decodedInst);
    ASSERT_NE(addVxByteInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, LdIAddrDecodingTest) {
    auto decodedInst=decoder.decode(0xA425);
    auto ldIAddrInstruction=dynamic_cast<LdIAddr*>(decodedInst);
    ASSERT_NE(ldIAddrInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, DrwVxVyNibbleDecodingTest) {
    auto decodedInst=decoder.decode(0xD425);
    auto drwVxVyNibbleInstruction=dynamic_cast<DrwVxVyNibble*>(decodedInst);
    ASSERT_NE(drwVxVyNibbleInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, ClsDecodingTest) {
    auto decodedInst=decoder.decode(0x00E0);
    auto clsInstruction=dynamic_cast<Cls*>(decodedInst);
    ASSERT_NE(clsInstruction, nullptr);
    delete decodedInst;
}

