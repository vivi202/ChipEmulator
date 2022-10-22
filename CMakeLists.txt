cmake_minimum_required(VERSION 3.23)
project(ChipEmulator)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ChipInterpreter)
find_package(SDL2 REQUIRED)
include_directories(ChipInterpreter ChipInterpreter/ChipCore ${SDL2_INCLUDE_DIRS})
add_executable(ChipEmulator main.cpp Window.cpp Window.h SdlChipDisplay.cpp SdlChipDisplay.h DisplayTextureHandler.cpp DisplayTextureHandler.h Drawable.h RenderEngine.cpp RenderEngine.h ChipInterpreterHandler.cpp ChipInterpreterHandler.h KeyBindings.cpp KeyBindings.h)
target_link_libraries(ChipEmulator ${SDL2_LIBRARIES} ChipInterpreter)