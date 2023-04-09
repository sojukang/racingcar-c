#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modules/car.h"
#include "modules/random.h"
#include "modules/request.h"

#define ARRAY_SIZE(array) (sizeof(&array) / sizeof(array[0]))

bool canMove(int number) {
    if (number >= 4) {
        return true;
    }
    return false;
}

void move(struct Car *car) {
    if (canMove(randomNumber())) {
        car->position += 1;
    }
}

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

int arraySize(char **pString) {
    int size = 0;
    while (pString[size] != NULL && strlen(pString[size]) > 0) {
        size++;
    }
    return size;
}

int main() {
    setRandomSeed();

    char **carNames = getCarNames();
    int gameCount = getGameCount();
    struct Car *cars = getCars(arraySize(carNames), carNames);

    for (int i = 0; i < gameCount; ++i) {
        moveAll(cars);
    }

    for (int j = 0; j < arraySize(carNames); ++j) {
        printf("%s : %d\n", cars[j].name, cars[j].position);
    }
    printf("\n\n");

    bool *isWinners = getIsWinners(cars);
    for (int i = 0; i < ARRAY_SIZE(isWinners); ++i) {
        if (isWinners[i] == true) {
            printf("winner: %s\n", cars[i].name);
        }
    }

    free(carNames);
    free(isWinners);
    free(cars);
    return 0;
}
