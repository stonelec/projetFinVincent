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

void enqueue(struct Queue* q, struct vect* position, struct vect* vitesse, int temps, bool* valid){
    *valid = true;
    struct point* newHead = createPoint(position,vitesse,temps);
    newHead->next = q->l->head;
    q->l->head = newHead;
    q->l->size ++;

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
    if(queueSize(q) == 1){
        struct point* res = getItemPos(q->l,0,valid);
        deleteFirst(q->l);
        return res;
    }
    struct point* res = getItemPos(q->l, queueSize(q)-1,valid);
    deleteItemPos(q->l, queueSize(q)-1,valid);
    return res;
}

unsigned int queueSize(struct Queue* q){
    return listSize(q->l);
}

bool isQueueEmpty(struct Queue* q){
    return (queueSize(q) == 0);
}

void printQueue(struct Queue* q){
    if(isQueueEmpty(q)){
        printf("rear -> NULL <- front");
        return;
    }
    struct point* iter = q->l->head;
    printf("rear -> ");
    printPoint(iter);
    unsigned int size = queueSize(q);
    iter = iter->next;
    for(unsigned int i=1; i<size;i++){
        printf("\n");
        printPoint(iter);
        iter = iter->next;
    }
    printf(" <- front\n");
}

void deleteQueue(struct Queue** q){
    struct List* temp = (*q)->l;
    deleteList(&temp);
    free(*q);
}

