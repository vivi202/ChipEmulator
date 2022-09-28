cmake_minimum_required(VERSION 3.23)
project(ChipEmulator)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ChipInterpreter)

include_directories(ChipInterpreter ChipInterpreter/ChipCore)
add_executable(ChipEmulator main.cpp)
target_link_libraries(ChipEmulator ChipInterpreter)