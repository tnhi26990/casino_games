cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

# Enable testing with CTest
enable_testing()

# Add Google Test submodule
add_subdirectory(external/googletest)

# Include Google Test in your include paths
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define your test executable
add_executable(mines_testing 
    Tests/MinesTests.cpp
    Mines/Controller/MinesController.cpp 
    Mines/Model/MinesModel.cpp 
    Mines/View/MinesView.cpp 
    Player.cpp # Include Player.cpp as it's referenced in MinesController
)

add_executable(roulette_testing
    Tests/RouletteTests.cpp
    Roulette/Controller/RouletteController.cpp
    Roulette/Model/BettingTable.cpp
    Roulette/Model/RouletteWheel.cpp
    Roulette/View/RouletteView.cpp
    Player.cpp
)


# Link Google Test libraries
target_link_libraries(mines_testing gtest gtest_main)
target_link_libraries(roulette_testing gtest gtest_main)

# Add the directory containing uSockets headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/uSockets/src)

# Add the directory containing uWebSockets headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/src)

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
add_executable(backend_server ${SOURCE_FILES})

# Link against the uSockets library
target_link_libraries(backend_server ${CMAKE_CURRENT_SOURCE_DIR}/uWebSockets/uSockets/uSockets.a)

# Link against zlib
find_package(ZLIB REQUIRED)
target_link_libraries(backend_server ZLIB::ZLIB)