#ifndef CAR_H
#define CAR_H

struct Car{
    int position;
};

struct Car* getCars(int size) {
    struct Car* cars = malloc(size * sizeof(struct Car));
    for (int i = 0; i < size; ++i) {
        cars[i].position = 1;
    }
    return cars;
}

#endif