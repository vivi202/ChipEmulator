cmake_minimum_required(VERSION 3.23)
project(ChipInterpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(ChipCore)
add_subdirectory(ChipInterpreter_gtest)
set(CHIP_INTERPRETER_SOURCES
        ChipCore/RegisterBank.cpp ChipCore/RegisterBank.h
        ChipCore/ResettableComponent.h ChipCore/ChipCore.cpp ChipCore/ChipCore.h ChipCore/Instruction.h ChipCore/Ram.cpp ChipCore/Ram.h ChipCore/Display.h ChipCore/Keyboard.cpp ChipCore/Keyboard.h)

add_library(ChipInterpreter ${CHIP_INTERPRETER_SOURCES})