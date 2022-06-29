//
// Created by vince on 24/06/2022.
//

#ifndef PROJETFINVINCENT_LISTE_H
#define PROJETFINVINCENT_LISTE_H

#include "infoPLanet.h"
#include "point.h"

struct List{
    unsigned int size;
    struct Point* head;
    struct Point* tail;
};

struct List* createEmptyList();

void addFirst(struct List* l, struct Vect* position, struct Vect* speed, int time);
void addLast(struct List* l, struct Vect* position, struct Vect* speed, int time);

bool isListEmpty(struct List* l);

void printList(struct List* l);

unsigned int listSize(struct List* l);


void deleteFirst(struct List* l);

void deleteList(struct List** l);


#endif //PROJETFINVINCENT_LISTE_H
