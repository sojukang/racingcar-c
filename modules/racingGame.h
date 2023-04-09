#ifndef RACINGGAME_H
#define RACINGGAME_H

#include "domain/car.h"
#include "arraytools.h"
#include "presentation/response.h"
#include <stdlib.h>
#include <stdio.h>

void moveAll(struct Car cars[]);

bool *getIsWinners(struct Car cars[]);

void runRacing(int gameCount, struct Car *cars);

char **getWinnerNames(const struct Car *cars, const bool *isWinners);

#endif