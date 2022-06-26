//
// Created by vince on 24/06/2022.
//

#include "liste.h"

struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    if(l != NULL){
        l->head = NULL;
        l->size = 0;
    }
    return l;
}

void addFirst(struct List* l, struct vect* position, struct vect* vitesse, int temps){
    struct point* newHead = createPoint(position,vitesse,temps);
    struct point* formerHead = l->head;
    l->head = newHead;
    newHead->next = formerHead;
    l->size += 1;
}

bool isListEmpty(struct List* l){
    return l->head == NULL;
}

struct point* getItemPos(struct List* l, unsigned int place, bool* valid){
    if((place < 0) || (place >= listSize(l))){
        *valid = false;
        return 0;
    }
    struct point* iter = l->head;
    *valid = true;
    for(int i=0; i<place; i++){
        iter = iter->next;
    }
    if(iter == NULL){
        *valid = false;
    }
    return iter;
}

void deleteFirst(struct List* l){
    if(!isListEmpty(l)){
        struct point* newHead;
        newHead = l->head->next;
        free(l->head);
        l->size -= 1;
        l->head = newHead;
    }
}

void printList(struct List* l){
    struct point* iter = l->head;
    for(int i=0; i<l->size;i++){
        printPoint(iter);
        iter = iter->next;
    }
    printf("NULL\n");
}

unsigned int listSize(struct List* l){
    return l->size;
}

void addItemPos(struct List* l, struct vect* position, struct vect* vitesse, int temps , unsigned int place, bool* valid){
    if(isListEmpty(l) && place == 0){
        addFirst(l, position, vitesse, temps);
        *valid = true;
    }
    else {
        struct point* newItem = createPoint(position, vitesse, temps);
        struct point* iter = l->head;
        if(place > listSize(l) || place < 0) {
            *valid = false;
            return;
        }
        if(place == 0) {
            addFirst(l, position, vitesse, temps);
            l->size++;
            *valid = true;
        }
        else{
            for (int i = 0; i < place - 1; i++) {
                iter = iter->next;
            }
            struct point* nextItem = iter->next;
            iter->next = newItem;
            newItem->next = nextItem;
            l->size += 1;
            *valid = true;
        }
    }
}

void deleteItemPos(struct List* l, unsigned int place, bool* valid){
    if(isListEmpty(l) || place < 0 || listSize(l) < place){
        *valid = false;
        return;
    }
    *valid = true;
    if(place == 0){
        deleteFirst(l);
    }
    else {
        struct point* nextItem;
        struct point* iter = l->head;
        for (int i = 0; i < place - 1; i++) {
            iter = iter->next;
        }
        struct point* deletedItem = iter->next;
        nextItem = iter->next->next;
        iter->next = nextItem;
        free(deletedItem);
        l->size--;
    }
}

void deleteList(struct List** l){
    struct List* temp = *l;
    unsigned int n = listSize(temp);
    for(int i = 0; i<n; i++){
        deleteFirst(temp);
    }
    free(temp);
    *l = NULL;
}
