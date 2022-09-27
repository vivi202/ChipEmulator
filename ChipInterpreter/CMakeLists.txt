cmake_minimum_required(VERSION 3.23)
project(ChipInterpreter)

set(CMAKE_CXX_STANDARD 17)

set(CHIP_INTERPRETER_SOURCES
        ChipCore/RegisterBank.cpp ChipCore/RegisterBank.h
        )

add_library(ChipInterpreter ${CHIP_INTERPRETER_SOURCES} )
