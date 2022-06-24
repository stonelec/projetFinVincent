//
// Created by vince on 23/06/2022.
//

#include "point.h"
struct point* createPoint(struct vect* position, struct vect* vitesse, int temps){
    struct point* new = malloc(sizeof (struct point));
    if( new != NULL){
        new->position=position;
        new->vitesse=vitesse;
        new->temps=temps;
        new->next=NULL
    }
    return new;
}

struct vect* acceleration(double massePlanete, double constanteG, struct vect* positionPlanete){
    double reelAcceleration = -((constanteG * massePlanete) / (normeVecteur(positionPlanete)));
    return multiplicationVecteursParReel(positionPlanete, reelAcceleration);
}

double vitesseInitiale(double constanteG, double demieGrandAxeOrbite, double exentriciteOrbite){
    return sqrt((constanteG*MASSESOLEIL*(1+exentriciteOrbite))  / (demieGrandAxeOrbite*(1-exentriciteOrbite)));
}

struct vect* vitesse(struct vect*  vitessePost, struct vect* accelerationPost, int temps){
    return additionVecteurs(vitessePost, multiplicationVecteursParScalaire(accelerationPost, temps));
}

struct vect* position(struct vect*  positionPost, struct vect* vitessePost, int temps){
    return additionVecteurs(positionPost, multiplicationVecteursParScalaire(vitessePost, temps));
}
