//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TRAJECTOIRE_H
#define PROJETFINVINCENT_TRAJECTOIRE_H

#include "infoPLanete.h"
#include "queueliste.h"
#include "point.h"

void firstPoint(struct Queue* newTraj,double demieGrandAxe, double exentricite,int temps,  bool valid);

struct Queue* createTrajectoire(double masse, double demieGrandAxe, double exentricite);

struct vect* position(struct vect*  positionPost, struct vect*  vitessePost);

struct vect* acceleration(struct vect* positionPlanete);

struct vect* vitesse(struct vect*  vitessePost, struct vect*  accelerationPost);
/*
double energiePotentielle(double massePlanete, struct vect* positionPlanete);

double energieCinetique(double massePlanete, struct vect* vitesse);

double energieTotale(double massePlanete, struct vect* positionPlanete, struct vect* vitesse);
*/

#endif //PROJETFINVINCENT_TRAJECTOIRE_H