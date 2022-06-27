//
// Created by vince on 23/06/2022.
//

#include "planet.h"

struct planet* createEmptyPlanet(){
    struct planet* new = malloc(sizeof (struct planet));
    if(new!=NULL){
        new->name=NULL;
        new->traj = NULL;
    }
    return new;
}
struct planet* createPlanet(char* name, double masse, double demieGrandAxe, double exentricite){

    struct planet* new = createEmptyPlanet();
    struct Queue* traj = createTrajectory(masse, demieGrandAxe, exentricite);

    new->name = name;
    new->traj = traj;

    return new;
}
//test

void printPlanet (struct planet* planet){
    printf("{nom : %s", planet->name);
    printf("[\npoints : ");
    printQueue(planet->traj);
    printf("]\nqueue size : %d",queueSize(planet->traj));
}

void filePlanet(struct planet* planet){
    FILE* file = fopen("planets.txt","wt");
    if(file==NULL){
        printf("Error in opening file");
        return ;
    }
    if(isQueueEmpty(planet->traj)){
        return;
    }

    fprintf(file, "{");
    fprintf(file, "\"%s\" : [", planet->name);

    struct point* iter = planet->traj->l->head;
    unsigned int size = queueSize(planet->traj);
    iter = iter->next;
    while (iter != NULL){
        fprintf(file,"\n");
        fprintf(file, ",[[%f, %f, %f], ", iter->position->x, iter->position->y, iter->position->z);
        fprintf(file, "[%f, %f, %f],", iter->speed->x, iter->speed->y, iter->speed->z);
        fprintf(file, "%d]", iter->time);
        iter = iter->next;
    }
    fprintf(file, "]\n}");
    fclose(file);
}

void deletePlanet(struct planet** planet){
    struct Queue* traj = (*planet)->traj;
    deleteQueue(&traj);
    free(*planet);
}
