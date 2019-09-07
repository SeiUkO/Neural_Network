cmake_minimum_required(VERSION 3.14)
project(Neural_Network LANGUAGES C CXX CUDA)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(include)

add_executable(game lib/glad.c src/main.cc src/game/Engine.cc src/game/Engine.hh src/game/Entity.cc src/game/Entity.hh src/game/Entity.cc src/game/Entity.hh src/game/Entity.cc src/game/Entity.hh src/game/Game.cc src/game/Game.hh src/game/Controller.cc src/game/Controller.hh src/game/Action.cc src/game/Action.hh src/game/Action.cc src/game/Action.hh src/render/Window.cc src/render/Window.hh)

target_link_libraries(game -ldl -lGL -lGLU -lglfw)
