#include <stdio.h>
#include "../arraytools.h"
#include "../racingGame.h"

void printCurrentPosition(char progressView, int position) {
    for (int i = 0; i < position; ++i) {
        printf("%c", progressView);
    }
}

void printWinners(char *winnerNames[]) {
    char *winnerNameDisplayForm = join(winnerNames, ",", arraySize(winnerNames));
    printf("%s가 최종 우승하였습니다.", winnerNameDisplayForm);
    free(winnerNameDisplayForm);
}

void printRacingStatus(Car *cars) {
    int size = sizeOf(cars);
    for (int i = 0; i < size; ++i) {
        printf("%s : ", cars[i].name);
        printCurrentPosition('-', cars[i].position);
        printf("\n");
    }
}