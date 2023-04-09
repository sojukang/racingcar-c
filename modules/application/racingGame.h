#ifndef RACING_GAME_H
#define RACING_GAME_H

#include "../domain/car.h"
#include "../commons/arrayTools.h"
#include "../presentation/response.h"
#include <stdlib.h>
#include <stdio.h>

void moveAll(Car cars[]);

bool *getIsWinners(Car cars[]);

char **getWinnerNames(const Car *cars, const bool *isWinners);

#endif