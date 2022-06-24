//
// Created by vince on 24/06/2022.
//

#ifndef PROJETFINVINCENT_LISTE_H
#define PROJETFINVINCENT_LISTE_H

#include "infoPLanete.h"
#include "point.h"

//operation
struct Cell{
    struct point* point;
    struct Cell* next;
};
struct List{
    unsigned int size;
    struct Cell* head;
};


struct Cell* createCell(struct point* point);
struct List* createEmptyList();

void addFirst(struct List* l, struct point* point);

bool isListEmpty(struct List* l);

int getItemPos(struct List* l, unsigned int position, bool* valid);

void deleteFirst(struct List* l);

void printList(struct List* l);

unsigned int listSize(struct List* l);

void addItemPos(struct List* l, struct point* point, unsigned int position, bool* valid);

void deleteItemPos(struct List* l, unsigned int position, bool* valid);

void deleteList(struct List** l);

#endif //PROJETFINVINCENT_LISTE_H
