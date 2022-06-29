//
// Created by vince on 23/06/2022.
//

#include "vector.h"
//créer un vecteur avec des valeurs initiales
struct Vect* createVect(double x, double y, double z){
    struct Vect* new = malloc(sizeof (struct Vect));
    if( new != NULL){
        new->x=x;
        new->y=y;
        new->z=z;
    }
    return new;
}
//afficher un vecteur dans la console
void printVect(struct Vect* printable){
    printf("[%e,%e,%e]",printable->x,printable->y,printable->z);
}
//calculer la somme de 2 vecteurs
struct Vect* additionVectors (struct Vect* vector1, struct Vect* vector2){
    return createVect(vector1->x + vector2->x, vector1->y + vector2->y, vector1->z + vector2->z);
}
//calculer la soustraction de 2 vecteurs
struct Vect* subtractionVectors (struct Vect* vector1, struct Vect* vector2){
    return createVect(vector1->x - vector2->x, vector1->y - vector2->y, vector1->z - vector2->z);
}
//calculer la multiplication d'un vecteur par un réel
struct Vect* multiplicationVectorsByReal (struct Vect* vecteur, double real){
    return createVect(vecteur->x * real, vecteur->y * real, vecteur->z * real);
}
//calculer la norme d'un vecteur
double normeVector (struct Vect* vecteur){
    return sqrt(pow((vecteur->x),2) + pow((vecteur->y),2) + pow((vecteur->z),2));
}
//calculer la distance entre 2 vecteurs
double distance2Vects(struct Vect* vector1, struct Vect* vector2){
    return sqrt(pow((vector1->x-vector2->x),2) + pow((vector1->y-vector2->z),2) + pow((vector1->z-vector2->z),2));
}
//supprimer un vecteur
void deleteVector(struct Vect** vector){
    free(*vector);
    *vector=NULL;
}
//test pour vérifier le fonctionnement des vecteurs
void moduleTest (){
    struct Vect* vect1 = createVect(100, 100, 0);
    struct Vect* vect2 = createVect(5, 5, 0);
    printVect(vect1);
    printf("\n");
    printVect(vect2);
    printf("\n");
    struct Vect* add = additionVectors(vect1,vect2);//->(105,105,0)
    struct Vect* sub = subtractionVectors(vect1,vect2);//->(95,95,0)
    struct Vect* multi = multiplicationVectorsByReal(vect1,5);//->(500,500,0)
    double norme = normeVector(vect2);//->
    double vect = distance2Vects(vect1,vect2);
    printVect(add);
    printVect(sub);
    printVect(multi);
    printf("\n%f",norme);
    printf("\n%f",vect);

    //printf("\nis%e",vect);
}
