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

#ifndef NODE_H // "if not defined NODE_H," prevents .h file from being included multiple times
#define NODE_H // ^ if it has not been defined then define it

/*
    Node in data structure (singly linked list)

    Ownership rules (rules for managing memory):
    - Nodes are always heap allocated with node_create
    - Nodes are always freed with node_destroy
    - The List owns the nodes NOT the caller (Caller = the code (func.) that calls another func.)
*/
typedef struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list (or NULL)
    //         ^ Dereference Operator: Accesses the value at the memory address stored 
} Node;

/*
    Allocates memory on the heap for a new Node
    Ownership of returned pointer is transferred to caller
*/
Node* node_create(int data);

/*
    Frees memory allocated for a Node
    The pointer is INVALID after this call
*/
void node_destroy(Node *node); // same as (Node *node); just style preference

#endif // end of NODE_H