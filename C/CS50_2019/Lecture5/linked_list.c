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

    add_node(list, 2);
    add_node(list, 2);
    add_node(list, 5);
    add_node(list, 5);
    add_node(list, 5);
    add_node(list, 7);
    add_node(list, 8);
    add_node(list, 8);

    print_list(list);

    del_node(list, 2);
    del_node(list, 2);
    del_node(list, 4);
    del_node(list, 5);
    del_node(list, 5);
    del_node(list, 8);
    del_node(list, 8);

    print_list(list);

    free_list(list);
    printf(list);
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

    // If value is greater than the first node,
    if(list->number < value)
    {
        // tmp points at the node right before the value
        node *tmp = list;
        while (tmp->next->number < value)
        {
            tmp = tmp->next;
            if(tmp->next == NULL)
            {
                printf("%i is not in the list.\n", value);
                return;
            }
        }
        
        // node next to tmp must be equal to value if it exists
        // so if it's not equal, the value is not in the list
        if (tmp->next->number != value)
        {
            printf("%i is not in the list.\n", value);
            return;
        }

        // else, delete the node after tmp (= value)
        node *n = tmp->next;
        tmp->next = n->next;
        free(n);
    }
    // If value is the first node, delete the first node.
    else if(list->number == value)
    {
        node *n = list;
        list = n->next;
        free(n);
    }
    // If value is less than the first node, return.
    else
    {
        prtinf("%i is not in the list.\n", value);
        return;
    }

    return;
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