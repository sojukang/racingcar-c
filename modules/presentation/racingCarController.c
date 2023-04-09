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
        PRINT_NEW_LINE;
    }
    PRINT_NEW_LINE;
}

void runGame() {
    /*
     * 1. setUp environment
     * 2. request names of cars
     * 3. request racing count
     */
    setRandomSeed();
    char **carNames = getCarNames();
    int gameCount = getGameCount();
    Car *cars = getCars(arraySize(carNames), carNames);

    /*
     * 4. run racing for count
     */
    runRacing(gameCount, cars);

    /*
     * 5. determine winners and present
     */
    bool *isWinners = getIsWinners(cars);
    char **winnerNames = getWinnerNames(cars, isWinners);
    printWinners(winnerNames);

    free(winnerNames);
    free(carNames);
    free(isWinners);
    free(cars);
}
