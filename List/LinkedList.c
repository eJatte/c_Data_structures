#include "LinkedList.h"

LinkedList* LinkedList_empty(void free_function(void*)){
    Element *head = malloc(sizeof(Element));
    Element *tail = malloc(sizeof(Element));
    LinkedList *linkedList = malloc(sizeof(LinkedList));

    if(head == NULL || tail == NULL || linkedList == NULL){
        if(head != NULL){free(head);}
        if(tail != NULL){free(tail);}
        if(linkedList != NULL){free(linkedList);}
        return NULL;
    }

    head->value = NULL;
    head->previous = NULL;
    head->next = tail;

    tail->value = NULL;
    tail->previous = head;
    tail->next = NULL;

    linkedList->head = head;
    linkedList->tail = tail;
    linkedList->size = 0;
    linkedList->free_function = free_function;

    return linkedList;
}
