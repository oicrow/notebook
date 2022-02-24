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

    enqueue_array(array, "cookie");             // cookie
    enqueue_array(array, "choloate");           // cookie, chocolate
    enqueue_array(array, "lemon");              // cookie, chocolate, lemon
    enqueue_array(array, "cheese");             // cookie, chocolate, lemon, cheese
    enqueue_array(array, "butter");             // cookie, chocolate, lemon, cheese, butter  
    enqueue_array(array, "macadamia");          // cookie, chocolate, lemon, cheese, butter, macadamia
    enqueue_array(array, "matcha");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha
    enqueue_array(array, "almonde");            // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde
    enqueue_array(array, "earl grey");          // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    enqueue_array(array, "peanut");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut
    enqueue_array(array, "coconut");            // Queue is already full.

    print_array(array);                         // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut

    char *tmp = dequeue_array(array);           // chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut
    printf("I need %s.\n", tmp);                // I need cookie.

    print_array(array);                         // chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut

    enqueue_array(array, "coconut");            // chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut, coconut
    
    dequeue_array(array);                       // lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut, coconut
    dequeue_array(array);                       // cheese, butter, macadamia, matcha, almonde, earl grey, peanut, coconut
    dequeue_array(array);                       // butter, macadamia, matcha, almonde, earl grey, peanut, coconut
    dequeue_array(array);                       // macadamia, matcha, almonde, earl grey, peanut, coconut
    
    print_array(array);                         // macadamia, matcha, almonde, earl grey, peanut, coconut
    
    enqueue_array(array, "blueberry");          // macadamia, matcha, almonde, earl grey, peanut, coconut, blueberry
    
    print_array(array);                         // macadamia, matcha, almonde, earl grey, peanut, coconut, blueberry
    
    dequeue_array(array);                       // matcha, almonde, earl grey, peanut, coconut, blueberry
    dequeue_array(array);                       // almonde, earl grey, peanut, coconut, blueberry
    dequeue_array(array);                       // earl grey, peanut, coconut, blueberry
    
    print_array(array);                         // earl grey, peanut, coconut, blueberry
   
    dequeue_array(array);                       // peanut, coconut, blueberry
    dequeue_array(array);                       // coconut, blueberry
    dequeue_array(array);                       // blueberry
    
    print_array(array);                         // blueberry
    
    dequeue_array(array);                       // 
    
    print_array(array);                         //

    dequeue_array(array);                       // Queue is already empty.
    
    enqueue_array(array, "cookie");             // cookie
    enqueue_array(array, "choloate");           // cookie, chocolate
    enqueue_array(array, "lemon");              // cookie, chocolate, lemon
    enqueue_array(array, "cheese");             // cookie, chocolate, lemon, cheese
    enqueue_array(array, "butter");             // cookie, chocolate, lemon, cheese, butter  
    enqueue_array(array, "macadamia");          // cookie, chocolate, lemon, cheese, butter, macadamia
    enqueue_array(array, "matcha");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha
    enqueue_array(array, "almonde");            // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde
    enqueue_array(array, "earl grey");          // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey
    enqueue_array(array, "peanut");             // cookie, chocolate, lemon, cheese, butter, macadamia, matcha, almonde, earl grey, peanut

    clear_array(array);                         //

    print_array(array);                         //

    dequeue_array(array);                       // Queue is already empty.

    enqueue_array(array, "cookie");             // cookie
    
    clear_array(array);                         //


    // Queue in linked list

    // Initialize linked list
    node *head = NULL;

    print_linked(head);                         //

    enqueue_linked(&head, "cookie");            // cookie

    print_linked(head);                         // cookie

    enqueue_linked(&head, "chocolate");         // cookie, chocolate
    enqueue_linked(&head, "lemon");             // cookie, chocolate, lemon
    enqueue_linked(&head, "cheese");            // cookie, chocolate, lemon, cheese
    enqueue_linked(&head, "butter");            // cookie, chocolate, lemon, cheese, butter
    enqueue_linked(&head, "matcha");            // cookie, chocolate, lemon, cheese, butter, matcha
    enqueue_linked(&head, "earl grey");         // cookie, chocolate, lemon, cheese, butter, matcha, earl grey
    enqueue_linked(&head, "peanut");            // cookie, chocolate, lemon, cheese, butter, matcha, earl grey, peanut

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter, matcha, earl grey, peanut

    tmp = dequeue_linked(&head);                // chocolate, lemon, cheese, butter, matcha, earl grey, peanut
    printf("I need %s.\n", tmp);                // I need cookie.

    print_linked(head);                         // chocolate, lemon, cheese, butter, matcha, earl grey, peanut

    enqueue_linked(&head, "macadamia");         // chocolate, lemon, cheese, butter, matcha, earl grey, peanut, macadamia

    tmp = dequeue_linked(&head);                // lemon, cheese, butter, matcha, earl grey, peanut, macadamia
    printf("I need %s cookie.\n", tmp);         // I need chocolate cookie.

    tmp = dequeue_linked(&head);                // cheese, butter, matcha, earl grey, peanut, macadamia
    printf("I need %s cookie.\n", tmp);         // I need lemon cookie.

    print_linked(head);                         // cheese, butter, matcha, earl grey, peanut, macadamia

    dequeue_linked(&head);                      // butter, matcha, earl grey, peanut, macadamia
    dequeue_linked(&head);                      // matcha, earl grey, peanut, macadamia
    dequeue_linked(&head);                      // earl grey, peanut, macadamia
    dequeue_linked(&head);                      // peanut, macadamia
    dequeue_linked(&head);                      // macadamia
    
    print_linked(head);                         // macadamia

    dequeue_linked(&head);                      //

    print_linked(head);                         //

    dequeue_linked(&head);                      // Queue is already empty.

    print_linked(head);                         //

    clear_linked(&head);                        //

    print_linked(head);                         //
    
    enqueue_linked(&head, "cookie");            // cookie
    
    print_linked(head);                         // cookie

    clear_linked(&head);                        // 

    enqueue_linked(&head, "cookie");            // cookie    
    enqueue_linked(&head, "choloate");          // cookie, chocolate
    enqueue_linked(&head, "lemon");             // cookie, chocolate, lemon
    enqueue_linked(&head, "cheese");            // cookie, chocolate, lemon, cheese
    enqueue_linked(&head, "butter");            // cookie, chocolate, lemon, cheese, butter

    print_linked(head);                         // cookie, chocolate, lemon, cheese, butter

    clear_linked(&head);                        //

    enqueue_linked(&head, "cookie");            // cookie    
    enqueue_linked(&head, "choloate");          // cookie, chocolate
    enqueue_linked(&head, "lemon");             // cookie, chocolate, lemon
    enqueue_linked(&head, "cheese");            // cookie, chocolate, lemon, cheese
    enqueue_linked(&head, "butter");            // cookie, chocolate, lemon, cheese, butter

    dequeue_linked(&head);                      // chocolate, lemon, cheese, butter

    clear_linked(&head);                        //

    dequeue_linked(&head);                      // Queue is already empty.

    print_linked(head);                         //
}

// Function to enqueue string to array
// (same with stack)
void enqueue_array(char **arr, char *string)
{
    // Move i to index of the first empty element of queue
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
    // If arr is empty, print message and return
    if (arr[0] == NULL)
    {
        printf("Queue is already empty.\n");
        return NULL;
    }

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
// (same with stack)
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
    printf("--- End of queue ---\n");
    printf("%i element(s) in queue / %i slot(s) available\n", i, 10 - i);
    return;
}

// Function to clear all elements in array
// (same with stack)
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
    // If list is empty, print message and return
    if ((*list) == NULL)
    {
        printf("Queue is already empty.\n");
        return NULL;
    }

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
    printf("--- End of queue ---\n");
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