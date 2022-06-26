
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


    struct planete* mercure = createPlanete("Terre", MASSEMERCURE, DEMIEGRANDAXEMERCURE, EXENTRICITEMERCURE  );
    struct planete* venus = createPlanete("venus",MASSEVENUS , DEMIEGRANDAXEVENUS, EXENTRICITEVENUS);
    struct planete* terre = createPlanete("terre",MASSETERRE, DEMIEGRANDAXETERRE, EXENTRICITETERRE);
    struct planete* mars = createPlanete("mars",MASSEMARS, DEMIEGRANDAXEMARS, EXENTRICITEMARS);
    struct planete* jupiter = createPlanete("jupiter",MASSEJUPITER, DEMIEGRANDAXEJUPITER, EXENTRICITEJUPITER);
    struct planete* saturne = createPlanete("saturne",MASSESATURNE, DEMIEGRANDAXESATURNE, EXENTRICITESATURNE);
    struct planete* uranus = createPlanete("uranus",MASSEURANUS, DEMIEGRANDAXEURANUS, EXENTRICITEURANUS);
    struct planete* neptune = createPlanete("neptune",MASSENEPTUNE, DEMIEGRANDAXENEPTUNE, EXENTRICITENEPTUNE);
    struct planete* lune = createPlanete("lune",MASSELUNE, DEMIEGRANDAXELUNE, EXENTRICITELUNE);

    printPlanete(mercure);
    printPlanete(venus);
    printPlanete(terre);
    printPlanete(mars);
    printPlanete(jupiter);
    printPlanete(saturne);
    printPlanete(uranus);
    printPlanete(neptune);
    printPlanete(lune);

    return 0;
}


