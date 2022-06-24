
#include "planete.h"
int main(){
    struct vect* vect1 = createVect(100, 100, 0);
    struct vect* vect2 = createVect(5, 5, 0);
    printVect(vect1);
    printVect(vect2);
    double vect = normeVecteur(vect1);
    //printVect(vect1);
    printf("\nis%e",vect);

    createPlanete("Terre", MASSETERRE, DEMIEGRANDAXETERRE, EXENTRICITETERRE);
    return 0;
}


