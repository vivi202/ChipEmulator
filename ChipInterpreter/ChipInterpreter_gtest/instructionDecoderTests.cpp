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
    auto clsInstruction=dynamic_cast<Cls*>(decodedInst.get());
    ASSERT_NE(clsInstruction, nullptr);
}

TEST_F(InstructionDecoderTests, RetDecodingTest) {
    auto decodedInst=decoder.decode(0x00EE);
    auto retInstruction=dynamic_cast<Ret*>(decodedInst.get());
    ASSERT_NE(retInstruction, nullptr);
}



TEST_F(InstructionDecoderTests, JpAddrDecodingTest) {
    for (int i = 0x200; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x1000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto jpAddrInstruction=dynamic_cast<JpAddr*>(decodedInst.get());
        ASSERT_NE(jpAddrInstruction, nullptr);
    }

}

TEST_F(InstructionDecoderTests, CallAddrDecodingTest) {
    for (int i = 0x200; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x2000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto callAddrInstruction=dynamic_cast<CallAddr*>(decodedInst.get());
        ASSERT_NE(callAddrInstruction, nullptr);
    }

}

TEST_F(InstructionDecoderTests, SeVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x3000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto seVxByteInstruction=dynamic_cast<SeVxByte*>(decodedInst.get());
        ASSERT_NE(seVxByteInstruction, nullptr);
    }

}

TEST_F(InstructionDecoderTests, SneVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x4000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto sneVxByteInstruction=dynamic_cast<SneVxByte*>(decodedInst.get());
        ASSERT_NE(sneVxByteInstruction, nullptr);
    }

}

TEST_F(InstructionDecoderTests, SeVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF ; ++i) {
        uint16_t machineCode=0x5000 | (i<<4);
        auto decodedInst=decoder.decode(machineCode);
        auto seVxVyInstruction=dynamic_cast<SeVxVy*>(decodedInst.get());
        ASSERT_NE(seVxVyInstruction, nullptr);
    }

}

TEST_F(InstructionDecoderTests, LdVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF ; ++i) {
        uint16_t machineCode=0x6000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxByteInstruction=dynamic_cast<LdVxByte*>(decodedInst.get());
        ASSERT_NE(ldVxByteInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, AddVxByteDecodingTest) {
    for (int i = 0x000; i <= 0xFFF; ++i) {
        uint16_t machineCode=0x7000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto addVxByteInstruction=dynamic_cast<AddVxByte*>(decodedInst.get());
        ASSERT_NE(addVxByteInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8000 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxVyInstruction=dynamic_cast<LdVxVy*>(decodedInst.get());
        ASSERT_NE(ldVxVyInstruction, nullptr);
    }
}
TEST_F(InstructionDecoderTests, OrVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8001 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto orVxVyInstruction=dynamic_cast<OrVxVy*>(decodedInst.get());
        ASSERT_NE(orVxVyInstruction, nullptr);
    }
}
TEST_F(InstructionDecoderTests, AndVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8002 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto andVxVyInstruction=dynamic_cast<AndVxVy*>(decodedInst.get());
        ASSERT_NE(andVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, XorVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8003 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto xorVxVyInstruction=dynamic_cast<XorVxVy*>(decodedInst.get());
        ASSERT_NE(xorVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, AddVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8004 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto addVxVyInstruction=dynamic_cast<AddVxVy*>(decodedInst.get());
        ASSERT_NE(addVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, SubVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8005 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto subVxVyInstruction=dynamic_cast<SubVxVy*>(decodedInst.get());
        ASSERT_NE(subVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, ShrVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8006 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto shrVxVyInstruction=dynamic_cast<ShrVxVy*>(decodedInst.get());
        ASSERT_NE(shrVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, SubnVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x8007 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto subnVxVyInstruction=dynamic_cast<SubnVxVy*>(decodedInst.get());
        ASSERT_NE(subnVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, ShlVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x800E | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto shlVxVyInstruction=dynamic_cast<ShlVxVy*>(decodedInst.get());
        ASSERT_NE(shlVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, SneVxVyDecodingTest) {
    for (int i = 0x00; i <= 0xFF; ++i) {
        uint16_t machineCode=0x9000 | (i << 4);
        std::cout<<std::hex<<machineCode<<"\n";
        auto decodedInst=decoder.decode(machineCode);
        auto sneVxVyInstruction=dynamic_cast<SneVxVy*>(decodedInst.get());
        ASSERT_NE(sneVxVyInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdIAddrDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xA000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto ldIAddrInstruction=dynamic_cast<LdIAddr*>(decodedInst.get());
        ASSERT_NE(ldIAddrInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, JpV0AddrDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xB000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto jpV0AddrInstruction=dynamic_cast<JpV0Addr*>(decodedInst.get());
        ASSERT_NE(jpV0AddrInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, RndVxByteDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xC000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto RndVxByteInstruction=dynamic_cast<RndVxByte*>(decodedInst.get());
        ASSERT_NE(RndVxByteInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, DrwVxVyNibbleDecodingTest) {
    for (int i = 0; i <= 0xFFF; ++i) {
        uint16_t machineCode=0xD000 | i;
        auto decodedInst=decoder.decode(machineCode);
        auto drwVxVyNibbleInstruction=dynamic_cast<DrwVxVyNibble*>(decodedInst.get());
        ASSERT_NE(drwVxVyNibbleInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, SkpVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xE09E | (i <<8);
        auto decodedInst=decoder.decode(machineCode);
        auto skpVxInstruction=dynamic_cast<SkpVx*>(decodedInst.get());
        ASSERT_NE(skpVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, SknpVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xE0A1 | (i <<8);
        auto decodedInst=decoder.decode(machineCode);
        auto sknpVxInstruction=dynamic_cast<SknpVx*>(decodedInst.get());
        ASSERT_NE(sknpVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdVxDtDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF007 | (i <<8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxDtInstruction=dynamic_cast<LdVxDt*>(decodedInst.get());
        ASSERT_NE(ldVxDtInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdVxKDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF00A | (i <<8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxKInstruction=dynamic_cast<LdVxK*>(decodedInst.get());
        ASSERT_NE(ldVxKInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdDtVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF015 | (i <<8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldDtVxInstruction=dynamic_cast<LdDtVx*>(decodedInst.get());
        ASSERT_NE(ldDtVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdStVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF018 | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldStVxInstruction=dynamic_cast<LdStVx*>(decodedInst.get());
        ASSERT_NE(ldStVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, AddIVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF01E | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto addIVxInstruction=dynamic_cast<AddIVx*>(decodedInst.get());
        ASSERT_NE(addIVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdFVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF029 | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldFVxInstruction=dynamic_cast<LdFVx*>(decodedInst.get());
        ASSERT_NE(ldFVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdBVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF033 | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldBVxInstruction=dynamic_cast<LdBVx*>(decodedInst.get());
        ASSERT_NE(ldBVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdIVxDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF055 | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldIVxInstruction=dynamic_cast<LdIVx*>(decodedInst.get());
        ASSERT_NE(ldIVxInstruction, nullptr);
    }
}

TEST_F(InstructionDecoderTests, LdVxIDecodingTest) {
    for (int i = 0; i <= 0xF; ++i) {
        uint16_t machineCode=0xF065 | (i << 8);
        auto decodedInst=decoder.decode(machineCode);
        auto ldVxIInstruction=dynamic_cast<LdVxI*>(decodedInst.get());
        ASSERT_NE(ldVxIInstruction, nullptr);
    }
}


