#include <stdlib.h>
#include <time.h>

void setRandomSeed() {
    srand(time(NULL));
}

int randomNumber() {
    return rand() % 10;
}
