cmake_minimum_required(VERSION 3.20)
project(comp_arch_5)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(comp_arch_5
        src/warrior.cpp src/warrior.h src/Game.cpp src/Game.h src/main.cpp)

target_link_libraries(comp_arch_5 PRIVATE Threads::Threads)