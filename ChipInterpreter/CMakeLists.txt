cmake_minimum_required(VERSION 3.23)
project(ChipInterpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(ChipCore)
add_subdirectory(ChipInterpreter_gtest)
set(CHIP_INTERPRETER_SOURCES
        ChipCore/RegisterBank.cpp ChipCore/RegisterBank.h
        ChipCore/ResettableComponent.h ChipCore/ChipCore.cpp
        ChipCore/ChipCore.h ChipCore/Instruction.h
        ChipCore/Ram.cpp ChipCore/Ram.h ChipCore/Display.h
        ChipCore/Keyboard.cpp ChipCore/Keyboard.h
        ChipCore/instructionHelpers.cpp ChipCore/instructionHelpers.h
        ChipCore/instructionFactories/InstructionFactory.h ChipCore/instructionFactories/ZeroInstructionFactory.cpp
        ChipCore/instructionFactories/ZeroInstructionFactory.h
        ChipCore/instructionFactories/FirstNibbleDecodedInstructionFactory.cpp
        ChipCore/instructionFactories/FirstNibbleDecodedInstructionFactory.h
        ChipCore/InstructionDecoder.cpp ChipCore/InstructionDecoder.h
        ChipCore/instructionFactories/ArithmeticInstructionFactory.cpp
        ChipCore/instructionFactories/ArithmeticInstructionFactory.h
        ChipCore/instructionFactories/EInstructionFactory.cpp ChipCore/instructionFactories/EInstructionFactory.h
        ChipCore/instructionFactories/FInstructionFactory.cpp ChipCore/instructionFactories/FInstructionFactory.h ChipInterpreter.cpp ChipInterpreter.h)
set(INSTRUCTION_SET_SOURCES
        ChipCore/InstructionSet/Cls.h ChipCore/InstructionSet/JpAddr.h
        ChipCore/InstructionSet/LdVxByte.h ChipCore/InstructionSet/AddVxByte.h
        ChipCore/InstructionSet/LdIAddr.h ChipCore/InstructionSet/DrwVxVyNibble.h
        ChipCore/InstructionSet/Ret.h ChipCore/InstructionSet/CallAddr.h
        ChipCore/InstructionSet/SeVxByte.h ChipCore/InstructionSet/SneVxByte.h
        ChipCore/InstructionSet/SeVxVy.h ChipCore/InstructionSet/LdVxVy.h
        ChipCore/InstructionSet/OrVxVy.h ChipCore/InstructionSet/AndVxVy.h
        ChipCore/InstructionSet/XorVxVy.h ChipCore/InstructionSet/AddVxVy.h
        ChipCore/InstructionSet/SubVxVy.h ChipCore/InstructionSet/ShrVxVy.h
        ChipCore/InstructionSet/SubnVxVy.h ChipCore/InstructionSet/ShlVxVy.h
        ChipCore/InstructionSet/SneVxVy.h ChipCore/InstructionSet/JpV0Addr.h
        ChipCore/InstructionSet/RndVxByte.h ChipCore/InstructionSet/SkpVx.h
        ChipCore/InstructionSet/SknpVx.h ChipCore/InstructionSet/LdVxDt.h
        ChipCore/InstructionSet/LdVxK.h ChipCore/InstructionSet/LdDtVx.h
        ChipCore/InstructionSet/LdStVx.h ChipCore/InstructionSet/AddIVx.h
        ChipCore/InstructionSet/LdFVx.h ChipCore/InstructionSet/LdBVx.h
        ChipCore/InstructionSet/LdIVx.h ChipCore/InstructionSet/LdVxI.h)

add_library(ChipInterpreter ${CHIP_INTERPRETER_SOURCES} ${INSTRUCTION_SET_SOURCES})