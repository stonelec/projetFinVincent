//
// Created by vince on 23/06/2022.
//

#include "trajectory.h"

void firstPoint( struct Queue* newTraj,double demieGrandAxe, double exentricite,int time, bool valid){
    double xPositionInitial = demieGrandAxe*(1-exentricite);
    double ySpeedInitial = sqrt((CONSTANTE_GRAVITATION*MASSE_SOLEIL*(1+exentricite))/(demieGrandAxe*(1-exentricite)));
    struct vect* positionInitial = createVect(xPositionInitial,0,0);
    struct vect* speedInitial = createVect(0,ySpeedInitial,0);
    enqueue(newTraj, positionInitial, speedInitial, time, &valid);
}

struct Queue* createTrajectory(double masse, double demieGrandAxe, double exentricite){
    struct Queue* newTraj = createEmptyQueue();
    int temps = 0;
    bool valid;
    firstPoint(newTraj,demieGrandAxe,exentricite,temps,&valid);

    while (temps<NBPAS-1) {
        temps++;
        struct vect* newAcceleration = acceleration(newTraj->l->tail->position);
        struct vect* newPosition = position(newTraj->l->tail->position, newTraj->l->tail->speed);
        struct vect* newSpeed = speed(newTraj->l->tail->speed, newAcceleration);

        enqueue(newTraj, newPosition, newSpeed, temps, &valid);
    }
    return newTraj;
}

struct vect* acceleration(struct vect* positionPlanet){
    double reelAcceleration = -((CONSTANTE_GRAVITATION * MASSE_SOLEIL) / (pow(normeVector(positionPlanet),3)));
    return multiplicationVectorsByReal(positionPlanet, reelAcceleration);
}
struct vect* position(struct vect*  positionPost, struct vect* speedPost){
    return additionVectors(positionPost, multiplicationVectorsByReal(speedPost,PAS));
}
struct vect* accelerationMoon(struct vect* positionPlanet){
    double reelAcceleration = -((CONSTANTE_GRAVITATION * MASSE_SOLEIL) / (pow(normeVector(positionPlanet),3)));
    return multiplicationVectorsByReal(positionPlanet, reelAcceleration);
}
struct vect* speed(struct vect*  speedPost, struct vect* accelerationPost){
    return additionVectors(speedPost, multiplicationVectorsByReal(accelerationPost, PAS));
}
/*
double energyPotential(double massePlanet, struct vect* positionPlanet){
    struct vect* positionSoleil = createVect(0,0,0);
    return (CONSTANTE_GRAVITATION*massePlanet*MASSE_SOLEIL) / (pow(distance2Vects(positionPlanet,positionSoleil),2));
}
double energyKinetic(double massePlanet, struct vect* speed){
    return 0.5*(massePlanet * pow(normeVecteur(speed),2));
}

double energyTotal(double massePlanet, struct vect* positionPlanet, struct vect* speed){
    return energyPotential(massePlanet, positionPlanet) + energyKinetic(massePlanet, speed);
}
*/

/*
void firstPointMoon( struct Queue* newTraj,double demieGrandAxe, double exentricite,int time, bool valid){
    double xPositionInitiale = demieGrandAxe*(1-exentricite);
    double yVitesseInitiale = sqrt((CONSTANTE_GRAVITATION*MASSE_SOLEIL*(1+exentricite))/(demieGrandAxe*(1-exentricite)));
    struct vect* positionInitiale = createVect(xPositionInitiale,0,0);
    struct vect* vitesseInitiale = createVect(0,yVitesseInitiale,0);
    enqueue(newTraj, positionInitiale, vitesseInitiale, time, &valid);
}

struct Queue* createTrajectoryMoon(double masse, double demieGrandAxe, double exentricite){
    struct Queue* newTraj = createEmptyQueue();
    int temps = 0;
    bool valid;
    firstPoint(newTraj,demieGrandAxe,exentricite,temps,&valid);

    while (temps<NBPAS) {
        temps++;
        struct vect* newAcceleration = accelerationMoon(newTraj->l->head->position);
        struct vect* newPosition = position(newTraj->l->head->position, newTraj->l->head->speed);
        struct vect* newVitesse = speed(newTraj->l->head->speed, newAcceleration);
        enqueue(newTraj, newPosition, newVitesse, temps, &valid);
    }
    return newTraj;
}
 */