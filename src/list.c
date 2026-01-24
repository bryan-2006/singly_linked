#include <stdlib.h> // for malloc and free
// #include <stdio.h>  // for printf (debugging)
#include "../include/list.h"

List *list_create(void)
{
    List *list = malloc(sizeof(List)); // allocate memory for a List

    if (!list)
    {
        return NULL; // return NULL if memory allocation fails
    }

    list->head = NULL; // initialize head to NULL
    return list;       // return pointer to the newly created list
}

void list_destroy(List *list)
{
    /*
        Free all nodes before the list itself.
        ^ iterate through list and free each node.
    */
    ListNode *current = list->head;
    while (current)
    {
        ListNode *next = current->next; // store pointer to next node
        list_node_destroy(current);     // free current node
        current = next;                 // move to next node
    }
    free(list); // free the memory allocated for the list
}

bool list_push(List *list, int data)
{
    ListNode *node = list_node_create(data); // create a new node

    if (!node)
    {
        return false; // return false if memory allocation fails
    }

    // Push node to front (new head and old head is the new head's next)
    node->next = list->head; // new node points to current head
    list->head = node;       // update head to new node
    return true;             // successful push
}

bool list_remove(List *list, int data)
{
    ListNode *current = list->head;
    ListNode *prev = NULL;

    // Traverse list until we find the node to remove/the end
    while (current)
    {
        if (current->data == data)
        {
            /*
                Time to remove the node:
                Case 1: Removing the head node
                Case 2: Removing a non-head node
            */
            if (prev)
            {                               // case 2
                prev->next = current->next; // link prev to next node (cut out the current)
            }
            else
            {                               // case 1
                list->head = current->next; // new head is current (head)'s next
            }
            list_node_destroy(current); // free memory of removed node
            return true;                // successful removal
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    // Value was never found in the list
    return false;
}