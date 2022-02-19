// Queue
//  : FIFO - First In, First Out
//  : enqueue - get in the queue
//  : dequeue - get out of the queue

#include <stdio.h>
#include <stdlib.h> // malloc, free

// Node of linked list
typedef struct node
{
    char *string;
    struct node *next;
}
node;

void enqueue_array(char **arr, char *string);
char *dequeue_array(char **arr);
void print_array(char **arr);
void clear_array(char **arr);
void enqueue_linked(node **list, char *string);
char *dequeue_linked(node **list);
void print_linked(node *list);
void clear_linked(node **list);

int main(void)
{
    // Queue in array
    
    // Initialize array of pointer to char (string)
    char *array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = NULL;
    }

    enqueue_array(array, "cookie");
    enqueue_array(array, "butter cookie");


    // Queue in linked list

    // Initialize linked list
    node *head = NULL;
}

// Function to enqueue string to array
void enqueue_array(char **arr, char *string)
{
    // Move i to index of the last unempty element of array
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == NULL)
        {
            break;
        }
    }

    // If arr[i] is not empty, the queue is already full so return
    if (arr[i] != NULL)
    {
        printf("Queue is already full.\n");
        return;
    }

    // Add string to the queue
    arr[i] = string;

    // Prompt user that enqueue successed
    printf("Successfully enqueued \"%s\".\n", string);
    
    return;
}

// Function to dequeue string from array
//  : return the first element of array (dequeued string)
char *dequeue_array(char **arr)
{
    // Remember first element
    char *string = arr[0];

    // Move each element one step forward
    int i;
    for (i = 0; i < 9; i++)
    {
        arr[i] = arr[i + 1];
    }

    // Initialize last node to NULL
    arr[i] = NULL;

    // Prompt user that dequeue successed
    printf("Successfully dequeued \"%s\".\n", string);

    // Return first element 
    return string;
}

// Function to print all elements in array
void print_array(char **arr)
{
    // Repeat for every element in array
    for (int i = 0; i < 10; i++)
    {
        // If there's no element backward, print message and return
        if (arr[i] == NULL)
        {
            printf("End of queue.\n");
            printf("%i element(s) in queue / %i slot(s) available\n", i, 10 - i);
            return;
        }
        // Else print i'th element
        printf("#%i: %s\n", i, arr[i]);
    }
}

// Function to clear all elements in array
void clear_array(char **arr)
{
    // Repeat for every element in array
    for (int i = 0; i < 10; i++)
    {
        // If there's no element backward, return
        if (arr[i] == NULL)
        {
            return;
        }
        // Else delete value of element and initialize it to NULL
        arr[i] = NULL;
    }
}

// Function to enqueue string to linked list
void enqueue_linked(node **list, char *string)
{
    // Create a new node with string and next NULL
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Enqueue failed: cannot execute malloc\n");
        return;
    }
    n->string = string;
    n->next = NULL;

    // If list is empty,
    if (*list == NULL)
    {
        // Add the node to the first
        *list = n;
    }
    // If list is not empty,
    else
    {
        // Go to the last node, and
        node *tmp = *list;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        // Link it after the last node
        tmp->next = n;
    }

    // Prompt user that enqueue successed
    printf("Successfully enqueued \"%s\".\n", string);

    return;
}

// Function to dequeue string from linked list
//  : return the first element of linked list (dequeued string)
char *dequeue_linked(node **list)
{
    // Remember first element
    char *string = (*list)->string;

    // Move head to second node
    node *tmp = *list;
    *list = (*list)->next;

    // Free first node
    free(tmp);

    // Prompt user that dequeue succeessed
    printf("Successfully dequeued \'%s\'\n", string);

    // Return first element
    return string;
}

// Function to print all elements in linked list
void print_linked(node *list)
{
    // Print each element until the end of queue
    int i = 0;
    while (list != NULL)
    {
        // Print element
        printf("#%i: %s\n", i, list->string);

        // Move to the next node
        list = list->next;

        // Move to the next index
        i++;
    }

    // Print message that notifies the end
    printf("End of queue.\n");
    printf("%i element(s) in queue\n", i);

    return;
}

// Function to clear and free all elements in linked list
void clear_linked(node **list)
{
    // tmp for temporarily store pointer to node
    node *tmp = NULL;

    // Repeat while list is not empty
    while ((*list) != NULL)
    {
        // Update tmp to list
        tmp = *list;
        // Update list to the next node
        *list = (*list)->next;

        // Delete tmp
        free(tmp);
    }
}