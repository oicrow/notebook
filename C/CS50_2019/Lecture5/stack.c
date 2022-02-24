// Stack
//  : LIFO - Last In, First Out
//  : push - pushing an element onto the stack
//  : pop - removing the top element

#include <stdio.h>
#include <stdlib.h> // malloc, free

// Node of linked list
typedef struct node
{
    char *string;
    struct node *next;
}
node;

int main(void)
{
    // Stack in array

    // Initialize array of pointer to char (string)
    char *array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = NULL;
    }

    // Stack in linked list

    // Initialize linked list
    node *head = NULL;
}

// Function to push string into array
// (sane with queue)
void push_array(char **arr, char *string)
{
    // Move i to index of the first empty element of stack
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == NULL)
        {
            break;
        }
    }

    // If arr[i] is not empty, the stack is already full so return
    if (arr[i] != NULL)
    {
        printf("Stack is already full.\n");
        return;
    }

    // Add string to the stack
    arr[i] = string;

    // Prompt user that push successed
    printf("Successfully pushed \"%s\".\n", string);
    
    return;
}

// Fucntion to pop string from array
//  : return the last element of array (poped string)
char *pop_array(char **arr)
{
    // Move i to index of the first empty element of stack
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == NULL)
        {
            break;
        }
    }
    
    // If arr[i] is not empty, the stack is already empty so return
    if (arr[i] =! NULL)
    {
        printf("Stack is already empty.\n");
        return;
    }

    // 
}

// Function to print all elements in array
// (same with queue)
void print_array(char **arr)
{
    // Repeat for every element in array
    int i;
    for (i = 0; i < 10; i++)
    {
        // If there's no element backward, get out of loop
        if (arr[i] == NULL)
        {
            break;
        }
        // Else print i'th element
        printf("#%i: %s\n", i, arr[i]);
    }

    // Print message and return
    printf("--- End of stack ---\n");
    printf("%i element(s) in stack / %i slot(s) available\n", i, 10 - i);
    return;
}

// Function to clear all elements in array
// (same with queue)
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