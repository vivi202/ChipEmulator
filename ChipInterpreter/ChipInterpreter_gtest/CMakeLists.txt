cmake_minimum_required(VERSION 3.22)
project(ChipInterpreter_gtest)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../ChipCore/InstructionSet)

add_executable(ChipInterpreter_test_run ${CHIP_INTERPRETER_SOURCES}
        InstructionTest.cpp
        runTests.cpp
        instructionDecoderTests.cpp)

target_link_libraries(ChipInterpreter_test_run gtest gtest_main ChipInterpreter)
