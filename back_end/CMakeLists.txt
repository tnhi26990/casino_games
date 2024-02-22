cmake_minimum_required(VERSION 3.24)
project(back_end)

set(CMAKE_CXX_STANDARD 14)

add_executable(back_end
        Casino.cpp
        CoinGame.cpp
        Driver.cpp
        Player.cpp
        CasinoInterface.cpp
        )
