cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        Roulette/Model/RouletteWheel.cpp
        Roulette/Model/BettingTable.cpp
        Roulette/View/RouletteView.cpp
        Roulette/Controller/RouletteController.cpp
        Roulette/Driver.cpp)