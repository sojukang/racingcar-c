#include <stdio.h>
#include "../racingGame.h"

void printCurrentPosition(char progressView, int position) {
    for (int i = 0; i < position; ++i) {
        printf("%c", progressView);
    }
}

void printWinners(char **winnerNames) {
    for (int i = 0; i < arraySize(winnerNames); ++i) {
        printf("%s, ", winnerNames[i]);
    }
    printf("가 최종 우승하였습니다.");
}

void printRacingStatus(struct Car *cars) {
    int size = sizeOf(cars);
    for (int i = 0; i < size; ++i) {
        printf("%s : ", cars[i].name);
        printCurrentPosition('-', cars[i].position);
        printf("\n");
    }
}