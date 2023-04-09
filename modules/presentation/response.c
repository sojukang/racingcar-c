#include <stdio.h>

void printCurrentPosition(char progressView, int position) {
    for (int i = 0; i < position; ++i) {
        printf("%c", progressView);
    }
}

