//
// Created by vince on 23/06/2022.
//

#include "trajectoire.h"
struct trajectoire* createTrajectoire(){

}
struct trajectoire* createEmptyTrajectoire(){
    struct trajectoire* new = malloc(sizeof (struct trajectoire));
    if(new!=NULL){
        new->list = createEmptyList();
    }
    return new;
}



/*
double energiePotentielle(double massePlanete,double masseSoleil , double constanteG, struct vect* positionPlanete, struct vect* positionSoleil){
    return 0.5*(constanteG * massePlanete * masseSoleil) / (distanceEntre2Vects(positionPlanete,positionSoleil));
}// ici je fais pour toute les planètes
*/
double energiePotentielle(double massePlanete,double masseSoleil , double constanteG, struct vect* positionPlanete, struct vect* positionSoleil){
    return ((constanteG * massePlanete * masseSoleil) / pow((distanceEntre2Vects(positionPlanete,positionSoleil)),2));
}
// ici je fais juste pour la terre

double energieCinétique(double massePlanete, struct vect* vitesse){
    return 0.5*(massePlanete * pow(normeVecteur(vitesse),2));
}

double energieTotale(double energiePotentielle, double energieCinétique){
    return energieCinétique + energiePotentielle;
}


