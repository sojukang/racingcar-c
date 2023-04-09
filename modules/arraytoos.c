#include <string.h>

int arraySize(char **pString) {
    int size = 0;
    while (pString[size] != NULL && strlen(pString[size]) > 0) {
        size++;
    }
    return size;
}
