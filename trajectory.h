//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TRAJECTOIRE_H
#define PROJETFINVINCENT_TRAJECTOIRE_H

#include "infoPLanet.h"
#include "queuelist.h"
#include "point.h"

double init(struct Queue* newTraj, double mass, double demieGrandAxe, double exentricite,int time,  bool valid);

struct Queue* createTrajectoryEuler(double masse, double demieGrandAxe, double exentricite);

struct Queue* createTrajectoryEulerAsymetric(double masse, double demieGrandAxe, double exentricite);


struct Vect* acceleration(struct Vect* positionPlanet);

struct Vect* position(struct Vect*  positionPost, struct Vect*  speedPost);

struct Vect* speed(struct Vect*  speedPost, struct Vect*  accelerationPost);

double energyPotential(double massePlanet, struct Vect* positionPlanet);

double energyKinetic(double massePlanet, struct Vect* speed);

double energyTotal(double massePlanet, struct Vect* positionPlanet, struct Vect* speed);

double calculVariationEnergy (double mass, struct Vect* newPosition, struct Vect* newSpeed, struct Point* lastPoint);

double initMoon( struct Queue* newTraj, double mass, double demieGrandAxe, double exentricite,int time, bool valid);

struct Queue* createTrajectoryEulerSymetricMoon(double mass, double demieGrandAxe, double exentricite);
struct Queue* createTrajectoryEulerAsymetricMoon(double masse, double demieGrandAxe, double exentricite);

struct Vect* accelerationMoon(struct Vect* positionMoon);


#endif //PROJETFINVINCENT_TRAJECTOIRE_H