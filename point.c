//
// Created by vince on 23/06/2022.
//

#include "point.h"
//créer un point avec des valeurs données
struct Point* createPoint(struct Vect* position, struct Vect* speed, int time){
    struct Point* new = malloc(sizeof (struct Point));
    if( new != NULL){
        new->position=position;
        new->speed=speed;
        new->time=time;
        new->next=NULL;
    }
    return new;
}
//afficher un point dans la console
void printPoint(struct Point* point){
    printf("[");
    printVect(point->position);
    printf(",");
    printVect(point->speed);
    printf(",%d]", point->time);
}
//ajouter un point dans un fichier
void filePoint(struct Point* point, FILE* file){

    fprintf(file, "[[%e, %e, %e], ", point->position->x, point->position->y, point->position->z);
    fprintf(file, "[%e, %e, %e],", point->speed->x, point->speed->y, point->speed->z);
    fprintf(file, "%d]", point->time);
}
//supprimer un point
void deletePoint(struct Point** point){
    deleteVector(&(*point)->position);
    deleteVector(&(*point)->speed);
    free(*point);
    *point = NULL;
}