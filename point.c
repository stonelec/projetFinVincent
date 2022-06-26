//
// Created by vince on 23/06/2022.
//

#include "point.h"
struct point* createPoint(struct vect* position, struct vect* vitesse, int temps){
    struct point* new = malloc(sizeof (struct point));
    if( new != NULL){
        new->position=position;
        new->vitesse=vitesse;
        new->temps=temps;
        new->next=NULL;
    }
    return new;
}

void printPoint(struct point* point){
    printf("\n  - position : ");
    printVect(point->position);
    printf(" vitesse : ");
    printVect(point->vitesse);
    printf(" temps : %d", point->temps);
}


