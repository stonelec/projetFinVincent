//
// Created by vince on 23/06/2022.
//



#include "planete.h"

struct planete* createEmptyPlanete(char* name){
    struct planete* new = malloc(sizeof (struct planete));
    if(new!=NULL){
        new->name=name;
        new->traj=createEmptyTrajectoire();
    }
    return new;
}

struct planete* createPlanete(char* name, double masse, double demieGrandAxe, double exentricite){
    struct planete* planete=createEmptyPlanete(name);

}


