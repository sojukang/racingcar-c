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

int main() {
    setRandomSeed();
    struct Car car = {1};
    move(&car);
    printf("%d", car.position);
    return 0;
}
