cmake_minimum_required(VERSION 3.18)
project(projetFinVincent C)

set(CMAKE_C_STANDARD 99)

add_executable(projetFinVincent main.c planete.c planete.h trajectoire.c trajectoire.h vecteur.c vecteur.h point.c point.h infoPLanete.h liste.c liste.h queueliste.c queueliste.h)

target_link_libraries(projetFinVincent m)