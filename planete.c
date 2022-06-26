//
// Created by vince on 23/06/2022.
//



#include "planete.h"

struct planete* createEmptyPlanete(){
    struct planete* new = malloc(sizeof (struct planete));
    if(new!=NULL){
        new->name=NULL;
        new->traj = NULL;
    }
    return new;
}
struct planete* createPlanete(char* name, double masse, double demieGrandAxe, double exentricite){

    struct planete* new = createEmptyPlanete();
    struct Queue* traj = createTrajectoire(masse, demieGrandAxe, exentricite);

    new->name = name;
    new->traj = traj;

    return new;
}
//test

void printPlanete (struct planete* planete){
    printf("nom : %s", planete->name);
    printf("\npoints : ");
    printQueue(planete->traj);
    printf("\nqueue size : %d",queueSize(planete->traj));
}