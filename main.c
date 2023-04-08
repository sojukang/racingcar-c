#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modules/car.h"
#include "modules/random.h"
#include <string.h>

#define ARRAY_SIZE(array) (sizeof(&array) / sizeof((array)[0]))

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
    int count = sizeof(&cars) / sizeof(cars[0]);
    for (int i = 0; i < count; ++i) {
        move(&cars[i]);
    }
}

bool *getIsWinners(struct Car cars[]) {
    int size = sizeof(&cars) / sizeof(cars[0]);
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

char* getCarNames() {
    char* input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    return input;
}

int main() {
    setRandomSeed();
    printf("경주할 자동차 이름을 입력하세요(이름은 쉼표(,)를 기준으로 구분).\n");
    char *carNames = getCarNames();

    struct Car *cars = getCars(2);
    moveAll(cars);

    printf("%d\n", cars[0].position);
    printf("%d\n\n", cars[1].position);

    bool *isWinners = getIsWinners(cars);
    for (int i = 0; i < ARRAY_SIZE(isWinners); ++i) {
        if (isWinners[i] == true) {
            printf("%d\n", i);
        }
    }
    free(isWinners);
    free(cars);
    free(carNames);
    return 0;
}
