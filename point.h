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

struct vect* acceleration(double massePlanete, double constanteG, struct vect* positionPlanete);

double vitesseInitiale(double masseSoleil, double constanteG, double demieGrandAxeOrbite, double exentriciteOrbite);

struct vect* vitesse(struct vect*  vitessePost, struct vect*  accelerationPost, int temps);

struct vect* position(struct vect*  positionPost, struct vect*  vitessePost, int temps);

#endif //PROJETFINVINCENT_POINT_H