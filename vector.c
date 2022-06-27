//
// Created by vince on 23/06/2022.
//

#include "vector.h"

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
struct vect* additionVectors (struct vect* vector1, struct vect* vector2){
    return createVect(vector1->x + vector2->x, vector1->y + vector2->y, vector1->z + vector2->z);
}
struct vect* subtractionVectors (struct vect* vector1, struct vect* vector2){
    return createVect(vector1->x - vector2->x, vector1->y - vector2->y, vector1->z - vector2->z);
}
struct vect* multiplicationVectorsByReal (struct vect* vecteur, double real){
    return createVect(vecteur->x * real, vecteur->y * real, vecteur->z * real);
}

double normeVector (struct vect* vecteur){
    return sqrt(pow((vecteur->x),2) + pow((vecteur->y),2) + pow((vecteur->z),2));
}
double distance2Vects(struct vect* vector1, struct vect* vector2){
    return sqrt(pow((vector1->x-vector2->x),2) + pow((vector1->y-vector2->z),2) + pow((vector1->z-vector2->z),2));
}
void moduleTest (){
    struct vect* vect1 = createVect(100, 100, 0);
    struct vect* vect2 = createVect(5, 5, 0);
    printVect(vect1);
    printf("\n");
    printVect(vect2);
    printf("\n");
    struct vect* vect = subtractionVectors(vect1,vect2);
    printVect(vect);

    //printf("\nis%e",vect);
}
