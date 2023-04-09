cmake_minimum_required(VERSION 3.25)
project(racingcar C)

set(CMAKE_C_STANDARD 23)

add_executable(racingcar main.c modules/domain/car.h modules/presentation/response.h modules/racingGame.h modules/random.c modules/arraytoos.c modules/presentation/response.c)
add_subdirectory(modules)
add_subdirectory(tests)

