#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void setRandomSeed() {
    srand(time(NULL));
}

int randomNumber() {
    return rand() % 10;
}

bool canMove(int number) {
    if (number >= 4) {
        return true;
    }
    return false;
}

int move(int position) {
    if (canMove(randomNumber())) {
        return position + 1;
    }
    return position;
}

int main() {
    setRandomSeed();
    printf("%d", move(1));
    return 0;
}
