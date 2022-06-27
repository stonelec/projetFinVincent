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
double distanceEntre2Vects(struct vect* vecteur1, struct vect* vecteur2){
    return sqrt(pow((vecteur1->x-vecteur2->x),2) + pow((vecteur1->y-vecteur2->z),2) + pow((vecteur1->z-vecteur2->z),2));
}
void moduleTest (){
    struct vect* vect1 = createVect(100, 100, 0);
    struct vect* vect2 = createVect(5, 5, 0);
    printVect(vect1);
    printf("\n");
    printVect(vect2);
    printf("\n");
    struct vect* vect = soustractionVecteurs(vect1,vect2);
    printVect(vect);

    printf("\nis%e",vect);
}
