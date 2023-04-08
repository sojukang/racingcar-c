#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "modules/car.h"

void setRandomSeed() {
    srand(time(NULL));
}

int randomNumber() {
    return rand() % 10;
}

bool canMove(int number) {
    if (number >= 4) {
        return true;
    }
    return false;
}

void move(struct Car *car) {
    if (canMove(randomNumber())) {
        car -> position += 1;
    }
}

void moveAll(struct Car cars[]) {
    int count = sizeof(&cars) / sizeof(cars[0]);
    for (int i = 0; i < count; ++i) {
        move(&cars[i]);
    }
}

int main() {
    setRandomSeed();
    struct Car cars[2];
    cars[0].position = 1;
    cars[1].position = 1;

    moveAll(cars);

    printf("%d\n", cars[0].position);
    printf("%d", cars[1].position);
    return 0;
}
