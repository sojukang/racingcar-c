#ifndef CAR_H
#define CAR_H

#include <stdbool.h>

typedef struct Car {
    int position;
    char *name;
} Car;

Car *getCars(int size, char **carNames);

int sizeOf(Car *cars);

bool canMove(int number);

void move(Car *car);

#endif