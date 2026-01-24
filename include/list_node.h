/*
    header file for node structure
    defines a simple linked list node and its associated functions
    the actual implementation of the functions would be in node.c
*/

/*
    Python import:   Loads code at runtime
    Java interface:  Declares behavior, no implementation
    C header file:   Declares what exists, not how it works
*/

#ifndef LISTNODE_H // "if not defined NODE_H," prevents .h file from being included multiple times
#define LISTNODE_H // ^ if it has not been defined then define it

/*
    ListNode in data structure (singly linked list)

    Ownership rules (rules for managing memory):
    - ListNodes are always heap allocated with node_create
    - ListNodes are always freed with node_destroy
    - The List owns the nodes NOT the caller (Caller = the code (func.) that calls another func.)
*/
typedef struct ListNode
{
    int data;              // Data stored in the node
    struct ListNode *next; // Pointer to the next node in the list (or NULL)
    //         ^ Dereference Operator: Accesses the value at the memory address stored
} ListNode;

/*
    Allocates memory on the heap for a new ListNode
    Ownership of returned pointer is transferred to caller
*/
ListNode *list_node_create(int data);

/*
    Frees memory allocated for a ListNode
    The pointer is INVALID after this call
*/
void list_node_destroy(ListNode *node); // same as (ListNode *node); just style preference

#endif // end of NODE_H