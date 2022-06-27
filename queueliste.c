//
// Created by vince on 24/06/2022.
//
#include "liste.h"
#include "queueliste.h"
struct Queue* createEmptyQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    if(q != NULL){
        q->l = createEmptyList();
    }
    return q;
}

void enqueue(struct Queue* q, struct vect* position, struct vect* speed, int time, bool* valid){
    *valid = true;
    addLast(q->l, position,speed,time);
}

struct point* head(struct Queue* q, bool* valid){
    if(isQueueEmpty(q)){
        *valid = false;
        return 0;
    }
    *valid = true;
    struct point* iter = q->l->head;
    while(iter->next != NULL){
        iter = iter->next;
    }
    return iter;
}

struct point* dequeue(struct Queue* q, bool* valid){
    *valid = true;
    if(isQueueEmpty(q)){
        *valid = false;
        return 0;
    }
    if(queueSize(q) > 0){
        struct point* res = q->l->head;
        deleteFirst(q->l);
        return res;
    }
    /*
    struct point* res = getItemPos(q->l, queueSize(q)-1,valid);
    deleteItemPos(q->l, queueSize(q)-1,valid);
    return res;
     */
}

unsigned int queueSize(struct Queue* q){
    return listSize(q->l);
}

bool isQueueEmpty(struct Queue* q){
    return (queueSize(q) == 0);
}

void printQueue(struct Queue* q){
/*
    bool valid = true;
    if(isQueueEmpty(q)){
        printf("rear -> NULL <- front");
        return;
    }
    printf("rear -> ");
    unsigned int size = queueSize(q);
    for(unsigned int i=1; i<size;i++){
        printf("\n");
        printPoint(dequeue(q, &valid));
    }
    printf(" <- front\n");
    */
    struct point* iter = q->l->head;
    printf(",[[%f, %f, %f], ", iter->position->x, iter->position->y, iter->position->z);
    printf("[%f, %f, %f],", iter->speed->x, iter->speed->y, iter->speed->z);
    printf("%d]", iter->time);
    iter = iter->next;
    while (iter!= NULL){
        printf("\n");
        printf(",[[%f, %f, %f], ", iter->position->x, iter->position->y, iter->position->z);
        printf("[%f, %f, %f],", iter->speed->x, iter->speed->y, iter->speed->z);
        printf("%d]", iter->time);
        iter = iter->next;
    }
    printf("]\n}");

}

void deleteQueue(struct Queue** q){
    struct List* temp = (*q)->l;
    deleteList(&temp);
    free(*q);
}

