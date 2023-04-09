#include <string.h>
#include <stdlib.h>

int arraySize(char **pString) {
    int size = 0;
    while (pString[size] != NULL && strlen(pString[size]) > 0) {
        size++;
    }
    return size;
}

char *join(char *strings[], char *separator, int count) {
    char *str = NULL;             /* Pointer to the joined strings  */
    size_t total_length = 0;      /* Total length of joined strings */
    int i = 0;                    /* Loop counter                   */

    /* Find total length of joined strings */
    for (i = 0; i < count; i++) total_length += strlen(strings[i]);
    total_length++;     /* For joined string terminator */
    total_length += strlen(separator) * (count - 1); // for separators

    str = (char *) malloc(total_length);  /* Allocate memory for joined strings */
    str[0] = '\0';                      /* Empty string we can append to      */

    /* Append all the strings */
    for (i = 0; i < count; i++) {
        strcat(str, strings[i]);
        if (i < (count - 1)) strcat(str, separator);
    }

    return str;
}