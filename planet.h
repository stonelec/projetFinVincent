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

#include "trajectory.h"
#include "infoPLanet.h"

struct planet{
    char* name;
    struct Queue* traj;
};

struct planet* createEmptyPlanet();

struct planet* createPlanet(char* name, double masse, double demieGrandAxe, double exentricite);

void printPlanet(struct planet* planet);

void filePlanet(struct planet* planet);

void deletePlanet(struct planet** planet);

#endif //PROJETFINVINCENT_PLANETE_H