#ifndef RACINGGAME_H
#define RACINGGAME_H

#include "domain/car.h"
#include "arraytools.h"
#include "presentation/response.h"
#include <stdlib.h>
#include <stdio.h>

void moveAll(Car cars[]);

bool *getIsWinners(Car cars[]);

void runRacing(int gameCount, Car *cars);

char **getWinnerNames(const Car *cars, const bool *isWinners);

#endif