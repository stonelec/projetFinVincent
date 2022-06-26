//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TEST_H
#define PROJETFINVINCENT_TEST_H

#include "infoPLanete.h"

struct vect{
    double x;
    double y;
    double z;
};

struct vect* createVect(double x, double y, double z);

void printVect(struct vect* printable);

struct vect* additionVecteurs (struct vect* vecteur1, struct vect* vecteur2);

struct vect* soustractionVecteurs (struct vect* vecteur1, struct vect* vecteur2);

struct vect* multiplicationVecteursParReel (struct vect* vecteur, double reel);

struct vect* multiplicationVecteursParScalaire (struct vect* vecteur, double scalaire);

double normeVecteur (struct vect* vecteur);

double distanceEntre2Vects(struct vect* vecteur1, struct vect* vecteur2);

void moduleTest ();



#endif //PROJETFINVINCENT_TEST_H