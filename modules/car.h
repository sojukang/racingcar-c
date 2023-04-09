#ifndef CAR_H
#define CAR_H

struct Car{
    int position;
    char* name;
};

struct Car *getCars(int size, char **carNames) {
    struct Car* cars = malloc(size * sizeof(struct Car));
    for (int i = 0; i < size; ++i) {
        cars[i].position = 1;
        cars[i].name = carNames[i];
    }
    return cars;
}

int sizeOf(struct Car *cars) {
    int i = 0;
    while (cars[i].name != NULL) {
        i++;
    }
    return i;
}
#endif