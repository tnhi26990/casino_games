cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Add the directory containing uSockets headers from your project
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/uSockets/src)

# Add your source files
set(SOURCE_FILES
        Casino.cpp
        Player.cpp
        Roulette/Model/RouletteWheel.cpp
        Roulette/Model/BettingTable.cpp
        Roulette/View/RouletteView.cpp
        Roulette/Controller/RouletteController.cpp
        Roulette/RouletteDriver.cpp
        Mines/Model/MinesModel.cpp
        Mines/Controller/MinesController.cpp
        Mines/View/MinesView.cpp
        Mines/MinesDriver.cpp
        MainDriver.cpp
        )

# Add the executable
add_executable(untitled ${SOURCE_FILES} MainDriver.cpp)

# Link against the uSockets library from your project
target_link_libraries(untitled ${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/uSockets/uSockets.a)

# Link against zlib
find_package(ZLIB REQUIRED)
target_link_libraries(untitled ZLIB::ZLIB)

# Add the directory containing uSockets headers
#include_directories(/Users/adem/uWebSockets/uSockets/src)
#include_directories(/Users/adem/uWebSockets/src)

# Add GoogleTest submodule
add_subdirectory(external/googletest)

# Enable testing with CMake
enable_testing()


# Link against the uSockets library
#target_link_libraries(untitled /Users/adem/uWebSockets/uSockets/uSockets.a)

# Link against zlib
#find_package(ZLIB REQUIRED)
#target_link_libraries(untitled ZLIB::ZLIB)
