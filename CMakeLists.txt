cmake_minimum_required(VERSION 3.18)
project(projetFinVincent C)

set(CMAKE_C_STANDARD 99)

add_executable(projetFinVincent main.c planet.c planet.h trajectory.c trajectory.h vector.c vector.h point.c point.h infoPLanet.h list.c list.h queuelist.c queuelist.h)

target_link_libraries(projetFinVincent m)