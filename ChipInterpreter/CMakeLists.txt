cmake_minimum_required(VERSION 3.23)
project(ChipInterpreter)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(ChipInterpreter_gtest)
include_directories(ChipCore)
set(CHIP_INTERPRETER_SOURCES
        ChipCore/RegisterBank.cpp ChipCore/RegisterBank.h
        ChipCore/ResettableComponent.h ChipCore/ChipCore.cpp ChipCore/ChipCore.h ChipCore/Instruction.h)

add_library(ChipInterpreter ${CHIP_INTERPRETER_SOURCES})