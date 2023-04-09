#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modules/domain/car.h"
#include "modules/random.h"
#include "modules/presentation/request.h"
#include "modules/arraytools.h"
#include "modules/racingGame.h"

#define ARRAY_SIZE(array) (sizeof(&array) / sizeof(array[0]))

void printWinners(const struct Car *cars, bool **isWinners);

int main() {
    setRandomSeed();

    char **carNames = getCarNames();
    int gameCount = getGameCount();
    struct Car *cars = getCars(arraySize(carNames), carNames);

    printRacingStatus(carNames, gameCount, cars);

    bool *isWinners = getIsWinners(cars);
    printWinners(cars, &isWinners);

    free(carNames);
    free(isWinners);
    free(cars);
    return 0;
}

void printWinners(const struct Car *cars, bool **isWinners) {
    for (int i = 0; i < ARRAY_SIZE((*isWinners)); ++i) {
        if ((*isWinners)[i] == true) {
            printf("%s, ", cars[i].name);
        }
    }
    printf("가 최종 우승하였습니다.");
}


