#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/list.h"

/*
    $ gcc lib/singly_linked/src/list.c lib/singly_linked/src/list_node.c lib/singly_linked/test/main.c -Ilib/singly_linked/include -o singly_linked_test

    $ valgrind --leak-check=full ./singly_linked_test

    valgrind              // run program inside Valgrind
    --leak-check=full     // show detailed leak information
    ./singly_linked_test  // the executable to run


    Valgrind is a runtime memory checker.
    Runs and reports:
    - memory leaks
    - double frees
    - use-after-free
    - invalid reads/writes
    - forgotten free() calls
*/

int main(void)
{
    List *list = list_create();
    assert(list != NULL);

    list_push(list, 1);
    list_push(list, 2);
    list_push(list, 3);

    list_remove(list, 2);

    list_destroy(list);
    return 0;
}
