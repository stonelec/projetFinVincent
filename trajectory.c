//
// Created by vince on 23/06/2022.
//

#include "trajectory.h"
//rentrer le point initiale d'une planète et retourner sa variation(ici 1 car pas de différence)
double init( struct Queue* newTraj, double mass, double demieGrandAxe, double exentricite,int time, bool valid){
    double xPositionInitial = demieGrandAxe*(1-exentricite);
    double ySpeedInitial = sqrt((GRAVITATIONAL_CONSTANT*MASS_SUN*(1+exentricite))/(demieGrandAxe*(1-exentricite)));
    struct Vect* positionInitial = createVect(xPositionInitial,0,0);
    struct Vect* speedInitial = createVect(0,ySpeedInitial,0);
    enqueue(newTraj, positionInitial, speedInitial, time, &valid);

    return calculVariationEnergy(mass, positionInitial, speedInitial, newTraj->l->head);
}
//retourner trajectoire planète Euler symétrique
struct Queue* createTrajectoryEuler(double mass, double demieGrandAxe, double exentricite){
    struct Queue* traj = createEmptyQueue();
    int time = 0;
    bool valid;
    double variationEnergy = init(traj, mass, demieGrandAxe,exentricite,time,&valid);
    while (time<NBSTEP) {
        time++;
        struct Point* lastPoint = traj->l->tail;
        struct Vect* newAcceleration = acceleration(lastPoint->position);
        struct Vect* newPosition = position(lastPoint->position,lastPoint->speed);
        struct Vect* newSpeed = speed(lastPoint->speed, newAcceleration);
        deleteVector(&newAcceleration);

        variationEnergy += calculVariationEnergy(mass, newPosition, newSpeed, lastPoint);

        enqueue(traj, newPosition, newSpeed, time, &valid);
    }
    double result = variationEnergy/NBSTEP;
    printf("-> average energy variation : %e\n",result);
    return traj;
}
//retourner trajectoire planète Euler asymétrique
struct Queue* createTrajectoryEulerAsymetric(double mass, double demieGrandAxe, double exentricite){
    struct Queue* traj = createEmptyQueue();
    int time = 0;
    bool valid;
    double variationEnergy = init(traj, mass, demieGrandAxe,exentricite,time,&valid);
    while (time<NBSTEP) {
        time++;
        struct Point* lastPoint = traj->l->tail;
        struct Vect* newPosition = position(lastPoint->position, lastPoint->speed);
        struct Vect* newAcceleration = acceleration(newPosition);
        struct Vect* newSpeed = speed(lastPoint->speed, newAcceleration);
        deleteVector(&newAcceleration);

        variationEnergy += calculVariationEnergy(mass, newPosition, newSpeed, lastPoint);

        enqueue(traj, newPosition, newSpeed, time, &valid);
    }
    double result = variationEnergy/NBSTEP;
    printf("-> average energy variation : %e\n",result);
    return traj;
}
//calcul accélération
struct Vect* acceleration(struct Vect* positionPlanet){
    double reelAcceleration = -((GRAVITATIONAL_CONSTANT * MASS_SUN) / (pow(normeVector(positionPlanet),3)));
    return multiplicationVectorsByReal(positionPlanet, reelAcceleration);
}
//calcul position planète
struct Vect* position(struct Vect*  positionPost, struct Vect* speedPost){
    struct Vect* multiplication = multiplicationVectorsByReal(speedPost,STEP);
    struct Vect* addition = additionVectors(positionPost, multiplication);
    deleteVector(&multiplication);
    return addition;
}
//calcul vitesse
struct Vect* speed(struct Vect*  speedPost, struct Vect* accelerationPost){
    struct Vect* multiplication = multiplicationVectorsByReal(accelerationPost, STEP);
    struct Vect* addition = additionVectors(speedPost, multiplication);
    deleteVector(&multiplication);
    return addition;
}
//calcul de l'énergie potentielle
double energyPotential(double massPlanet, struct Vect* positionPlanet){
    struct Vect* positionSoleil = createVect(0,0,0);
    double result = (GRAVITATIONAL_CONSTANT*massPlanet*MASS_SUN) / (pow(distance2Vects(positionPlanet,positionSoleil),2));
    deleteVector(&positionSoleil);
    return result;
}
//calcul de l'énergie cinétique
double energyKinetic(double massPlanet, struct Vect* speed){
    return 0.5*(massPlanet * pow(normeVector(speed),2));
}
//calcul de l'énergie total
double energyTotal(double massPlanet, struct Vect* positionPlanet, struct Vect* speed){
    return energyPotential(massPlanet, positionPlanet) + energyKinetic(massPlanet, speed);
}
//calcul de la variation d'énergie total
double calculVariationEnergy (double mass, struct Vect* newPosition, struct Vect* newSpeed, struct Point* lastPoint){
    double newEnergy = energyTotal(mass, newPosition, newSpeed);
    double lastEnergy = energyTotal(mass, lastPoint->position, lastPoint->speed);
    double result = lastEnergy/newEnergy;
    return result;
}

