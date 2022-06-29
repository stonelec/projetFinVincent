//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_POINT_H
#define PROJETFINVINCENT_POINT_H

#include "vector.h"
#include "infoPLanet.h"

struct Point{
    struct Vect* position;
    struct Vect* speed;
    int time;
    struct Point* next;
};
struct Point* createPoint(struct Vect* position, struct Vect* speed, int time );

void printPoint(struct Point* point);

void filePoint(struct Point* point, FILE* file);

void deletePoint(struct Point** point);

#endif //PROJETFINVINCENT_POINT_H