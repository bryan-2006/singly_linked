#include <stdlib.h> // for malloc and free
// #include <stdio.h>  // for printf (debugging)
#include "../include/list_node.h"

ListNode *list_node_create(int data)
{
    ListNode *node = malloc(sizeof(ListNode)); // allocate memory for a ListNode

    if (!node)
    {
        return NULL; // return NULL if memory allocation fails
    }

    node->data = data; // set the data
    node->next = NULL; // initialize next to NULL
    return node;       // return pointer to the newly created node
}

void list_node_destroy(ListNode *node)
{
    // does not update list pointers; caller must handle that
    // if (node) {
    //     free(node); // free the memory allocated for the node
    // }
    free(node); // no need for if check; free(NULL) is safe
}