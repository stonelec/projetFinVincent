//
// Created by vince on 23/06/2022.
//

#ifndef PROJETFINVINCENT_PLANETE_H
#define PROJETFINVINCENT_PLANETE_H


#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <math.h>

#include "trajectoire.h"
#include "infoPLanete.h"

struct planete{
    char* name;
    struct trajectoire* traj;
};

struct planete* createPlanete(char* name, double masse, double demieGrandAxe, double exentricite);

#endif //PROJETFINVINCENT_PLANETE_H