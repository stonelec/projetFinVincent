//
// Created by vince on 24/06/2022.
//

#include "list.h"
//créer un liste vide
struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    if(l != NULL){
        l->head = NULL;
        l->size = 0;
        l->tail = NULL;
    }
    return l;
}
//ajouter un point en debut de liste
void addFirst(struct List* l, struct Vect* position, struct Vect* speed, int time){
    struct Point* newHead = createPoint(position,speed,time);
    struct Point* formerHead = l->head;
    l->head = newHead;
    newHead->next = formerHead;
    l->size += 1;
}
//ajouter un point en fin de liste
void addLast(struct List* l, struct Vect* position, struct Vect* speed, int time){
    struct Point* newTail = createPoint(position,speed,time);
    if (isListEmpty(l)){
        l->head = newTail;
        l->tail = newTail;
        l->size++;
    } else {
        l->tail->next = newTail;
        l->tail = newTail;
        l->size += 1;
    }
}
//vérifier si une liste est vide
bool isListEmpty(struct List* l){
    return l->head == NULL;
}
//afficher une liste dans la console
void printList(struct List* l){
    struct Point* iter = l->head;
    for(int i=0; i<l->size;i++){
        printPoint(iter);
        iter = iter->next;
    }
    printf("NULL\n");
}
//retourner la taille d'une liste
unsigned int listSize(struct List* l){
    return l->size;
}
//supprimer le premier élément d'une liste
void deleteFirst(struct List* l){
    if(!isListEmpty(l)){
        struct Point* newHead;
        newHead = l->head->next;
        deletePoint(&l->head);
        l->size -= 1;
        l->head = newHead;
    }
}
//supprimer une liste
void deleteList(struct List** l){
    unsigned int n = listSize(*l);
    for(int i = 0; i<n; i++){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}


