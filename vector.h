//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TEST_H
#define PROJETFINVINCENT_TEST_H

#include "infoPLanet.h"

struct vect{
    double x;
    double y;
    double z;
};

struct vect* createVect(double x, double y, double z);

void printVect(struct vect* printable);

struct vect* additionVectors (struct vect* vector1, struct vect* vector2);

struct vect* subtractionVectors (struct vect* vector1, struct vect* vector2);

struct vect* multiplicationVectorsByReal (struct vect* vecteur, double real);

double normeVector (struct vect* vector);

double distance2Vects(struct vect* vector1, struct vect* vector2);

void moduleTest ();



#endif //PROJETFINVINCENT_TEST_H