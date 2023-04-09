#include <stdio.h>
#include "../commons/arrayTools.h"
#include "../application/racingGame.h"

static void printCurrentPosition(char progressView, int position) {
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
        PRINT_NEW_LINE;
    }
}