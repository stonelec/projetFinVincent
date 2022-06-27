
#include "planet.h"
#include "infoPLanet.h"
int main(){



    //moduleTest();


    struct planet* mercure = createPlanet("help", MASSE_MERCURE, DEMIE_GRANDAXE_MERCURE, EXENTRICITE_MERCURE  );
    /*
    struct planet* venus = createPlanet("venus",MASSE_VENUS , DEMIE_GRANDAXE_VENUS, EXENTRICITE_VENUS);
    struct planet* terre = createPlanet("terre",MASSE_TERRE, DEMIE_GRANDAXE_TERRE, EXENTRICITE_TERRE);
    struct planet* mars = createPlanet("mars",MASSE_MARS, DEMIE_GRANDAXE_MARS, EXENTRICITE_MARS);
    struct planet* jupiter = createPlanet("jupiter",MASSE_JUPITER, DEMIE_GRANDAXE_JUPITER, EXENTRICITE_JUPITER);
    struct planet* saturne = createPlanet("saturne",MASSE_SATURNE, DEMIE_GRANDAXE_SATURNE, EXENTRICITE_SATURNE);
    struct planet* uranus = createPlanet("uranus",MASSE_URANUS, DEMIE_GRANDAXE_URANUS, EXENTRICITE_URANUS);
    struct planet* neptune = createPlanet("neptune",MASSE_NEPTUNE, DEMIE_GRANDAXE_NEPTUNE, EXENTRICITE_NEPTUNE);
    */
    //printPlanet(mercure);
    filePlanet(mercure);
    //filePlanete(venus);
     /*
    printPlanet(venus);
    printPlanet(terre);
    printPlanet(mars);
    printPlanet(jupiter);
    printPlanet(saturne);
    printPlanet(uranus);
    printPlanet(neptune);
    */
    deletePlanet(&mercure);
    return 0;
}


