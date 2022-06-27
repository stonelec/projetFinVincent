cmake_minimum_required(VERSION 3.18)
project(projetFinVincent C)

set(CMAKE_C_STANDARD 99)

add_executable(projetFinVincent main.c planet.c planet.h trajectory.c trajectory.h vector.c vector.h point.c point.h infoPLanet.h liste.c liste.h queueliste.c queueliste.h)

target_link_libraries(projetFinVincent m)