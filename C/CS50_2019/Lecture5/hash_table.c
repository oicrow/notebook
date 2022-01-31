// Hash table
//  : a combination of an array and linked lists inside of it
//  : search is technically O(n), but actually takes much faster than that on average 

// Hash function
//  : a function that converts the value to index of a hash table
//  : better if the function generates unique index for each input

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strcmp

typedef struct node
{
    char *name;
    struct node *next;
} node;

int hash_function(char *name);
void add_hash_table(node *hash_table[], char *name);

int main (void)
{
    node *hash_table[26];

}

int hash_function(char *name)
{
    int first_letter_int = name[0];
    if (first_letter_int >= 97 && first_letter_int <= 122)
    {
        first_letter_int -= 32;
    }
    return first_letter_int;
}

void add_hash_table(node *hash_table[], char *name)
{
    // Create the node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Add failed.\n");
        return;
    }
    n->name = name;
    n->next = NULL;

    // Find the hash
    node *list = hash_table[hash_function(name)];

    // Link it to the hash table
    if (list == NULL)   // if list is empty,
    {
        list = n;       // add to the first
        return;
    }

    node *tmp = list;
    while (tmp->next != NULL && strcmp(n->name, tmp->next->name) > 0)
    {
        tmp = tmp->next;
    }   // tmp -> the node right before where new node will be (except for the first)

    if (tmp->name > n->name) // if new node should be the first,
    {
        n->next = tmp;       // link at the first
        list = n;
    }
    else                    // else, link the node after tmp
    {
        n->next = tmp->next;
        tmp->next = n;
    }

    return;
}
