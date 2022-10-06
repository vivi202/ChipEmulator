cmake_minimum_required(VERSION 3.23)
project(ChipInterpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(ChipCore)
add_subdirectory(ChipInterpreter_gtest)
set(CHIP_INTERPRETER_SOURCES
        ChipCore/RegisterBank.cpp ChipCore/RegisterBank.h
        ChipCore/ResettableComponent.h ChipCore/ChipCore.cpp ChipCore/ChipCore.h ChipCore/Instruction.h
        ChipCore/Ram.cpp ChipCore/Ram.h ChipCore/Display.h ChipCore/Keyboard.cpp ChipCore/Keyboard.h
        ChipCore/instructionHelpers.cpp ChipCore/instructionHelpers.h ChipCore/instructionFactories/InstructionFactory.h
        ChipCore/instructionFactories/ZeroInstructionFactory.cpp ChipCore/instructionFactories/ZeroInstructionFactory.h
        ChipCore/instructionFactories/FirstNibbleDecodedInstructionFactory.cpp
        ChipCore/instructionFactories/FirstNibbleDecodedInstructionFactory.h ChipCore/InstructionDecoder.cpp ChipCore/InstructionDecoder.h)
set(INSTRUCTION_SET_SOURCES
        ChipCore/InstructionSet/Cls.h ChipCore/InstructionSet/JpAddr.h ChipCore/InstructionSet/LdVxByte.h
        ChipCore/InstructionSet/AddVxByte.h ChipCore/InstructionSet/LdIAddr.h ChipCore/InstructionSet/DrwVxVyNibble.h ChipCore/InstructionSet/Ret.h ChipCore/InstructionSet/CallAddr.h)

add_library(ChipInterpreter ${CHIP_INTERPRETER_SOURCES} ${INSTRUCTION_SET_SOURCES})