#include <stdlib.h>
#include <stdbool.h>
#include "modules/domain/car.h"
#include "modules/random.h"
#include "modules/presentation/request.h"
#include "modules/arraytools.h"
#include "modules/racingGame.h"

int main() {
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
    return 0;
}


