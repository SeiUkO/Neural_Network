cmake_minimum_required(VERSION 3.14)
project(Neural_Network)

set(CMAKE_CXX_STANDARD 17)

add_executable(game src/main.cpp src/game/Engine.cc src/game/Engine.hh)

