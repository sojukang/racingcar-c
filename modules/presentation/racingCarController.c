#include "../domain/car.h"
#include "response.h"
#include "../application/racingGame.h"
#include "../commons/random.h"
#include "request.h"
#include <stdio.h>


static void runRacing(int gameCount, Car *cars) {
    printf("\n실행 결과\n");
    for (int i = 0; i < gameCount; ++i) {
        printRacingStatus(cars);
        moveAll(cars);
        printf("\n");
    }
    printf("\n");
}

void runGame() {
    setRandomSeed();

    char **carNames = getCarNames();
    int gameCount = getGameCount();
    Car *cars = getCars(arraySize(carNames), carNames);

    runRacing(gameCount, cars);

    bool *isWinners = getIsWinners(cars);
    char **winnerNames = getWinnerNames(cars, isWinners);
    printWinners(winnerNames);

    free(winnerNames);
    free(carNames);
    free(isWinners);
    free(cars);
}
