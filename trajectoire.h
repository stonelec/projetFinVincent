//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_TRAJECTOIRE_H
#define PROJETFINVINCENT_TRAJECTOIRE_H

#include "infoPLanete.h"
#include "liste.h"

struct trajectoire{
    struct point* list;
};
struct trajectoire* createTrajectoire();
struct trajectoire* createEmptyTrajectoire();

//more
double energiePotentielle(double massePlanete,double masseSoleil , double constanteG, struct vect* positionPlanete, struct vect* positionSoleil);

double energieCinétique(double massePlanete, struct vect* vitesse);

double energieTotale(double energiePotentielle, double energieCinétique);

#endif //PROJETFINVINCENT_TRAJECTOIRE_H