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

TEST_F(InstructionDecoderTests, ClsDecodingTest) {
    auto decodedInst=decoder.decode(0x00E0);
    auto clsInstruction=dynamic_cast<Cls*>(decodedInst);
    ASSERT_NE(clsInstruction, nullptr);
    delete decodedInst;
}

TEST_F(InstructionDecoderTests, RetDecodingTest) {
    auto decodedInst=decoder.decode(0x00EE);
    auto retInstruction=dynamic_cast<Ret*>(decodedInst);
    ASSERT_NE(retInstruction, nullptr);
    delete decodedInst;
}



TEST_F(InstructionDecoderTests, JpAddrDecodingTest) {
    for (int i = 0x200; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x1000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto jpAddrInstruction=dynamic_cast<JpAddr*>(decodedInst);
        ASSERT_NE(jpAddrInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, CallAddrDecodingTest) {
    for (int i = 0x200; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x2000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto callAddrInstruction=dynamic_cast<CallAddr*>(decodedInst);
        ASSERT_NE(callAddrInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, SeVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x3000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto seVxByteInstruction=dynamic_cast<SeVxByte*>(decodedInst);
        ASSERT_NE(seVxByteInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, SneVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x4000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto sneVxByteInstruction=dynamic_cast<SneVxByte*>(decodedInst);
        ASSERT_NE(sneVxByteInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, SeVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF ; ++i) {
        uint16_t machineCode=0x5000 | (i<<4);
        auto decodedInst=decoder.decode(machineCode);
        auto seVxVyInstruction=dynamic_cast<SeVxVy*>(decodedInst);
        ASSERT_NE(seVxVyInstruction, nullptr);
        delete decodedInst;
    }

}

TEST_F(InstructionDecoderTests, LdVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x6000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxByteInstruction=dynamic_cast<LdVxByte*>(decodedInst);
        ASSERT_NE(ldVxByteInstruction, nullptr);
        delete decodedInst;
    }
}

TEST_F(InstructionDecoderTests, AddVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF; ++i) {
        uint16_t machineCode=0x7000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto addVxByteInstruction=dynamic_cast<AddVxByte*>(decodedInst);
        ASSERT_NE(addVxByteInstruction, nullptr);
        delete decodedInst;
    }
}
//TODO LogicArithmeticInstructions
TEST_F(InstructionDecoderTests, LdVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8001 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxVyInstruction=dynamic_cast<LdVxVy*>(decodedInst);
        ASSERT_NE(ldVxVyInstruction, nullptr);
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



