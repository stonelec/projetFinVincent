//
// Created by vince on 24/06/2022.
//

#ifndef PROJETFINVINCENT_LISTE_H
#define PROJETFINVINCENT_LISTE_H

#include "infoPLanete.h"
#include "point.h"

struct List{
    unsigned int size;
    struct point* head;
};

struct List* createEmptyList();

void addFirst(struct List* l, struct vect* position, struct vect* vitesse, int temps);

struct point* getItemPos(struct List* l, unsigned int place, bool* valid);

void deleteFirst(struct List* l);

void printList(struct List* l);

unsigned int listSize(struct List* l);

void addItemPos(struct List* l, struct vect* position, struct vect* vitesse, int temps, unsigned int place, bool* valid);

void deleteItemPos(struct List* l, unsigned int place, bool* valid);

void deleteList(struct List** l);


#endif //PROJETFINVINCENT_LISTE_H
