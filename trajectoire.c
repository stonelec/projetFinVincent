//
// Created by vince on 23/06/2022.
//

#include "trajectoire.h"

void firstPoint( struct Queue* newTraj,double demieGrandAxe, double exentricite,int temps, bool valid){
    double xPositionInitiale = demieGrandAxe*(1-exentricite);
    double yVitesseInitiale = sqrt((CONSTANTEGRAVITATION*MASSESOLEIL*(1+exentricite))/(demieGrandAxe*(1-exentricite)));
    struct vect* positionInitiale = createVect(xPositionInitiale,0,0);
    struct vect* vitesseInitiale = createVect(0,yVitesseInitiale,0);
    enqueue(newTraj, positionInitiale, vitesseInitiale, temps, &valid);
}

struct Queue* createTrajectoire(double masse, double demieGrandAxe, double exentricite){
    struct Queue* newTraj = createEmptyQueue();
    int temps = 0;
    bool valid;
    firstPoint(newTraj,demieGrandAxe,exentricite,temps,&valid);

        while (temps<36499) {
        temps++;
        struct vect* newAcceleration = acceleration(newTraj->l->head->position);
        struct vect* newPosition = position(newTraj->l->head->position, newTraj->l->head->vitesse);
        struct vect* newVitesse = vitesse(newTraj->l->head->vitesse, newAcceleration);
        /*
        if(energieTotale(masse, newTraj->l->head->position, newTraj->l->head->vitesse) != energieTotale(masse, newPosition, newVitesse)){
            return 0;
        }
        */
        enqueue(newTraj, newPosition, newVitesse, temps, &valid);
    }
    return newTraj;
}


struct vect* position(struct vect*  positionPost, struct vect* vitessePost){
    return additionVecteurs(positionPost, multiplicationVecteursParReel(vitessePost,PAS));
}
struct vect* acceleration(struct vect* positionPlanete){
    double reelAcceleration = -((CONSTANTEGRAVITATION * MASSESOLEIL) / (pow(normeVecteur(positionPlanete),3)));
    return multiplicationVecteursParReel(positionPlanete, reelAcceleration);
}
struct vect* vitesse(struct vect*  vitessePost, struct vect* accelerationPost){
    return additionVecteurs(vitessePost, multiplicationVecteursParReel(accelerationPost, PAS));
}

double energiePotentielle(double massePlanete, struct vect* positionPlanete){
    struct vect* positionSoleil = createVect(0,0,0);
    return (CONSTANTEGRAVITATION*massePlanete*MASSESOLEIL) / (pow(distanceEntre2Vects(positionPlanete,positionSoleil),2));
}
double energieCinetique(double massePlanete, struct vect* vitesse){
    return 0.5*(massePlanete * pow(normeVecteur(vitesse),2));
}

double energieTotale(double massePlanete, struct vect* positionPlanete, struct vect* vitesse){
    return energiePotentielle(massePlanete, positionPlanete) + energieCinetique(massePlanete, vitesse);
}
