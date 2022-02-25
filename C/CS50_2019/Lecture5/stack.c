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

void push_array(char **arr, char *string);
char *pop_array(char **arr);
void print_array(char **arr);
void clear_array(char **arr);
void push_linked(node **list, char *string);
char *pop_linked(node **list);
void print_linked(node *list);
void clear_linked(node **list);

int main(void)
{
    // Stack in array

    // Initialize array of pointer to char (string)
    char *array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = NULL;
    }

    push_array(array, "cookie");                // cookie
    push_array(array, "choloate");              // cookie, chocolate
    push_array(array, "lemon");                 // cookie, chocolate, lemon
    push_array(array, "cheese");                // cookie, chocolate, lemon, cheese
    push_array(array, "butter");                // cookie, chocolate, lemon, cheese, butter  
    push_array(array, "macadamia");             // cookie, chocolate, lemon, cheese, butter, macadamia
    push_array(array, "matcha");                // cookie, chocolate, lemon, cheese, butter, macadamia, matcha
    push_array(array, "almonde");               // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde
    push_array(array, "earl grey");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    push_array(array, "peanut");                // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut
    push_array(array, "coconut");               // Stack is already full.

    print_array(array);                         // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut

    char *tmp = pop_array(array);               // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    printf("I need %s.\n", tmp);                // I need peanut.

    print_array(array);                         // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey

    push_array(array, "coconut");               // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, coconut
    
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter, macadamia, matcha
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter, macadamia
    
    print_array(array);                         // cookie, chocolate, lemon, cheese, butter, macadamia
    
    push_array(array, "blueberry");             // cookie, chocolate, lemon, cheese, butter, macadamia, blueberry
    
    print_array(array);                         // cookie, chocolate, lemon, cheese, butter, macadamia, blueberry
    
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter, macadamia
    pop_array(array);                           // cookie, chocolate, lemon, cheese, butter
    pop_array(array);                           // cookie, chocolate, lemon, cheese
    
    print_array(array);                         // cookie, chocolate, lemon, cheese
   
    pop_array(array);                           // cookie, chocolate, lemon
    pop_array(array);                           // cookie, chocolate
    pop_array(array);                           // cookie
    
    print_array(array);                         // cookie
    
    pop_array(array);                           // 
    
    print_array(array);                         //

    pop_array(array);                           // Stack is already empty.
    
    push_array(array, "cookie");                // cookie
    push_array(array, "choloate");              // cookie, chocolate
    push_array(array, "lemon");                 // cookie, chocolate, lemon
    push_array(array, "cheese");                // cookie, chocolate, lemon, cheese
    push_array(array, "butter");                // cookie, chocolate, lemon, cheese, butter  
    push_array(array, "macadamia");             // cookie, chocolate, lemon, cheese, butter, macadamia
    push_array(array, "matcha");                // cookie, chocolate, lemon, cheese, butter, macadamia, matcha
    push_array(array, "almonde");               // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde
    push_array(array, "earl grey");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    push_array(array, "peanut");                // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut

    clear_array(array);                         //

    print_array(array);                         //

    pop_array(array);                           // Stack is already empty.

    push_array(array, "cookie");                // cookie
    
    clear_array(array);                         //


    // Stack in linked list

    // Initialize linked list
    node *head = NULL;

    print_linked(head);                         //

    push_linked(&head, "cookie");               // cookie

    print_linked(head);                         // cookie

    push_linked(&head, "chocolate");            // cookie, chocolate
    push_linked(&head, "lemon");                // cookie, chocolate, lemon
    push_linked(&head, "cheese");               // cookie, chocolate, lemon, cheese
    push_linked(&head, "butter");               // cookie, chocolate, lemon, cheese, butter
    push_linked(&head, "matcha");               // cookie, chocolate, lemon, cheese, butter, matcha
    push_linked(&head, "earl grey");            // cookie, chocolate, lemon, cheese, butter, matcha, earl grey
    push_linked(&head, "peanut");               // cookie, chocolate, lemon, cheese, butter, matcha, earl grey, peanut

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter, matcha, earl grey, peanut

    tmp = pop_linked(&head);                    // cookie, chocolate, lemon, cheese, butter, matcha, earl grey
    printf("I need %s.\n", tmp);                // I need peanut.

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter, matcha, earl grey

    push_linked(&head, "macadamia");            // cookie, chocolate, lemon, cheese, butter, matcha, earl grey, macadamia

    tmp = pop_linked(&head);                    // cookie, chocolate, lemon, cheese, butter, matcha, earl grey
    printf("I need %s cookie.\n", tmp);         // I need macadamia cookie.

    tmp = pop_linked(&head);                    // cookie, chocolate, lemon, cheese, butter, matcha
    printf("I need %s cookie.\n", tmp);         // I need earl grey cookie.

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter, matcha

    pop_linked(&head);                          // cookie, chocolate, lemon, cheese, butter
    pop_linked(&head);                          // cookie, chocolate, lemon, cheese
    pop_linked(&head);                          // cookie, chocolate, lemon
    pop_linked(&head);                          // cookie, chocolate
    pop_linked(&head);                          // cookie

    print_linked(head);                         // cookie

    pop_linked(&head);                          //

    print_linked(head);                         //

    pop_linked(&head);                          // Stack is already empty.

    print_linked(head);                         //

    clear_linked(&head);                        //

    print_linked(head);                         //
    
    push_linked(&head, "cookie");               // cookie
    
    print_linked(head);                         // cookie

    clear_linked(&head);                        // 

    push_linked(&head, "cookie");               // cookie    
    push_linked(&head, "choloate");             // cookie, chocolate
    push_linked(&head, "lemon");                // cookie, chocolate, lemon
    push_linked(&head, "cheese");               // cookie, chocolate, lemon, cheese
    push_linked(&head, "butter");               // cookie, chocolate, lemon, cheese, butter

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter

    clear_linked(&head);                        //

    push_linked(&head, "cookie");               // cookie    
    push_linked(&head, "choloate");             // cookie, chocolate
    push_linked(&head, "lemon");                // cookie, chocolate, lemon
    push_linked(&head, "cheese");               // cookie, chocolate, lemon, cheese
    push_linked(&head, "butter");               // cookie, chocolate, lemon, cheese, butter

    pop_linked(&head);                          // cookie, chocolate, lemon, cheese

    clear_linked(&head);                        //

    pop_linked(&head);                          // Stack is already empty.

    print_linked(head);                         //
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
    
    // If i is 0, the stack is already empty so return
    if (i == 0)
    {
        printf("Stack is already empty.\n");
        return NULL;
    }

    // Move i to the index of last unempty element of stack
    i--;

    // Remember last element
    char *string = arr[i];

    // Initialize last element to NULL
    arr[i] = NULL;

    // Prompt user that pop successed
    printf("Successfully poped \"%s\".\n", string);

    // Return last element
    return string;
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

