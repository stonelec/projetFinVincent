//
// Created by vince on 23/06/2022.
//

#include "planet.h"
//créer une planète sans valeurs
struct Planet* createEmptyPlanet(){
    struct Planet* new = malloc(sizeof (struct Planet));
    if(new!=NULL){
        new->name=NULL;
        new->traj = NULL;
    }
    return new;
}
//créer une planète avec la methode d'Euler symétrique
struct Planet* createPlanetSymetrique(char* name, double mass, double halfMojorAxis, double exentricity){
    struct Planet* new = createEmptyPlanet();
    new->name = name;
    new->traj = createTrajectoryEuler(mass, halfMojorAxis, exentricity);
    return new;
}
//créer une planète avec la methode d'Euler asymétrique
struct Planet* createPlanetAsymetrique(char* name, double mass, double halfMojorAxis, double exentricity){
    struct Planet* new = createEmptyPlanet();
    new->name = name;
    new->traj = createTrajectoryEulerAsymetric(mass, halfMojorAxis, exentricity);
    return new;
}
//créer une lune avec la methode d'Euler symétrique
struct Planet* createMoonSymetrique(char* name, double mass, double halfMojorAxis, double exentricity){
    struct Planet* new = createEmptyPlanet();
    new->name = name;
    new->traj = createTrajectoryEulerSymetricMoon(mass, halfMojorAxis, exentricity);
    return new;
}
//créer une lune avec la methode d'Euler asymétrique
struct Planet* createMoonAsymetrique(char* name, double mass, double halfMojorAxis, double exentricity){
    struct Planet* new = createEmptyPlanet();
    new->name = name;
    new->traj = createTrajectoryEulerAsymetricMoon(mass, halfMojorAxis, exentricity);

    return new;
}
//test
//afficher une planète dans la console(nom+trajectoire+taille de la trajectoire)
void printPlanet (struct Planet* planet){
    printf("{ \"%s\" : [\n", planet->name);
    printQueue(planet->traj);
    printf("}\nqueue size : %d\n",queueSize(planet->traj));
}
//afficher toutes les planètes dans la console
void printPlanets(struct Planet* mercury, struct Planet* venus, struct Planet* earth, struct Planet* mars, struct Planet* jupiter, struct Planet* saturn, struct Planet* uranus, struct Planet* neptune, struct Planet* moon){
    printf("{ ");
    printPlanet(mercury);
    printf("\n,");
    printPlanet(venus);
    printf("\n,");
    printPlanet(earth);
    printf("\n,");
    printPlanet(mars);
    printf("\n,");
    printPlanet(jupiter);
    printf("\n,");
    printPlanet(saturn);
    printf("\n,");
    printPlanet(uranus);
    printf("\n,");
    printPlanet(neptune);
    printf("\n}");
    printPlanet(moon);
    printf("}\n");
}
//afficher toutes les planètes dans la console pour euler asymétrique et symétrique (nom+trajectoire+taille de la trajectoire)
void printPlanetsBoth(struct Planet* mercury_symmetric,struct Planet* venus_symmetric,struct Planet* earth_symmetric,struct Planet* mars_symmetric,struct Planet* jupiter_symmetric,struct Planet* saturn_symmetric,struct Planet* uranus_symmetric,struct Planet* neptune_symmetric,struct Planet* moon_symmetric,struct Planet* mercury_asymmetric,struct Planet* venus_asymmetric,struct Planet* earth_asymmetric,struct Planet* mars_asymmetric,struct Planet* jupiter_asymmetric,struct Planet* saturn_asymmetric,struct Planet* uranus_asymmetric,struct Planet* neptune_asymmetric,struct Planet* moon_asymmetric){
    printf("{ ");
    printPlanet(mercury_symmetric);
    printf("\n,");
    printPlanet(venus_symmetric);
    printf("\n,");
    printPlanet(earth_symmetric);
    printf("\n,");
    printPlanet(mars_symmetric);
    printf("\n,");
    printPlanet(jupiter_symmetric);
    printf("\n,");
    printPlanet(saturn_symmetric);
    printf("\n,");
    printPlanet(uranus_symmetric);
    printf("\n,");
    printPlanet(neptune_symmetric);
    printf("\n}");
    printPlanet(moon_symmetric);
    printf("\n}");
    printPlanet(mercury_asymmetric);
    printf("\n,");
    printPlanet(venus_asymmetric);
    printf("\n,");
    printPlanet(earth_asymmetric);
    printf("\n,");
    printPlanet(mars_asymmetric);
    printf("\n,");
    printPlanet(jupiter_asymmetric);
    printf("\n,");
    printPlanet(saturn_asymmetric);
    printf("\n,");
    printPlanet(uranus_asymmetric);
    printf("\n,");
    printPlanet(neptune_asymmetric);
    printf("\n}");
    printPlanet(moon_asymmetric);
    printf("\n}");
}
//mettre une planète dans un fichier
void filePlanet(struct Planet* planet, FILE* file){
    if(isQueueEmpty(planet->traj)){
        return;
    }
    fprintf(file, "\"%s\" : [\n", planet->name);

    struct Point* astre = planet->traj->l->head;

    filePoint(astre, file);
    astre = astre->next;
    while (astre != NULL){
        fprintf(file,"\n,");
        filePoint(astre, file);
        astre = astre->next;
    }
    fprintf(file, "]");

}

