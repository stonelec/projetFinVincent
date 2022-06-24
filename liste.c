//
// Created by vince on 24/06/2022.
//

#include "liste.h"

struct Cell* createCell(struct point* point){
    struct Cell* cell = malloc(sizeof (struct Cell));
    if(cell!=NULL){
        cell -> point = NULL;
        cell -> next = NULL;
    }
    return cell;
}
struct List* createEmptyList(){
    struct List* list = malloc(sizeof (struct List));
    if(list!=NULL){
        list -> size = 0;
        list -> head = NULL;
    }
    return list;
}
void addFirst(struct List* l, struct point* point){
    struct point* newHead = point;
    newHead->next = l->head;
    l->head = newHead;
    l->size ++;
}

bool isListEmpty(struct List* l){
    return l->size == 0;
}

int getItemPos(struct List* l, unsigned int position, bool* valid){
    *valid = true;
    if (position >= l->size){
        *valid = false;
        return -42;
    }
    struct Cell* item = l->head;
    for(unsigned int i=0 ; i<position ; i++){
        item = item->next;
    }
    return item->point;
}

void deleteFirst(struct List* l){
    if(isListEmpty(l)){
        return;
    }
    struct Cell* stock = l -> head -> next;
    l -> size--;
    free(l->head);
    l->head = stock;
}

void printList(struct List* l){
    if(l->size == 0){
        printf("NULL\n");
        return;
    }
    struct Cell *stock = l->head;
    for (unsigned int i = 0; i < l->size; i++) {
        printf("%d->", stock->point);
        stock = stock->next;
    }
    printf("NULL\n");
}

unsigned int listSize(struct List* l){
    return l->size;
}

void addItemPos(struct List* l, struct point* point,unsigned int position, bool* valid) {
    *valid = true;
    if (position >l->size) {
        *valid = false;
        return;
    }
    if (position == 0) {
        addFirst(l, point);
        return;
    }
    struct Cell *beforeAddCell = l->head;
    for (int i = 0; i < position-1; i++) {
        beforeAddCell = beforeAddCell->next;
    }
    struct Cell *addCell = createCell(point);
    addCell->next = beforeAddCell->next;
    beforeAddCell->next = addCell;
    l->size++;
}

void deleteItemPos(struct List* l,unsigned int position, bool* valid){
    *valid = true;
    if(position == 0){
        deleteFirst(l);
        return;
    }
    if(position > l->size){
        *valid=false;
        return;
    }
    struct Cell* beforeDeleteItem = l->head;
    for(unsigned int i=0 ; i!=position-1 ; i++){
        beforeDeleteItem = beforeDeleteItem -> next;
    }
    struct Cell* deleteItem = beforeDeleteItem -> next;
    beforeDeleteItem -> next = deleteItem -> next;
    free(deleteItem);
    l->size--;
}


void deleteList(struct List** l){
    struct List* list = *l;
    while (list->head != NULL){
        deleteFirst(list);
    }
    free(list);
}
