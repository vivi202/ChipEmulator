cmake_minimum_required(VERSION 3.22)
project(ChipEmulator)
option(BUILD_INTERPRETER_TESTS "Build InterpreterTests" OFF)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(ChipInterpreter)

if(NOT BUILD_INTERPRETER_TESTS)
    find_package(SDL2 REQUIRED)
endif(NOT BUILD_INTERPRETER_TESTS)

include_directories(ChipInterpreter ChipInterpreter/ChipCore ${SDL2_INCLUDE_DIRS})
add_executable(ChipEmulator main.cpp Window.cpp Window.h SdlChipDisplay.cpp SdlChipDisplay.h DisplayTextureHandler.cpp
        DisplayTextureHandler.h Drawable.h RenderEngine.cpp RenderEngine.h ChipInterpreterHandler.cpp
        ChipInterpreterHandler.h KeyBindings.cpp KeyBindings.h SoundEngine.cpp SoundEngine.h Synth/WaveTableSynth.h
        Synth/SineWaveTableSynth.cpp Synth/SineWaveTableSynth.h Synth/SquareWaveTableSynth.cpp
        Synth/SquareWaveTableSynth.h CommandLineArgParser.cpp CommandLineArgParser.h App.cpp App.h)
target_link_libraries(ChipEmulator ${SDL2_LIBRARIES} ChipInterpreter)

enable_testing()
add_test(NAME interpreterTest COMMAND ChipInterpreter_test_run)