//code fonctions pour la lune -------------------------------------------------------------
//retourner trajectoire lune Euler symétrique
struct Queue* createTrajectoryEulerSymetricMoon(double mass, double demieGrandAxe, double exentricite){
    struct Queue* trajMoon = createEmptyQueue();
    int time = 0;
    bool valid;
    double variationEnergy = initMoon(trajMoon, mass, demieGrandAxe,exentricite,time,&valid);
    while (time<NBSTEP) {
        time++;
        struct Point* lastPoint = trajMoon->l->tail;
        struct Vect* newAcceleration = accelerationMoon(lastPoint->position);
        struct Vect* newPosition = position(lastPoint->position,lastPoint->speed);
        struct Vect* newSpeed = speed(lastPoint->speed, newAcceleration);
        deleteVector(&newAcceleration);

        variationEnergy += calculVariationEnergy(mass, newPosition, newSpeed, lastPoint);

        enqueue(trajMoon, newPosition, newSpeed, time, &valid);
    }
    double result = variationEnergy/NBSTEP;
    printf("-> average energy variation : %e\n",result);
    return trajMoon;

}
//rentrer le point initiale d'une lune et retourner sa variation(ici 1 car pas de différence
double initMoon( struct Queue* newTraj, double mass, double demieGrandAxe, double exentricite,int time, bool valid){
    double xPositionInitial = demieGrandAxe*(1-exentricite);
    double ySpeedInitial = sqrt((GRAVITATIONAL_CONSTANT*MASS_TERRE*(1+exentricite))/(demieGrandAxe*(1-exentricite)));
    struct Vect* positionInitial = createVect(xPositionInitial,0,0);
    struct Vect* speedInitial = createVect(0,ySpeedInitial,0);
    enqueue(newTraj, positionInitial, speedInitial, time, &valid);

    return calculVariationEnergy(mass, positionInitial, speedInitial, newTraj->l->head);
}
//retourner trajectoire planète Euler asymétrique
struct Queue* createTrajectoryEulerAsymetricMoon(double mass, double demieGrandAxe, double exentricite){
    struct Queue* trajMoon = createEmptyQueue();
    int time = 0;
    bool valid;
    double variationEnergy = initMoon(trajMoon, mass, demieGrandAxe,exentricite,time,&valid);
    while (time<NBSTEP) {
        time++;
        struct Point* lastPoint = trajMoon->l->tail;
        struct Vect* newPosition = position(lastPoint->position, lastPoint->speed);
        struct Vect* newAcceleration = accelerationMoon(newPosition);
        struct Vect* newSpeed = speed(lastPoint->speed, newAcceleration);
        deleteVector(&newAcceleration);

        variationEnergy += calculVariationEnergy(mass, newPosition, newSpeed, lastPoint);

        enqueue(trajMoon, newPosition, newSpeed, time, &valid);
    }
    double result = variationEnergy/NBSTEP;
    printf("-> average energy variation : %e\n",result);
    return trajMoon;

}
//calcul accélération lune
struct Vect* accelerationMoon(struct Vect* positionMoon){
    double reelAcceleration = -((GRAVITATIONAL_CONSTANT * MASS_TERRE) / (pow(normeVector(positionMoon),3)));
    return multiplicationVectorsByReal(positionMoon, reelAcceleration);
}

