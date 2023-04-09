cmake_minimum_required(VERSION 3.25)
project(racingcar C)

set(CMAKE_C_STANDARD 23)

add_executable(racingcar main.c modules/domain/car.h modules/presentation/response.h modules/application/racingGame.h modules/commons/random.c modules/commons/arrayTools.c modules/presentation/response.c modules/domain/car.c modules/application/racingGame.c modules/presentation/racingCarController.c modules/presentation/racingCarController.h)
add_subdirectory(modules)
add_subdirectory(tests)