// Function to push string to linked list
// (same with queue)
void push_linked(node **list, char *string)
{
    // Create a new node with string and next NULL
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Push failed: cannot execute malloc\n");
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

    // Prompt user that push successed
    printf("Successfully pushed \"%s\".\n", string);

    return;
}

// Function to pop string from linked list
//  : return the last element of linked list (poped string)
char *pop_linked(node **list)
{
    // If list is empty, print message and return
    if ((*list) == NULL)
    {
        printf("Stack is already empty.\n");
        return NULL;
    }

    // Declare variables to store last node and last element
    node *tmp;
    char *string;

    // If list has only one node, 
    if ((*list)->next == NULL)
    {
        // Remember last node
        tmp = *list;

        // Remember last element
        string = tmp->string;

        // Unlink last node from list
        (*list) = NULL;
    }
    // Else (if list has two or more nodes)
    else
    {
        // Move tmp to the last node, prev to the the node before tmp
        tmp = *list;
        node *prev = *list;
        int i = 0;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            if (i != 0)
            {
                prev = prev->next;
            }
            i++;
        }

        // Remember last element
        string = tmp->string;

        // Unlink last node from list
        prev->next = NULL;
    }

    // Free last node
    free(tmp);
    
    // Prompt user that pop successed
    printf("Successfully poped \"%s\".\n", string);

    // Return last element
    return string;
}

// Function to print all elements in linked list
// (same with queue)
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
    printf("--- End of stack ---\n");
    printf("%i element(s) in stack\n", i);

    return;
}

// Function to clear and free all elements in linked list
// (same with queue)
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