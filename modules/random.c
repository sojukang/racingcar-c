#include <stdlib.h>
#include <time.h>


void setRandomSeed() {
    srand(time(NULL));
}

int randomNumber(int upperBound) {
    return rand() % upperBound;
}
