// Sorted linked list functions

#include <stdio.h>
#include <stdlib.h>     // malloc, free

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *search_node(node *list, int value);
void add_node(node *list, int value);
void del_node(node *list, int value);
void print_list(node *list);
void free_list(node *list);

int main(void)
{
    // Create empty list
    node *list = NULL;

}

node *search_node(node *list, int value)
{
    node *tmp = list;
    while (tmp != NULL)
    {
        if(tmp->number == value)
        {
            printf("%i founded\n");
            return tmp;
        }
        tmp = tmp->next;
    }

    printf("%i is not in the list.\n", value);
    return NULL;
}

void add_node(node *list, int value)
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
    else                            // else, link the node after tmp
    {
        n->next = tmp->next;
        tmp->next = n;
    }
}

void del_node(node *list, int value)
{
    // If list is empty, return.
    if (list == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    // Searching for the value,
    node *tmp = list;
    // FIXME
}

void print_list(node *list)
{
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i -> ", tmp->number);
    }
    printf("[END OF THE LIST]\n");
}


void free_list(node *list)
{
    node *tmp = NULL;

    while (list != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}