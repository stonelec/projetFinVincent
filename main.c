
#include "planete.h"
int main(){
    /*
    struct vect* vect1 = createVect(100, 100, 0);
    struct vect* vect2 = createVect(5, 5, 0);
    printVect(vect1);
    printf("\n");
    printVect(vect2);
    printf("\n");
    struct vect* vect = soustractionVecteurs(vect1,vect2);
    printVect(vect);
    */
    //printf("\nis%e",vect);


    struct planete* newplanete;
    newplanete = createPlanete("Terre", MASSEMERCURE, DEMIEGRANDAXEMERCURE, EXENTRICITEMERCURE  );

    printPlanete(newplanete);

    return 0;
}


