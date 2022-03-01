// Dictionary
//  : data structure that has keys and values (anything that maps one to another)
//  : using hash table, hash functions
//  : also available in python

//        Wed 
//       ↙  ↘
//    Mon     Fri
//   ↙↘     ↙↘
//  Sun Tue Thu Sat

#include <stdio.h>
#include <stdlib.h> // malloc, free???

typedef struct Entry
{
    char *key;      // Day (Sunday, ... , Saturday)
    char *value;    // Todo on that day

    struct Entry *left; 
    struct Entry *right;
} Entry;


int main(void)
{
    // Creating a Dictionary
    Entry *dictionary = NULL;

    // Entry Wednesday
    Entry *tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        return -1;
    }
    tmp->key = "Wednesday";
    tmp->value = "Buy groceries";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary = tmp;

    // Entry Monday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary);
        return -1;
    }
    tmp->key = "Monday";
    tmp->value = "Watch movie";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->left = tmp;

    // Entry Sunday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary->left);
        free(dictionary);
        return -1;
    }
    tmp->key = "Sunday";
    tmp->value = "Read books";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->left->left = tmp;

    // Entry Tuesday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary->left->left);
        free(dictionary->left);
        free(dictionary);
        return -1;
    }
    tmp->key = "Tuesday";
    tmp->value = "Make cookies";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->left->right = tmp;

    // Entry Friday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary->left->right);
        free(dictionary->left->left);
        free(dictionary->left);
        free(dictionary);
        return -1;
    }
    tmp->key = "Friday";
    tmp->value = "Meet up with friends";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->right = tmp;

    // Entry Thursday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary->right);
        free(dictionary->left->right);
        free(dictionary->left->left);
        free(dictionary->left);
        free(dictionary);
        return -1;
    }
    tmp->key = "Thursday";
    tmp->value = "Fix door";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->right->left = tmp;

    // Entry Saturday
    tmp = malloc(sizeof(Entry));
    if (tmp == NULL)
    {
        free(dictionary->right->left);
        free(dictionary->right);
        free(dictionary->left->right);
        free(dictionary->left->left);
        free(dictionary->left);
        free(dictionary);
        return -1;
    }
    tmp->key = "Saturday";
    tmp->value = "Clean house";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->right->right = tmp;
}


void find_dict(Entry *dict, char *key)
{

}

void search_dict(Entry *dict, char *value)
{

}