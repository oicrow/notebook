// precaution: NULL is pointer to nowhere (0x0, or hexadecimal 0)
//           : NUL is character '\0', represented with binary 0

// + linked list can resize list so easily
//     -> insert: O(n)
// - but since you always need to access from the root node along the list, only linear search is available
//     -> search: O(n)
// - also, you need to sacrifice more memory to store the pointer to the next node


#include <stdio.h>
#include <stdlib.h>     // malloc, free

typedef struct node     // <--
{                       //   | two 'node's must be
    int number;         //   | synchronized
    struct node *next;  // <--
}
node;                   // <-- 'node' here doens't have to be same, but conventionally it is

int main(void)
{
    // Create empty list
    node *list = NULL;

    // Make 1st node and store value
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    (*n).number = 2;    // same as: n->number = 2;
    n->next = NULL;
    // Link it to the list
    list = n;

    // Make 2nd node and store value
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 4;
    n->next = NULL;
    // Link it to the list
    list->next = n;

    // Make 3rd node and store value
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 4;
    n->next = NULL;
    // Link it to the list
    list->next->next = n;


    // print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }


    // free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}