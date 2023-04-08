#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *requestCarNames() {
    char *input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    return input;
}

int getNumberOfCarNames(const char *carNames) {
    int count = 1;
    for (int i = 0; i < carNames[i] != '\0'; ++i) {
        if (carNames[i] == ',') {
            count++;
        }
    }
    return count;
}

char **splitCarNames(char *string, int size) {
    char **carNames = malloc(size * sizeof(char *));
    char *carName = strtok(string, ",");
    int i = 0;
    while (carName != NULL && i < size) {
        carNames[i++] = strdup(carName);
        carName = strtok(NULL, ",");
    }
    return carNames;
}

char **getCarNames() {
    printf("경주할 자동차 이름을 입력하세요(이름은 쉼표(,)를 기준으로 구분).\n");
    char *request = requestCarNames();
    int count = getNumberOfCarNames(request);
    char **carNames = splitCarNames(request, count);
    free(request);
    return carNames;
}

int getGameCount() {
    printf("시도할 회수는 몇회인가요?\n");
    int count;
    scanf("%d", &count);
    return count;
}