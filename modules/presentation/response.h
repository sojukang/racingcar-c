#ifndef RESPONSE_H
#define RESPONSE_H
#define PRINT_NEW_LINE printf("\n")

static void printCurrentPosition(char progressView, int position);

void printWinners(char **winnerNames);

void printRacingStatus(Car *cars);

#endif