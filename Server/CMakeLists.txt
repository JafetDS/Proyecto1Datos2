cmake_minimum_required(VERSION 3.20)
project(PruebaCliente)

set(CMAKE_CXX_STANDARD 14)

link_libraries(ws2_32)
add_executable(PruebaCliente main.cpp Server.cpp Server.h Node.cpp Node.h Matriz.cpp Matriz.h Game.cpp Game.h cmake-build-debug/Memory.cpp cmake-build-debug/Memory.h)

