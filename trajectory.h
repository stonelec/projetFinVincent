//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TRAJECTOIRE_H
#define PROJETFINVINCENT_TRAJECTOIRE_H

#include "infoPLanet.h"
#include "queueliste.h"
#include "point.h"

void firstPoint(struct Queue* newTraj,double demieGrandAxe, double exentricite,int time,  bool valid);

struct Queue* createTrajectory(double masse, double demieGrandAxe, double exentricite);

void firstPointMoon( struct Queue* newTraj,double demieGrandAxe, double exentricite,int time, bool valid);

struct Queue* createTrajectoryMoon(double masse, double demieGrandAxe, double exentricite);

struct vect* acceleration(struct vect* positionPlanet);

struct vect* position(struct vect*  positionPost, struct vect*  speedPost);

struct vect* accelerationMoon(struct vect* positionPlanet);

struct vect* speed(struct vect*  speedPost, struct vect*  accelerationPost);

double energyPotential(double massePlanet, struct vect* positionPlanet);

double energyKinetic(double massePlanet, struct vect* speed);

double energyTotal(double massePlanet, struct vect* positionPlanet, struct vect* speed);


#endif //PROJETFINVINCENT_TRAJECTOIRE_H