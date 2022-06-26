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

void filePlanete(struct planete* p){
    FILE* mercureFile = fopen("mercure.txt","w");
    if(mercureFile==NULL){
        printf("Error in opening file");
        return ;
    }
    /*
    fprintf(mercureFile, "%s", p->name);
    if(isQueueEmpty(p->traj)){
        return;
    }
    struct point* iter = p->traj->l->head;
    fprintf(mercureFile, "{(%f,%f,%f), ", iter->position->x, iter->position->y, iter->position->z);
    fprintf(mercureFile, "(%f,%f,%f)", iter->vitesse->x, iter->vitesse->y, iter->vitesse->z);
    fprintf(mercureFile, "%d}", iter->temps);
    unsigned int size = queueSize(p->traj);
    iter = iter->next;
    for(unsigned int i=1; i<size;i++){
        fprintf(mercureFile,"\n");
        fprintf(mercureFile, "{(%f,%f,%f), ", iter->position->x, iter->position->y, iter->position->z);
        fprintf(mercureFile, "(%f,%f,%f)", iter->vitesse->x, iter->vitesse->y, iter->vitesse->z);
        fprintf(mercureFile, "%d}", iter->temps);
        iter = iter->next;
    }
     */
    fclose(mercureFile);
}