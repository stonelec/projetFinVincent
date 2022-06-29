//
// Created by vince on 24/06/2022.
//
#include "list.h"
#include "queuelist.h"
//création queue vide
struct Queue* createEmptyQueue(){
    struct Queue* q = malloc(sizeof(struct Queue));
    if(q != NULL){
        q->l = createEmptyList();
    }
    return q;
}
//ajout d'une valeur à un queue
void enqueue(struct Queue* q, struct Vect* position, struct Vect* speed, int time, bool* valid){
    *valid = true;
    addLast(q->l, position,speed,time);
}
//retourne la taille d'un queue
unsigned int queueSize(struct Queue* q){
    return listSize(q->l);
}
//vérifie si un queue est vide
bool isQueueEmpty(struct Queue* q){
    return (queueSize(q) == 0);
}
//afficher un queue dans la console
void printQueue(struct Queue* q){

    struct Point* iter = q->l->head;
    printPoint(iter);

    iter = iter->next;
    while (iter!= NULL){
        printf("\n,");
        printPoint(iter);

        iter = iter->next;
        }
        printf("\n]");
}
//supprimer un queue
void deleteQueue(struct Queue** q){
    struct List* temp = (*q)->l;
    deleteList(&temp);
    free(*q);
    *q=NULL;
}

