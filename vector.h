//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TEST_H
#define PROJETFINVINCENT_TEST_H

#include "infoPLanet.h"

struct Vect{
    double x;
    double y;
    double z;
};

struct Vect* createVect(double x, double y, double z);

void printVect(struct Vect* printable);

struct Vect* additionVectors (struct Vect* vector1, struct Vect* vector2);

struct Vect* subtractionVectors (struct Vect* vector1, struct Vect* vector2);

struct Vect* multiplicationVectorsByReal (struct Vect* vecteur, double real);

double normeVector (struct Vect* vector);

double distance2Vects(struct Vect* vector1, struct Vect* vector2);

void deleteVector(struct Vect** vector);

void moduleTest ();



#endif //PROJETFINVINCENT_TEST_H