cmake_minimum_required(VERSION 3.25)
project(racingcar C)

set(CMAKE_C_STANDARD 23)

add_executable(racingcar main.c modules/car.h)
add_subdirectory(modules)
add_subdirectory(tests)

