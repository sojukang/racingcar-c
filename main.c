#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modules/car.h"
#include "modules/random.h"

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


int main() {
    setRandomSeed();
    struct Car *cars = getCars(2);
    moveAll(cars);

    printf("%d\n", cars[0].position);
    printf("%d", cars[1].position);
    free(cars);
    return 0;
}
