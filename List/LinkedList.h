#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    void *value;

    struct Element *previous;
    struct Element *next;
}Element;

typedef struct LinkedList{
    Element *head;
    Element *tail;

    int size;

    void (*free_function)(void*);
}LinkedList;

/*
* Function:     LinkedList_empty
*
* Description:  Returns an empty LinkedList.
*
* Input:        void free_function(void*) - free function to free value stored
*                                           in list.
*
* Return:       LinkedList* - pointer to the empty LinkedList.
*               NULL - on failure.
*/
LinkedList* LinkedList_empty(void (*free_function)(void*));

/*
* Function:     LinkedList_insert
*
* Description:  Inserts <value> immediately before the given element.
*
* Input:        Element *element - the element position to insert before.
*               void *value - the value to insert into the list.
*
* Return:       Element* - pointer to the newly inserted Element.
*               NULL - if <element> is the head of the list or
*                      on other failure
*/
Element* LinkedList_insert(Element *element, void *value);

/*
* Function:     LinkedList_isEmpty
*
* Description:  Checks if the LinkedList is empty.
*
* Input:        LinkedList *linkedList - the LinkedList to check.
*
* Return:       int - boolean stating whether it is empty or not.
*/
int LinkedList_isEmpty(LinkedList *linkedList);

/*
* Function:     LinkedList_size
*
* Description:  Returns the number of elements in the list,
*               excluding head and tail.
*
* Input:        LinkedList *linkedList - the LinkedList to check.
*
* Return:       int - number of elements.
*/
int LinkedList_size(LinkedList *linkedList);

/*
* Function:     LinkedList_inspect
*
* Description:  Returns the value of the given element.
*
* Input:        Element *element - the element
*
* Return:       void* - the value.
*               NULL - if the element has no value.
*/
void* LinkedList_inspect(Element *element);

/*
* Function:     LinkedList_extract
*
* Description:  Returns the value of the given element and removes it from
*               the list.
*
* Input:        LinkedList *linkedList - the list to remove the element from.
*               Element *element - the element.
*
* Return:       void* - the value.
*               NULL - if the element has no value.
*/
void* LinkedList_extract(LinkedList *linkedList, Element *element);

/*
* Function:     LinkedList_first
*
* Description:  Returns the first element in the list.
*
* Input:        LinkedList *linkedList - the list.
*
* Return:       Element* - the element.
*/
Element* LinkedList_first(LinkedList *linkedList);

/*
* Function:     LinkedList_end
*
* Description:  Returns the tail of the list. The tail has no value.
*
* Input:        LinkedList *linkedList - the list.
*
* Return:       Element* - the element.
*/
Element* LinkedList_end(LinkedList *linkedList);

/*
* Function:     LinkedList_next
*
* Description:  Returns the element after the input element.
*
* Input:        Element *element - the element.
*
* Return:       Element* - the element after the input element.
*               NULL - if the is no such element.
*/
Element* LinkedList_next(Element *element);

/*
* Function:     LinkedList_previous
*
* Description:  Returns the element before the input element.
*
* Input:        Element *element - the element.
*
* Return:       Element* - the element before the input element.
*               NULL - if the is no such element.
*/
Element* LinkedList_previous(Element *element);

/*
* Function:     LinkedList_get
*
* Description:  Get element by index in list. Exluding head and tail.
*
* Input:        LinkedList *linkedList - the list.
*               int index - the index of the wanted element.
*
* Return:       Element* - the element at <index>.
*               NULL - if the index exceeds the list size.
*/
Element* LinkedList_get(LinkedList *linkedList, int index);

/*
* Function:     LinkedList_remove
*
* Description:  Removes an element from the list.
*               Free:s the value of the element.
*
* Input:        LinkedList *linkedList - the list to remove the element from.
*               Element *element - the element to remove.
*
* Return:       Element* - the element immediately after the removed element.
*               NULL - if the element was head or tail.
*/
Element* LinkedList_remove(LinkedList *linkedList, Element *element);
