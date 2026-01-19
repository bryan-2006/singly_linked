#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
    To run:

        $ gcc -Wall -Wextra -Werror -fsanitize=address -g \
            main.c list.c node.c -o singly_linked_test

        $ ./singly_linked_test
*/

/*
    Interactive test program for List

    Commands:
    - push <int>: Adds a new node with the given integer data to the front of the list
    - remove <int>: Removes the first node with the given integer data from the list
    - print: Prints the current contents of the list
    - exit: Exits the program

    Memory ownership:
    - main() owns the List
    - List owns the Nodes
    - Nodes own their data (integers in this case)
    - main() does not directly touch Node pointers
*/
int main(void)
{
    List *list = list_create(); // Create a new list
    if (!list)
    {
        fprintf(stderr, "Failed to create list\n");
        return 1;
    }

    char input[16]; // stack buffer for user input (no heap allocation)
    /*
        ^ buffer size is fixed; large enough for simple commands
        and is freed when main() exits.

        Stack allocation is faster and simpler than heap allocation (but limited size).

        Ownership of stack is automatic (compiler managed) unlike manual heap management.
    */

    printf("Singly Linked List Interactive Test\n");
    printf("Commands: push <int>, remove <int>, print, exit\n");

    while (1)
    {
        printf("> ");

        // Read a full line from stdin
        if (!fgets(input, sizeof(input), stdin))
        {
            // EOF or error -> exit loop safely
            break;
        }

        input[strcspn(input, "\n")] = 0; // Remove newline character if present

        int data;

        if (sscanf(input, "push %d", &data) == 1)
        {
            if (!list_push(list, data))
            {
                fprintf(stderr, "Allocation failed\n");
            }
        }
        else if (sscanf(input, "remove %d", &data) == 1)
        {
            if (!list_remove(list, data))
            {
                printf("Value not found\n");
            }
        }
        else if (strcmp(input, "print") == 0)
        {
            Node *current = list->head;
            // printf("List contents: ");
            while (current)
            {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }
        else if (strcmp(input, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Unknown command\n");
        }
    }

    list_destroy(list); // Free the list and its nodes
    // ^ we could have done it in the if clause for exit, but this is cleaner
}