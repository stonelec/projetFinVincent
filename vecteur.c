//
// Created by vince on 23/06/2022.
//

#include "vecteur.h"

struct vect* createVect(double x, double y, double z){
    struct vect* new = malloc(sizeof (struct vect));
    if( new != NULL){
        new->x=x;
        new->y=y;
        new->z=z;
    }
    return new;
}
void printVect(struct vect* printable){
    printf("(%e,%e,%e)",printable->x,printable->y,printable->z);
}
struct vect* additionVecteurs (struct vect* vecteur1, struct vect* vecteur2){
    struct vect* result;

    result->x = vecteur1->x + vecteur2->x;
    result->y = vecteur1->y + vecteur2->y;
    result->z = vecteur1->z + vecteur2->z;

    return result;
}
struct vect* soustractionVecteurs (struct vect* vecteur1, struct vect* vecteur2){
    struct vect* result;

    result->x = vecteur1->x - vecteur2->x;
    result->y = vecteur1->y - vecteur2->y;
    result->z = vecteur1->z - vecteur2->z;

    return result;
}
struct vect* multiplicationVecteursParReel (struct vect* vecteur, int reel){
    struct vect* result;

    result->x = vecteur->x * reel;
    result->y = vecteur->y * reel;
    result->z = vecteur->z * reel;

    return result;
}
struct vect* multiplicationVecteursParScalaire (struct vect* vecteur, int scalaire){
    struct vect* result;

    result->x = vecteur->x * scalaire;
    result->y = vecteur->y * scalaire;
    result->z = vecteur->z * scalaire;

    return result;
}
double normeVecteur (struct vect* vecteur){
    return sqrt(pow((vecteur->x),2) + pow((vecteur->y),2) + pow((vecteur->z),2));
}
double distanceEntre2Vects(struct vect* vecteur1, struct vect* vecteur2){
    return sqrt(pow((vecteur1->x - vecteur2->x),2) + pow((vecteur1->y - vecteur2->y),2) + pow((vecteur1->z - vecteur2->z),2));
}
