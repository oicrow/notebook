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
void free_list(node *list);
void free_tree(node *hash_table[]);

int main (void)
{
    node *hash_table[26];

    for (int i = 0; i < 26; i++)
    {
        hash_table[i] = NULL;
    }

    add_hash_table(hash_table, "Albus");
    add_hash_table(hash_table, "Zacharias");
    add_hash_table(hash_table, "Hermione");
    add_hash_table(hash_table, "Ginny");
    add_hash_table(hash_table, "Ron");
    add_hash_table(hash_table, "Fred");
    add_hash_table(hash_table, "Severus");
    add_hash_table(hash_table, "Petunia");
    add_hash_table(hash_table, "Draco");
    add_hash_table(hash_table, "James");
    add_hash_table(hash_table, "Harry");
    add_hash_table(hash_table, "Hagrid");
    add_hash_table(hash_table, "Sirius");
    add_hash_table(hash_table, "Remus");
    add_hash_table(hash_table, "George");
    add_hash_table(hash_table, "Lily");
    add_hash_table(hash_table, "Lucius");

    free_tree(hash_table);
}

int hash_function(char *name)
{
    int first_letter_int = name[0];
    if (first_letter_int >= 97 && first_letter_int <= 122)
    {
        first_letter_int -= 32;
    }
    return first_letter_int - 65;
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
    int index = hash_function(name);
    node *list = hash_table[index];

    // Link it to the hash table
    if (list == NULL)   // if list is empty,
    {
        hash_table[index] = n;       // add to the first
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
        hash_table[index] = n;
    }
    else                    // else, link the node after tmp
    {
        n->next = tmp->next;
        tmp->next = n;
    }

    return;
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

void free_tree(node *hash_table[])
{
    for (int i = 0; i < 26; i++)
    {
        free_list(hash_table[i]);
    }

    return;
}