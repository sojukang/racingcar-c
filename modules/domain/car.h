#ifndef CAR_H
#define CAR_H

#include <stdbool.h>
struct Car {
    int position;
    char *name;
};

struct Car *getCars(int size, char **carNames);

int sizeOf(struct Car *cars);

bool canMove(int number);

void move(struct Car *car);

#endif