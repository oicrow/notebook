// Dictionary
//  : data structure that has keys and values (anything that maps one to another)
//  : using hash table, hash functions
//  : also available in python

//        Wed 
//      ↙   ↘
//    Mon     Fri
//   ↙↘     ↙↘
//  Sun Tue Thu Sat

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <ctype.h>  // tolower

typedef struct Entry
{
    int key;        // Day (Sunday, ... , Saturday)
    char *value;    // Todo on that day

    struct Entry *left; 
    struct Entry *right;
} Entry;

int hash_key(char *string);


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
    tmp->key = 4;
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
    tmp->key = 2;
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
    tmp->key = 1;
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
    tmp->key = 3;
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
    tmp->key = 6;
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
    tmp->key = 5;
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
    tmp->key = 7;
    tmp->value = "Clean house";
    tmp->left = NULL;
    tmp->right = NULL;
    dictionary->right->right = tmp;


    // free dictionary
    free(dictionary->right->right);
    free(dictionary->right->left);
    free(dictionary->right);
    free(dictionary->left->right);
    free(dictionary->left->left);
    free(dictionary->left);
    free(dictionary);

    return 0;
}

// Function to find hash value of the string
//  : return - corresponding hash value, if any
//           - -1, otherwise
//  : using one or two first letter(s)
int hash_key(char *string)
{
    // Ensure string is not emtpy
    if (string == NULL)
    {
        printf("Failed to find hash value: Invalid string\n");
        return -1;
    }

    // Convert string to all small letters
    string = tolower(string);

    // Return hash value according to string
    // If there's none, return -1
    if (string[0] == 's')
    {
        if (string[1] == 'u')
        {
            return 1;   // Sunday
        }
        else if (string[1] == 'a')
        {
            return 7;   // Saturday
        }
        else
        {
            printf("Failed to find hash value: Invalid string\n");
            return -1;
        }
    }
    else if (string[0] == 't')
    {
        if (string[1] == 'u')
        {
            return 3;   // Tuesday
        }
        else if (string[1] == 'h')
        {
            return 5;   // Thursday
        }
        else
        {
            printf("Failed to find hash value: Invalid string\n");
            return -1;
        }
    }
    else if (string[0] == 'm')
    {
        return 2;       // Monday
    }
    else if (string[0] == 'w')
    {
        return 4;       // Wednesday
    }
    else if (string[0] == 'f')
    {
        return 6;       // Friday
    }
    else
    {
        printf("Failed to find hash value: Invalid string\n");
        return -1;
    }
}

// Function to get value corresponding to the key
//  : return - pointer to char as a string that corresponds to key in given dictionary
//           - NULL, otherwise
char *get_dict(Entry *dict, char *key)
{
    // Find hash value of input key
    int hash = hash_key(key);

    // Ensure key has valid hash value
    if (hash < 1 || hash > 7)
    {
        printf("Failed to get value: Invalid key\n");
        return NULL;
    }

    // Find entry with key hash (binary search)
    // If found, print message and return value
    // If not found, print message and return NULL
    Entry *tmp = dict;
    char *value = NULL;
    while (tmp != NULL)
    {
        if (hash == tmp->key)
        {
            value = tmp->key;
            printf("Value of key \"%s\" is \"%s\".", key, value);
            return value;
        }
        else if (hash > tmp->key)
        {
            tmp = tmp->right;
        }
        else if (hash < tmp->key)
        {
            tmp = tmp->left;
        }
        else
        {
            printf("Value of key \"%s\" doesn't exist.\n", key);
            return NULL;
        }
    }

    // If not found, print message and return NULL
    printf("Value of key \"%s\" doesn't exist.\n", key);
    return NULL;
}

void search_dict(Entry *dict, char *value)
{

}