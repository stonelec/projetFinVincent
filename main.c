
#include "planet.h"
#include "infoPLanet.h"
int main(){

    //definition des planets pour euler symétrique
    struct Planet* mercury_symmetric;
    struct Planet* venus_symmetric;
    struct Planet* earth_symmetric;
    struct Planet* mars_symmetric;
    struct Planet* jupiter_symmetric;
    struct Planet* saturn_symmetric;
    struct Planet* uranus_symmetric;
    struct Planet* neptune_symmetric;
    struct Planet* moon_symmetric;
    //definition des planets pour euler asymétrique
    struct Planet* mercury_asymmetric;
    struct Planet* venus_asymmetric;
    struct Planet* earth_asymmetric;
    struct Planet* mars_asymmetric;
    struct Planet* jupiter_asymmetric;
    struct Planet* saturn_asymmetric;
    struct Planet* uranus_asymmetric;
    struct Planet* neptune_asymmetric;
    struct Planet* moon_asymmetric;

    //menue pour selectionner le but
    int exit = 0;//variable de sortie
    int option = 0;
    int method = 0;
    int action = 0;
    while (exit != 1) {
        int out = 0;
        //sélectionner ce qu'on veut entre :
        //      les données initiales
        //      le test pour les vecteurs
        //      le test des fonctions vecteur
        //      sortir du programme
        printf("-  -  -  -  -  -  -  -  -  -  -  -  -");
        printf("\nSelect an option : \n");
        printf("    1 -> display initial values\n");
        printf("    2 -> run the test of vectors\n");
        printf("    3 -> run the code\n");
        printf("    other number -> exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("option 1 :\n");
                printf(" * gravitational constant =  %e\n", GRAVITATIONAL_CONSTANT);
                printf(" * size of step = %d (day/10)\n", STEP);
                printf(" * number of step = %d\n", NBSTEP);
                break;

            case 2:
                printf("option 2 :\n");
                moduleTest();
                printf("\n");
                break;

            case 3:
                //sélectionner ce qu'on veut entre :
                //      la methode d'Euler symmetric
                //      la methode d'Euler asymmetric
                //      la methode d'Euler symmetric et asymmetric
                //      sortir du programme
                printf("option 3 :\n");
                printf("    Select a method : \n");
                printf("      1 -> symmetric Euler\n");
                printf("      2 -> asymmetric Euler\n");
                printf("      3 -> symmetric and asymmetric Euler\n");
                printf("      other number -> exit\n");
                scanf("%d", &method);

                switch (method) {
                    case 1:
                        printf("method 1 :\n");
                        printf("average of the energy variation the planet for verification :\n");
                        //créer les valeurs avec la methode d'Euler symmetric et en même temps afficher la moyenne de variation d'énergie pour vérifier que les valeurs obtenues ont du sens
                        printf(" * mercury symmetric");
                        mercury_symmetric = createPlanetSymetrique("mercury_symmetric", MASS_MERCURY,HALF_MAJOR_AXIS_MERCURY, ECCENTRICITY_MERCURY);
                        printf(" * venus symmetric");
                        venus_symmetric = createPlanetSymetrique("venus_symmetric", MASS_VENUS, HALF_MAJOR_AXIS_VENUS, ECCENTRICITY_VENUS);
                        printf(" * earth symmetric");
                        earth_symmetric = createPlanetSymetrique("earth_symmetric", MASS_TERRE, HALF_MAJOR_AXIS_TERRE,ECCENTRICITY_TERRE);
                        printf(" * mars symmetric");
                        mars_symmetric = createPlanetSymetrique("mars_symmetric", MASS_MARS, HALF_MAJOR_AXIS_MARS, ECCENTRICITY_MARS);
                        printf(" * jupiter symmetric");
                        jupiter_symmetric = createPlanetSymetrique("jupiter_symmetric", MASS_JUPITER, HALF_MAJOR_AXIS_JUPITER,ECCENTRICITY_JUPITER);
                        printf(" * saturn symmetric");
                        saturn_symmetric = createPlanetSymetrique("saturn_symmetric", MASS_SATURNE,  HALF_MAJOR_AXIS_SATURNE,ECCENTRICITY_SATURNE);
                        printf(" * uranus symmetric");
                        uranus_symmetric = createPlanetSymetrique("uranus_symmetric", MASS_URANUS,HALF_MAJOR_AXIS_URANUS, ECCENTRICITY_URANUS);
                        printf(" * neptune symmetric");
                        neptune_symmetric = createPlanetSymetrique("neptune_symmetric", MASS_NEPTUNE,HALF_MAJOR_AXIS_NEPTUNE, ECCENTRICITY_NEPTUNE);
                        printf(" * moon symmetric");
                        moon_symmetric = createMoonSymetrique("moon_symmetric", MASS_NEPTUNE, HALF_MAJOR_AXIS_NEPTUNE, ECCENTRICITY_NEPTUNE);
                        //sélectionner ce qu'on veut entre :
                        //      afficher les valeurs dans la console
                        //      rentrer les valeurs dans un fichier .json
                        //      sortir du programme
                        printf("        Select an action  : \n");
                        printf("            1 -> print here\n");
                        printf("            2 -> stock in file\n");
                        printf("            other number -> exit\n");
                        scanf("%d", &action);
                        switch (action) {
                            case 1:
                                printf("action 1 :\n");
                                printPlanets(mercury_symmetric, venus_symmetric, earth_symmetric, mars_symmetric,
                                             jupiter_symmetric, saturn_symmetric, uranus_symmetric, neptune_symmetric,
                                             moon_symmetric);
                                // libération de toute la mémoire
                                deletePlanet(&mercury_symmetric);
                                deletePlanet(&venus_symmetric);
                                deletePlanet(&earth_symmetric);
                                deletePlanet(&mars_symmetric);
                                deletePlanet(&jupiter_symmetric);
                                deletePlanet(&saturn_symmetric);
                                deletePlanet(&uranus_symmetric);
                                deletePlanet(&neptune_symmetric);
                                deletePlanet(&moon_symmetric);
                                break;
                            case 2:
                                printf("action 2 :\n");
                                filePlanets(mercury_symmetric, venus_symmetric, earth_symmetric, mars_symmetric,
                                            jupiter_symmetric, saturn_symmetric, uranus_symmetric, neptune_symmetric,
                                            moon_symmetric);
                                printf("stock in file done ! \n");
                                // libération de toute la mémoire
                                deletePlanet(&mercury_symmetric);
                                deletePlanet(&venus_symmetric);
                                deletePlanet(&earth_symmetric);
                                deletePlanet(&mars_symmetric);
                                deletePlanet(&jupiter_symmetric);
                                deletePlanet(&saturn_symmetric);
                                deletePlanet(&uranus_symmetric);
                                deletePlanet(&neptune_symmetric);
                                deletePlanet(&moon_symmetric);
                                break;
                            default:
                                out++;
                        }
                        break;
                    case 2:
                        printf("method 2 :\n");
                        printf("average of the energy variation the planet for verification :\n");
                        //créer les valeurs avec la methode d'Euler asymmetric et en même temps afficher la moyenne de variation d'énergie pour vérifier que les valeurs obtenues ont du sens
                        printf(" * mercury asymmetric");
                        mercury_asymmetric = createPlanetAsymetrique("mercury_asymmetric", MASS_MERCURY,
                                                                     HALF_MAJOR_AXIS_MERCURY,
                                                                     ECCENTRICITY_MERCURY);
                        printf(" * venus asymmetric");
                        venus_asymmetric = createPlanetAsymetrique("venus_asymmetric", MASS_VENUS,
                                                                   HALF_MAJOR_AXIS_VENUS,
                                                                   ECCENTRICITY_VENUS);
                        printf(" * earth asymmetric");
                        earth_asymmetric = createPlanetAsymetrique("earth_asymmetric", MASS_TERRE,
                                                                   HALF_MAJOR_AXIS_TERRE,
                                                                   ECCENTRICITY_TERRE);
                        printf(" * mars asymmetric");
                        mars_asymmetric = createPlanetAsymetrique("mars_asymmetric", MASS_MARS, HALF_MAJOR_AXIS_MARS,
                                                                  ECCENTRICITY_MARS);
                        printf(" * jupiter asymmetric");
                        jupiter_asymmetric = createPlanetAsymetrique("jupiter_asymmetric", MASS_JUPITER,
                                                                     HALF_MAJOR_AXIS_JUPITER,
                                                                     ECCENTRICITY_JUPITER);
                        printf(" * saturn asymmetric");
                        saturn_asymmetric = createPlanetAsymetrique("saturn_asymmetric", MASS_SATURNE,
                                                                    HALF_MAJOR_AXIS_SATURNE,
                                                                    ECCENTRICITY_SATURNE);
                        printf(" * uranus asymmetric");
                        uranus_asymmetric = createPlanetAsymetrique("uranus_asymmetric", MASS_URANUS,
                                                                    HALF_MAJOR_AXIS_URANUS,
                                                                    ECCENTRICITY_URANUS);
                        printf(" * neptune asymmetric");
                        neptune_asymmetric = createPlanetAsymetrique("neptune_asymmetric", MASS_NEPTUNE,
                                                                     HALF_MAJOR_AXIS_NEPTUNE,
                                                                     ECCENTRICITY_NEPTUNE);
                        printf(" * moon asymmetric");
                        moon_asymmetric = createMoonAsymetrique("moon_asymmetric", MASS_NEPTUNE,
                                                                HALF_MAJOR_AXIS_NEPTUNE,
                                                                ECCENTRICITY_NEPTUNE);
                        //sélectionner ce qu'on veut entre :
                        //      afficher les valeurs dans la console
                        //      rentrer les valeurs dans un fichier .json
                        //      sortir du programme
                        printf("        Select an action  : \n");
                        printf("            1 -> print here\n");
                        printf("            2 -> stock in file\n");
                        printf("            other number -> exit\n");
                        scanf("%d", &action);
                        switch (action) {
                            case 1:
                                printf("action 1 :\n");
                                printPlanets(mercury_asymmetric, venus_asymmetric, earth_asymmetric, mars_asymmetric,
                                             jupiter_asymmetric, saturn_asymmetric, uranus_asymmetric,
                                             neptune_asymmetric, moon_asymmetric);
                                // libération de toute la mémoire
                                deletePlanet(&mercury_asymmetric);
                                deletePlanet(&venus_asymmetric);
                                deletePlanet(&earth_asymmetric);
                                deletePlanet(&mars_asymmetric);
                                deletePlanet(&jupiter_asymmetric);
                                deletePlanet(&saturn_asymmetric);
                                deletePlanet(&uranus_asymmetric);
                                deletePlanet(&neptune_asymmetric);
                                deletePlanet(&moon_asymmetric);
                                break;
                            case 2:
                                printf("action 2 :\n");
                                filePlanets(mercury_asymmetric, venus_asymmetric, earth_asymmetric, mars_asymmetric,
                                            jupiter_asymmetric, saturn_asymmetric, uranus_asymmetric,
                                            neptune_asymmetric, moon_asymmetric);
                                printf("stock in file done ! \n");
                                // libération de toute la mémoire
                                deletePlanet(&mercury_asymmetric);
                                deletePlanet(&venus_asymmetric);
                                deletePlanet(&earth_asymmetric);
                                deletePlanet(&mars_asymmetric);
                                deletePlanet(&jupiter_asymmetric);
                                deletePlanet(&saturn_asymmetric);
                                deletePlanet(&uranus_asymmetric);
                                deletePlanet(&neptune_asymmetric);
                                deletePlanet(&moon_asymmetric);
                                break;
                            default:
                                out++;
                        }
                        break;
                    case 3:
                        printf("method 3 :\n");
                        printf("average of the energy variation the planet for verification :\n");
                        //créer les valeurs avec la methode d'Euler symmetric et en même temps afficher la moyenne de variation d'énergie pour vérifier que les valeurs obtenues ont du sens
                        printf(" * mercury symmetric");
                        mercury_symmetric = createPlanetSymetrique("mercury_symmetric", MASS_MERCURY, HALF_MAJOR_AXIS_MERCURY,ECCENTRICITY_MERCURY);
                        printf(" * venus symmetric");
                        venus_symmetric = createPlanetSymetrique("venus_symmetric", MASS_VENUS, HALF_MAJOR_AXIS_VENUS,ECCENTRICITY_VENUS);
                        printf(" * earth symmetric");
                        earth_symmetric = createPlanetSymetrique("earth_symmetric", MASS_TERRE, HALF_MAJOR_AXIS_TERRE, ECCENTRICITY_TERRE);
                        printf(" * mars symmetric");
                        mars_symmetric = createPlanetSymetrique("mars_symmetric", MASS_MARS, HALF_MAJOR_AXIS_MARS,ECCENTRICITY_MARS);
                        printf(" * jupiter symmetric");
                        jupiter_symmetric = createPlanetSymetrique("jupiter_symmetric",MASS_JUPITER,HALF_MAJOR_AXIS_JUPITER,ECCENTRICITY_JUPITER);
                        printf(" * saturn symmetric");
                        saturn_symmetric = createPlanetSymetrique("saturn_symmetric", MASS_SATURNE,HALF_MAJOR_AXIS_SATURNE,ECCENTRICITY_SATURNE);
                        printf(" * uranus symmetric");
                        uranus_symmetric = createPlanetSymetrique("uranus_symmetric", MASS_URANUS,HALF_MAJOR_AXIS_URANUS,ECCENTRICITY_URANUS);
                        printf(" * neptune symmetric");
                        neptune_symmetric = createPlanetSymetrique("neptune_symmetric", MASS_NEPTUNE,HALF_MAJOR_AXIS_NEPTUNE,ECCENTRICITY_NEPTUNE);
                        printf(" * moon symmetric");
                        moon_symmetric = createMoonSymetrique("moon_symmetric", MASS_LUNE, HALF_MAJOR_AXIS_LUNE,ECCENTRICITY_LUNE);
                        printf(" * mercury asymmetric");
                        mercury_asymmetric = createPlanetAsymetrique("mercury_asymmetric", MASS_MERCURY,HALF_MAJOR_AXIS_MERCURY,ECCENTRICITY_MERCURY);
                        printf(" * venus asymmetric");
                        venus_asymmetric = createPlanetAsymetrique("venus_asymmetric", MASS_VENUS,HALF_MAJOR_AXIS_VENUS,ECCENTRICITY_VENUS);
                        printf(" * earth asymmetric");
                        earth_asymmetric = createPlanetAsymetrique("earth_asymmetric", MASS_TERRE,HALF_MAJOR_AXIS_TERRE,ECCENTRICITY_TERRE);
                        printf(" * mars asymmetric");
                        mars_asymmetric = createPlanetAsymetrique("mars_asymmetric", MASS_MARS, HALF_MAJOR_AXIS_MARS,ECCENTRICITY_MARS);
                        printf(" * jupiter asymmetric");
                        jupiter_asymmetric = createPlanetAsymetrique("jupiter_asymmetric", MASS_JUPITER,HALF_MAJOR_AXIS_JUPITER,ECCENTRICITY_JUPITER);
                        printf(" * saturn asymmetric");
                        saturn_asymmetric = createPlanetAsymetrique("saturn_asymmetric", MASS_SATURNE,HALF_MAJOR_AXIS_SATURNE, ECCENTRICITY_SATURNE);
                        printf(" * uranus asymmetric");
                        uranus_asymmetric = createPlanetAsymetrique("uranus_asymmetric", MASS_URANUS,HALF_MAJOR_AXIS_URANUS, ECCENTRICITY_URANUS);
                        printf(" * neptune asymmetric");
                        neptune_asymmetric = createPlanetAsymetrique("neptune_asymmetric", MASS_NEPTUNE, HALF_MAJOR_AXIS_NEPTUNE,ECCENTRICITY_NEPTUNE);
                        printf(" * moon asymmetric");
                        moon_asymmetric = createMoonAsymetrique("moon_asymmetric", MASS_LUNE,HALF_MAJOR_AXIS_LUNE,ECCENTRICITY_LUNE);
                        //sélectionner ce qu'on veut entre :
                        //      afficher les valeurs dans la console
                        //      rentrer les valeurs dans un fichier .json
                        //      sortir du programme
                        printf("        Select an action  : \n");
                        printf("            1 -> print here\n");
                        printf("            2 -> stock in file\n");
                        printf("            other number -> exit\n");
                        scanf("%d", &action);
                        switch (action) {
                            case 1:
                                printf("action 1 :\n");
                                printPlanetsBoth(mercury_symmetric, venus_symmetric, earth_symmetric, mars_symmetric,
                                                 jupiter_symmetric, saturn_symmetric, uranus_symmetric,
                                                 neptune_symmetric, moon_symmetric, mercury_asymmetric,
                                                 venus_asymmetric, earth_asymmetric, mars_asymmetric,
                                                 jupiter_asymmetric, saturn_asymmetric, uranus_asymmetric,
                                                 neptune_asymmetric, moon_asymmetric);
                                // libération de toute la mémoire
                                deletePlanet(&mercury_symmetric);
                                deletePlanet(&venus_symmetric);
                                deletePlanet(&earth_symmetric);
                                deletePlanet(&mars_symmetric);
                                deletePlanet(&jupiter_symmetric);
                                deletePlanet(&saturn_symmetric);
                                deletePlanet(&uranus_symmetric);
                                deletePlanet(&neptune_symmetric);
                                deletePlanet(&moon_symmetric);
                                deletePlanet(&mercury_asymmetric);
                                deletePlanet(&venus_asymmetric);
                                deletePlanet(&earth_asymmetric);
                                deletePlanet(&mars_asymmetric);
                                deletePlanet(&jupiter_asymmetric);
                                deletePlanet(&saturn_asymmetric);
                                deletePlanet(&uranus_asymmetric);
                                deletePlanet(&neptune_asymmetric);
                                deletePlanet(&moon_asymmetric);
                                break;
                            case 2:
                                printf("action 2 :\n");
                                filePlanetsBoth(mercury_symmetric, venus_symmetric, earth_symmetric, mars_symmetric,
                                                jupiter_symmetric, saturn_symmetric, uranus_symmetric,
                                                neptune_symmetric, moon_symmetric, mercury_asymmetric,
                                                venus_asymmetric, earth_asymmetric, mars_asymmetric, jupiter_asymmetric,
                                                saturn_asymmetric, uranus_asymmetric, neptune_asymmetric,
                                                moon_asymmetric);
                                printf("stock in file done ! \n");
                                // libération de toute la mémoire
                                deletePlanet(&mercury_symmetric);
                                deletePlanet(&venus_symmetric);
                                deletePlanet(&earth_symmetric);
                                deletePlanet(&mars_symmetric);
                                deletePlanet(&jupiter_symmetric);
                                deletePlanet(&saturn_symmetric);
                                deletePlanet(&uranus_symmetric);
                                deletePlanet(&neptune_symmetric);
                                deletePlanet(&moon_symmetric);
                                deletePlanet(&mercury_asymmetric);
                                deletePlanet(&venus_asymmetric);
                                deletePlanet(&earth_asymmetric);
                                deletePlanet(&mars_asymmetric);
                                deletePlanet(&jupiter_asymmetric);
                                deletePlanet(&saturn_asymmetric);
                                deletePlanet(&uranus_asymmetric);
                                deletePlanet(&neptune_asymmetric);
                                deletePlanet(&moon_asymmetric);
                                break;
                            default:
                                out++;
                        }
                        break;


                    default:
                        out++;
                }
                break;

            default:
                out++;
        }
        if(out>0){
            printf("exit\n");
            exit=out;
        }

    }

    return 0;
}


