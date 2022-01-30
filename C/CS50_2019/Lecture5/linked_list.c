// Sorted linked list functions

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>     // malloc, free

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *search_node(node *list, int value);
void print_list(node *list);
void free_list(node **list_ptr);
void add_node(node **list_ptr, int value);
void del_node(node **list_ptr, int value);

int main(void)
{
    int mode = 1, input_num;   // mode number, input number to add/delete/search
    node *list = NULL;  // empty list
    
    while (mode != 0)
    {
        printf("---------------\n");
        printf("1 Add value\n");
        printf("2 Delete value\n");
        printf("3 Search value\n");
        printf("4 Print list\n");
        printf("0 Quit\n");
        printf("---------------\n");
        printf("Type the mode number: ");
        scanf("%d", &mode);

        while (mode < 0 || mode > 4)
        {
            printf("Invalid mode number.\n");
            printf("Type the mode number: ");
            scanf("%d", &mode);
        }

        switch (mode){
            case 1: // Add value
                printf("Integer to add: ");
                scanf("%d", &input_num);
                add_node(&list, input_num);
                print_list(list);
                break;
            
            case 2: // Delete value
                printf("Integer to delete: ");
                scanf("%d", &input_num);
                del_node(&list, input_num);
                print_list(list);
                break;
            
            case 3: // Search value
                printf("Integer to search: ");
                scanf("%d", &input_num);
                search_node(list, input_num);
                break;
            
            case 4: // Print list
                print_list(list);
                break;
            
            case 0: // Quit
                break;
            
            default:
                printf("Error: Invalid mode number.\n");
        }
    }

    free_list(&list);
    printf("Quit program.\n");
}

node *search_node(node *list, int value)
{
    node *tmp = list;
    int i = 1;
    
    while (tmp != NULL)
    {
        if(tmp->number == value)
        {
            printf("  %i founded in the %i'th node.\n", value, i);
            return tmp;
        }
        tmp = tmp->next;
        i++;
    }

    printf("  %i is not in the list.\n", value);
    return NULL;
}

void print_list(node *list)
{
    printf("\n\t");
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i -> ", tmp->number);
    }
    printf("[END OF THE LIST]\n\n");
}

void free_list(node **list_ptr)
{
    node *list = *list_ptr;
    node *tmp = NULL;

    while (list != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

void add_node(node **list_ptr, int value)
{
    node *list = *list_ptr;

    // Create a new node with number value and next NULL
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Add failed.\n");
        return;
    }
    n->number = value;
    n->next = NULL;

    // If list is empty, add to 1st
    if (list == NULL)
    {
        *list_ptr = n;
        printf("Added %i.\n", value);
        return;
    }

    // Let tmp point at the node right before where new node will be
    // (except for inserting at the first)
    node *tmp = list;
    while (tmp->next != NULL && tmp->next->number < n->number)
    {
        tmp = tmp->next;
    }

    // Link the node to the list
    if (tmp->number > n->number)    // if new node should be the first
    {
        n->next = tmp;
        *list_ptr = n;
    }
    else                            // else, link the node after tmp
    {
        n->next = tmp->next;
        tmp->next = n;
    }

    printf("Added %i.\n", value);
    return;
}

void del_node(node **list_ptr, int value)
{
    node *list = *list_ptr;

    // If list is empty, return.
    if (list == NULL)
    {
        printf("List is already empty.\n");
        return;
    }

    // If value is greater than the first node,
    if(list->number < value)
    {
        // tmp points at the node right before the value
        node *tmp = list;
        while (tmp->next != NULL && tmp->next->number < value)
        {
            tmp = tmp->next;
        }
        
        // node next to tmp must be equal to value if it exists
        // so if it's not equal or tmp is the last node, the value is not in the list
        if (tmp->next == NULL || tmp->next->number != value)
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
        *list_ptr = n->next;
        free(n);
    }
    // If value is less than the first node, return.
    else
    {
        printf("%i is not in the list.\n", value);
        return;
    }

    printf("Deleted %i.\n", value);
    return;
}