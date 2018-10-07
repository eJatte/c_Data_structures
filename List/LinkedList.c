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

int LinkedList_size(LinkedList *linkedList){
    if(linkedList == NULL){return -1;}
    return linkedList->size;
}

int LinkedList_isEmpty(LinkedList *linkedList){
    if(linkedList == NULL){return -1;}
    return LinkedList_size(linkedList) == 0;
}

Element* LinkedList_next(Element *element){
    if(element == NULL){return NULL;}
    return element->next;
}

Element* LinkedList_previous(Element *element){
    if(element == NULL){return NULL;}
    return element->previous;
}

Element* LinkedList_first(LinkedList *linkedList){
    if(linkedList == NULL){return NULL;}
    return LinkedList_next(linkedList->head);
}

Element* LinkedList_end(LinkedList *linkedList){
    if(linkedList == NULL){return NULL;}
    return linkedList->tail;
}

Element* LinkedList_insert( LinkedList *linkedList,
                            Element *element,
                            void *value)
{
    if(linkedList == NULL ||
       element == NULL ||
       element == linkedList->head ||
       value == NULL
    ){return NULL;}

    Element *newElement = malloc(sizeof(Element));
    if(newElement == NULL){return NULL;}

    newElement->value = value;

    Element *previous = element->previous;
    previous->next = newElement;
    newElement->previous = previous;
    newElement->next = element;
    element->previous = newElement;

    linkedList->size++;

    return newElement;
}

void* LinkedList_inspect(Element *element){
    if(element == NULL){return NULL;}
    return element->value;
}

void* LinkedList_extract(LinkedList *linkedList, Element *element){
    if(linkedList == NULL ||
       element == NULL ||
       element == linkedList->head ||
       element == linkedList->tail
    ){
        return NULL;
    }
    void* value = element->value;
    Element *previous = element->previous;
    Element *next = element->next;

    previous->next = next;
    next->previous = previous;

    free(element);

    linkedList->size--;

    return value;
}

Element* LinkedList_get(LinkedList *linkedList, int index){
    if(linkedList == NULL || index < 0 || index >= linkedList->size){
        return NULL;
    }
    Element *e = LinkedList_first(linkedList);
    while(index > 0){
        e = e->next;
        index--;
    }
    return e;
}

Element* LinkedList_remove(LinkedList *linkedList, Element *element){
    if(linkedList == NULL || element == NULL){return NULL;}
    Element *next = element->next;
    void *val = LinkedList_extract(linkedList, element);
    if(val == NULL){return NULL;}

    if(linkedList->free_function != NULL){
        linkedList->free_function(val);
    }
    return next;
}

void LinkedList_free(LinkedList *linkedList){
    if(linkedList == NULL){return;}

    while(!LinkedList_isEmpty(linkedList)){
        Element *element = LinkedList_first(linkedList);
        LinkedList_remove(linkedList, element);
    }
    free(linkedList->head);
    free(linkedList->tail);
    free(linkedList);
}
