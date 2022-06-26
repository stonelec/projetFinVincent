//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_POINT_H
#define PROJETFINVINCENT_POINT_H

#include "vecteur.h"
#include "infoPLanete.h"

struct point{
    struct vect* position;
    struct vect* vitesse;
    int temps;
    struct point* next;
};
struct point* createPoint(struct vect* position, struct vect* vitesse, int temps);

void printPoint(struct point* point);

#endif //PROJETFINVINCENT_POINT_H