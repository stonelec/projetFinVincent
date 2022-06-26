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
    return createVect(vecteur1->x + vecteur2->x, vecteur1->y + vecteur2->y, vecteur1->z + vecteur2->z);
}
struct vect* soustractionVecteurs (struct vect* vecteur1, struct vect* vecteur2){
    return createVect(vecteur1->x - vecteur2->x, vecteur1->y - vecteur2->y, vecteur1->z - vecteur2->z);
}
struct vect* multiplicationVecteursParReel (struct vect* vecteur, double reel){
    return createVect(vecteur->x * reel, vecteur->y * reel, vecteur->z * reel);
}

double normeVecteur (struct vect* vecteur){
    return sqrt(pow((vecteur->x),2) + pow((vecteur->y),2) + pow((vecteur->z),2));
}
