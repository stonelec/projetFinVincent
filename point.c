//
// Created by vince on 23/06/2022.
//

#include "point.h"
struct point* createPoint(struct vect* position, struct vect* speed, int time){
    struct point* new = malloc(sizeof (struct point));
    if( new != NULL){
        new->position=position;
        new->speed=speed;
        new->time=time;
        new->next=NULL;
    }
    return new;
}

void printPoint(struct point* point){
    printf("\n  - position : ");
    printVect(point->position);
    printf(" vitesse : ");
    printVect(point->speed);
    printf(" temps : %d", point->time);
}
/*
struct Point* head(struct Trajectory* t, bool* valid){
        int list_size = listSize(t->list_point)-1;
        return getItemPos(t->list_point,list_size,valid);
        //return t->list_point->head;
    }

*/