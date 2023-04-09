#include <stdbool.h>
#include <stdlib.h>
#include "../random.h"


typedef struct Car {
    int position;
    char *name;
} Car;

Car *getCars(int size, char **carNames) {
    Car *cars = malloc(size * sizeof(Car));
    for (int i = 0; i < size; ++i) {
        cars[i].position = 1;
        cars[i].name = carNames[i];
    }
    return cars;
}

int sizeOf(Car *cars) {
    int i = 0;
    while (cars[i].name != NULL) {
        i++;
    }
    return i;
}

bool canMove(int number) {
    if (number >= 4) {
        return true;
    }
    return false;
}

void move(Car *car) {
    if (canMove(randomNumber(10))) {
        car->position += 1;
    }
}