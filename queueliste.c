//
// Created by vince on 24/06/2022.
//

#include "queueliste.h"


//1

struct Queue* createEmptyQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    if (q!=NULL) {
        q->l = createEmptyList();
    }
    return q;
}

//2

void enqueue(struct Queue* q, struct point* point, bool* valid){
    *valid=true;
    struct Cell* newHead = createCell(point);
    newHead->next = q->l->head;
    q->l->head = newHead;
    q->l->size ++;
}

//3

int head(struct Queue* q, bool* valid) {
    *valid = true;
    if (q->l->size == 0) {
        *valid = false;
        return 000;
    } else {
        struct Cell* stock = q->l->head;
        while (stock->next != NULL) {
            stock = stock->next;
        }
        return stock->point;
    }
}
//4

int dequeue(struct Queue* q, bool* valid){
    *valid=true;
    if (q->l->size == 0) {
        *valid = false;
        return 000;
    } else {
        int place = listSize(q->l)-1;
        int result = getItemPos(q->l, place, valid);
        deleteItemPos(q->l, place, valid);
        return result;
    }
}

//5

unsigned int queueSize(struct Queue* q){
    return q->l->size;
}

//6

bool isQueueEmpty(struct Queue* q){
    return (isListEmpty(q->l));
}

//7

void printQueue(struct Queue* q){
    printf("rear -> ");
    if(isQueueEmpty(q)){
        printf("NULL <- front\n");
    } else {
        struct Cell* stock = q->l->head;
        while (stock != NULL) {
            printf("%d - ", stock->point);
            stock = stock->next;
        }
        printf("\b\b\b <- front\n");
    }
}

//8

void deleteQueue(struct Queue** q) {
    deleteList(&((*q)->l));
    free(*q);
    q=NULL;
}
