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
void push_array(char **arr, char *string)
{

}

// Fucntion to pop string from array
//  : return the last element of array (poped string)
char *pop_array(char **arr)
{

}

// Function to print all elements in array
void print_array(char **arr)
{

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