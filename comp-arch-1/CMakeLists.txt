cmake_minimum_required(VERSION 3.0)

project(
        comp-arch-1
        VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC
        "src/*.h"
        "src/*.cpp"
        )

add_executable(matrix ${SRC})
