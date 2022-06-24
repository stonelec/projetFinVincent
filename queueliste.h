//
// Created by vince on 24/06/2022.
//

#ifndef PROJETFINVINCENT_QUEUELISTE_H
#define PROJETFINVINCENT_QUEUELISTE_H

#include "liste.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Queue{
    struct List* l;
};


//1
struct Queue* createEmptyQueue();
//2
void enqueue(struct Queue* q, struct point* point, bool* valid);
//3
int head(struct Queue* q, bool* valid);
//4
int dequeue(struct Queue* q, bool* valid);
//5
unsigned int queueSize(struct Queue* q);
//6
bool isQueueEmpty(struct Queue* q);
//7
void printQueue(struct Queue* q);
//8
void deleteQueue(struct Queue** q);
#endif //PROJETFINVINCENT_QUEUELISTE_H
