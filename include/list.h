#ifndef LIST_H
#define LIST_H

#include "list_node.h" // Include node structure definition
#include <stdbool.h>   // for bool type
//_Bool is the primitive and ^this is a macro for it

/*
    A List is container that owns multiple ListNodes

    Ownership rules:
    - List is heap allocated with list_create
    - Destoying list (with list_destroy) frees all owned ListNodes
    - Owns all ListNodes reachable from its head
*/
typedef struct
{
    ListNode *head; // Pointer to the first node in the list (or NULL if empty)
} List;

/*
    Allocates memory on the heap for a new List
    Ownership of returned pointer is transferred to caller
*/
List *list_create(void);

/*
    Frees memory allocated for a List and all its owned ListNodes
    The pointer is INVALID after this call
*/
void list_destroy(List *list);

/*
    Adds a new ListNode with the given data to the front of the List.
    Return false if memory allocation fails.
*/
bool list_push(List *list, int data);

/*
    Removes the ListNode first encountered that contains the given data.
    Frees removed ListNode's memory.
*/
bool list_remove(List *list, int data);

#endif