#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H
#define ARRAY_SIZE(array) (sizeof(&array) / sizeof(array[0]))

int arraySize(char **pString);

#endif