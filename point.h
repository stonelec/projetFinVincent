//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_POINT_H
#define PROJETFINVINCENT_POINT_H

#include "vector.h"
#include "infoPLanet.h"

struct point{
    struct vect* position;
    struct vect* speed;
    int time;
    struct point* next;
};
struct point* createPoint(struct vect* position, struct vect* speed, int time );

void printPoint(struct point* point);

#endif //PROJETFINVINCENT_POINT_H