// Queue
//  : FIFO - First In, First Out
//  : enqueue - get in the queue
//  : dequeue - get out of the queue

#include <stdio.h>
#include <stdlib.h> // malloc, free

// Node of linked list
typedef struct node
{
    char *
    struct node *next;
}
node;

void enqueue_array(char **arr, char *string);
char *dequeue_array(char **arr);
void print_array(char **arr);

int main(void)
{
    // Queue in array
    
    // Initialize array of pointer to char (string)
    char *array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = NULL;
    }


    // Queue in linked list

    // Initialize linked 
}

void enqueue_array(char **arr, char *string)
{
    // Move i to index of the last unempty element of array
    for (int i = 0; i < 10; i++)
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

char *dequeue_array(char **arr)
{
    // Remember first element
    char *tmp = arr[0];

    // Move each element one step forward
    for (int i = 0; i < 9; i++)
    {
        arr[i] = arr[i + 1];
    }

    // Initialize last node to NULL
    arr[i] = NULL;

    // Prompt user that dequeue successed
    printf("Successfully dequeued \"%s\".\n", tmp);

    // Return first element 
    return tmp;
}

void print_array(char **arr)
{
    for (int i = 0; i < 10; i++)
    {
        // If there's no element backward, print message and return
        if (arr[i] == NULL)
        {
            printf("End of queue.\n");
            printf("%i elements in queue / %i slots available\n", i, 10 - i);
            return;
        }
        // Else print i'th element
        printf("#%i: %s\n", i, arr[i]);
    }
}

void enqueue_linked()