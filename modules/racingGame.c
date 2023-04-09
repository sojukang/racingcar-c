#include "domain/car.h"
#include "presentation/response.h"
#include <stdlib.h>
#include <stdio.h>

void moveAll(Car cars[]) {
    int count = sizeOf(cars);
    for (int i = 0; i < count; ++i) {
        move(&cars[i]);
    }
}

bool *getIsWinners(Car cars[]) {
    int size = sizeOf(cars);
    int maxPosition = cars[0].position;
    for (int i = 0; i < size; ++i) {
        if (cars[i].position > maxPosition) {
            maxPosition = cars[i].position;
        }
    }

    int maxCount = 0;
    for (int i = 0; i < size; ++i) {
        if (cars[i].position == maxPosition) {
            maxCount++;
        }
    }

    bool *isWinners = malloc(size * sizeof(bool));

    for (int i = 0; i < size; ++i) {
        if (cars[i].position == maxPosition) {
            isWinners[i] = true;
        } else {
            isWinners[i] = false;
        }
    }
    return isWinners;
}

void runRacing(int gameCount, Car *cars) {
    printf("\n실행 결과\n");
    for (int i = 0; i < gameCount; ++i) {
        printRacingStatus(cars);
        moveAll(cars);
        printf("\n");
    }
    printf("\n");
}

char **getWinnerNames(const Car *cars, const bool *isWinners) {
    int winnerCount = 0;
    size_t sizeOfIsWinners = (sizeof(&isWinners) / sizeof(isWinners[0]));
    for (int i = 0; i < sizeOfIsWinners; ++i) {
        if (isWinners[i]) {
            winnerCount++;
        }
    }

    char **winnerNames = malloc(winnerCount * sizeof(char *));
    int j = 0;
    for (int i = 0; i < sizeOfIsWinners; ++i) {
        if (isWinners[i]) {
            winnerNames[j] = cars[i].name;
        }
    }
    return winnerNames;
}