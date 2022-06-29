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

struct Planet{
    char* name;
    struct Queue* traj;
};

struct Planet* createEmptyPlanet();

struct Planet* createPlanetSymetrique(char* name, double mass, double demieGrandAxe, double exentricite);
struct Planet* createPlanetAsymetrique(char* name, double mass, double halfMojorAxis, double exentricity);

struct Planet* createMoonSymetrique(char* name, double mass, double demieGrandAxe, double exentricite);
struct Planet* createMoonAsymetrique(char* name, double mass, double demieGrandAxe, double exentricite);

void printPlanet (struct Planet* planet);

void printPlanets(struct Planet* mercury, struct Planet* venus, struct Planet* earth, struct Planet* mars, struct Planet* jupiter, struct Planet* saturn, struct Planet* uranus, struct Planet* neptune, struct Planet* moon);
void printPlanetsBoth(struct Planet* mercury_symmetric,struct Planet* venus_symmetric,struct Planet* earth_symmetric,struct Planet* mars_symmetric,struct Planet* jupiter_symmetric,struct Planet* saturn_symmetric,struct Planet* uranus_symmetric,struct Planet* neptune_symmetric,struct Planet* moon_symmetric,struct Planet* mercury_asymmetric,struct Planet* venus_asymmetric,struct Planet* earth_asymmetric,struct Planet* mars_asymmetric,struct Planet* jupiter_asymmetric,struct Planet* saturn_asymmetric,struct Planet* uranus_asymmetric,struct Planet* neptune_asymmetric,struct Planet* moon_asymmetric);

void filePlanet(struct Planet* planet, FILE*);

void fileMoon(struct Planet* planet, struct Planet* moon, FILE* file);

void filePlanets(struct Planet* mercury, struct Planet* venus, struct Planet* earth, struct Planet* mars, struct Planet* jupiter, struct Planet* saturn, struct Planet* uranus, struct Planet* neptune, struct Planet* moon);
void filePlanetsBoth(struct Planet* mercury_symmetric,struct Planet* venus_symmetric,struct Planet* earth_symmetric,struct Planet* mars_symmetric,struct Planet* jupiter_symmetric,struct Planet* saturn_symmetric,struct Planet* uranus_symmetric,struct Planet* neptune_symmetric,struct Planet* moon_symmetric,struct Planet* mercury_asymmetric,struct Planet* venus_asymmetric,struct Planet* earth_asymmetric,struct Planet* mars_asymmetric,struct Planet* jupiter_asymmetric,struct Planet* saturn_asymmetric,struct Planet* uranus_asymmetric,struct Planet* neptune_asymmetric,struct Planet* moon_asymmetric);
void deletePlanet(struct Planet** planet);

#endif //PROJETFINVINCENT_PLANETE_H