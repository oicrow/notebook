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
#include <string.h> // strcmp

typedef struct Entry
{
    int key;        // Day (Sunday, ... , Saturday)
    char *value;    // Todo on that day

    struct Entry *left; 
    struct Entry *right;
} Entry;

int hash_key(char *string);
char *get_dict(Entry *dict, char *key);
int search_dict(Entry *dict, char *value);

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

    // get Entries with key
    char *result = NULL;
    
    result = get_dict(dictionary, "Monday");
    printf("You need to %s today.\n", result);

    get_dict(dictionary, "Monday");
    get_dict(dictionary, "Tuesday");
    get_dict(dictionary, "weDnesday");
    get_dict(dictionary, "Thu");
    get_dict(dictionary, "Fri");
    get_dict(dictionary, "Sat.");
    get_dict(dictionary, "M");
    get_dict(dictionary, "cookie");
    get_dict(dictionary, "cheese");

    // search values
    int exists = -1;
    exists = search_dict(dictionary, "Buy groceries");  // is founded.
    exists = search_dict(dictionary, "Watch movie");    // is founded.
    search_dict(dictionary, "Meet up with friends");    // is founded.
    search_dict(dictionary, "Make cookies");            // is founded.
    search_dict(dictionary, "Buy cookies");             // is not in the dictionary.
    search_dict(dictionary, "Watch drama");             // is not in the dictionary.
    search_dict(dictionary, "Clean keyboard");          // is not in the dictionary.
    
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

    // Return hash value according to string
    // If there's none, return -1
    if (string[0] == 's' || string[0] == 'S')
    {
        if (string[1] == 'u' || string[1] == 'U')
        {
            return 1;   // Sunday
        }
        else if (string[1] == 'a' || string[1] == 'A')
        {
            return 7;   // Saturday
        }
        else
        {
            printf("Failed to find hash value: Invalid string\n");
            return -1;
        }
    }
    else if (string[0] == 't' || string[0] == 'T')
    {
        if (string[1] == 'u' || string[1] == 'U')
        {
            return 3;   // Tuesday
        }
        else if (string[1] == 'h' || string[1] == 'H')
        {
            return 5;   // Thursday
        }
        else
        {
            printf("Failed to find hash value: Invalid string\n");
            return -1;
        }
    }
    else if (string[0] == 'm' || string[0] == 'M')
    {
        return 2;       // Monday
    }
    else if (string[0] == 'w' || string[0] == 'W')
    {
        return 4;       // Wednesday
    }
    else if (string[0] == 'f' || string[0] == 'F')
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
            value = tmp->value;
            printf("Value of key \"%s\" is \"%s\".\n", key, value);
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

// Function to determine whether dictionary has entry including input value (string)
//  : return - 1, if it has
//           - 0, if it doensn't have
//           - -1, otherwise
int search_dict(Entry *dict, char *value)
{
    if (dict == NULL)
    {
        return 0;
    }
    else if (strcmp(dict->value, value) == 0)
    {
        printf("\"%s\" is founded.\n", value);
        return 1;
    }
    else if (search_dict(dict->right, value) == 1 || search_dict(dict->left, value) == 1)
    {
        return 1;
    }
    else // if (0 && 0) (both two sub-trees don't include the value)
    {
        return 0;
    }
}