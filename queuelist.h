//
// Created by vince on 24/06/2022.
//

#ifndef PROJETFINVINCENT_QUEUELISTE_H
#define PROJETFINVINCENT_QUEUELISTE_H

#include "list.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Queue{
    struct List* l;
};

struct Queue* createEmptyQueue();

void enqueue(struct Queue* q, struct Vect* position, struct Vect* speed, int time, bool* valid);


unsigned int queueSize(struct Queue* q);

bool isQueueEmpty(struct Queue* q);

void printQueue(struct Queue* q);

void deleteQueue(struct Queue** q);

#endif //PROJETFINVINCENT_QUEUELISTE_H