//mettre toutes les planètes ou lune dans un même fichier
void filePlanets(struct Planet* mercury, struct Planet* venus, struct Planet* earth, struct Planet* mars, struct Planet* jupiter, struct Planet* saturn, struct Planet* uranus, struct Planet* neptune, struct Planet* moon){
    FILE* file = fopen("planets.json","wt");
    if(file==NULL){
        printf("Error in opening file");
        return ;
    }
    fprintf(file, "{");
    filePlanet(mercury, file);
    fprintf(file, "\n,");
    filePlanet(venus, file);
    fprintf(file, "\n,");
    filePlanet(earth, file);
    fprintf(file, "\n,");
    filePlanet(mars, file);
    fprintf(file, "\n,");
    filePlanet(jupiter, file);
    fprintf(file, "\n,");
    filePlanet(saturn, file);
    fprintf(file, "\n,");
    filePlanet(uranus, file);
    fprintf(file, "\n,");
    filePlanet(neptune, file);
    fprintf(file, "\n,");
    filePlanet(moon, file);
    fprintf(file, "\n}");

    fclose(file);
}
//mettre toutes les planètes ou lune dans un même fichier pour euler asymétrique et symétrique
void filePlanetsBoth(struct Planet* mercury_symmetric,struct Planet* venus_symmetric,struct Planet* earth_symmetric,struct Planet* mars_symmetric,struct Planet* jupiter_symmetric,struct Planet* saturn_symmetric,struct Planet* uranus_symmetric,struct Planet* neptune_symmetric,struct Planet* moon_symmetric,struct Planet* mercury_asymmetric,struct Planet* venus_asymmetric,struct Planet* earth_asymmetric,struct Planet* mars_asymmetric,struct Planet* jupiter_asymmetric,struct Planet* saturn_asymmetric,struct Planet* uranus_asymmetric,struct Planet* neptune_asymmetric,struct Planet* moon_asymmetric){
    FILE* file = fopen("planets.json","wt");
    if(file==NULL){
        printf("Error in opening file");
        return ;
    }
    fprintf(file, "{ ");
    filePlanet(mercury_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(venus_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(earth_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(mars_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(jupiter_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(saturn_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(uranus_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(neptune_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(moon_symmetric, file);
    fprintf(file, "\n,");
    filePlanet(mercury_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(venus_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(earth_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(mars_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(jupiter_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(saturn_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(uranus_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(neptune_asymmetric, file);
    fprintf(file, "\n,");
    filePlanet(moon_asymmetric, file);
    fprintf(file, "\n}");

    fclose(file);
}
//supprimer une structure planète
void deletePlanet(struct Planet** planet){
    struct Queue* traj = (*planet)->traj;
    deleteQueue(&traj);
    free(*planet);
    *planet = NULL;
}
