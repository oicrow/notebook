// Sorted linked list functions
#include <stdio.h>
#include <stdlib.h>     // malloc, free

typedef struct node
{
    int number;
    struct node *next;
}
node;

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


    // Let tmp point at the last node
    node *tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // ... and link the new node to the last node of the list (tmp)
    tmp->next = n;



    // Insert the new node to the first of the list
    n->next = list;
    list = n;


    // Insert the new node to the middle of the list
    tmp = list;
    int i = 0
    while (tmp->number < n->number)
    {
        tmp = tmp->next;
        i++;
    }
    n->next = tmp;
    tmp = list;
    for(int j = 0; j < i - 1; j++)
    {
        tmp = tmp->next;
    }
    tmp->next = n;

}

void add(node *list, int value)
{
    // Create a new node with number value and next NULL
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Add failed\n");
        return;
    }
    n->number = value;
    n->next = NULL;

    // If list is empty, add to 1st
    if (list == NULL)
    {
        list = n;
        return;
    }

    // Let tmp point at the node right before where new node will be (except for inserting at the first)
    node *tmp = list;
    while (tmp->next->number < n->number)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
            break;
        }
    }

    // Link the node to the list
    if (tmp->number > n->number)    // if new node should be the first
    {
        n->next = tmp;
        list = n;
    }
    else                            // else, linkt the node after tmp
    {
        
    }
}