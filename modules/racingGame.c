#include "domain/car.h"
#include "arraytools.h"
#include "presentation/response.h"
#include <stdlib.h>
#include <stdio.h>

void moveAll(struct Car cars[]) {
    int count = sizeOf(cars);
    for (int i = 0; i < count; ++i) {
        move(&cars[i]);
    }
}

bool *getIsWinners(struct Car cars[]) {
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

void runRacing(char **carNames, int gameCount, struct Car *cars) {
    printf("\n실행 결과\n");
    for (int i = 0; i < gameCount; ++i) {
        for (int j = 0; j < arraySize(carNames); ++j) {
            printf("%s : ", cars[j].name);
            printCurrentPosition('-', cars[j].position);
            printf("\n");
        }
        moveAll(cars);
        printf("\n");
    }
}

char **getWinnerNames(const struct Car *cars, const bool *isWinners) {
    int winnerCount = 0;
    for (int i = 0; i < ARRAY_SIZE(isWinners); ++i) {
        if (isWinners[i]) {
            winnerCount++;
        }
    }

    char **winnerNames = malloc(winnerCount * sizeof(char *));
    int j = 0;
    for (int i = 0; i < ARRAY_SIZE(isWinners); ++i) {
        if (isWinners[i]) {
            winnerNames[j] = cars[i].name;
        }
    }
    return winnerNames;
}