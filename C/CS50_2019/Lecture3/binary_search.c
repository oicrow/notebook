#include <stdio.h>
#include <string.h>

int main(void)
{
    int sorted[10] = {2, 5, 7, 8, 17, 35, 50, 67, 86, 123};

    // if no items
    //     return false
    // if middle item is 50
    //     return 50
    // else if 50 < middle item
    //     search left half
    // else if 50 > middtle item
    //     search right half
    
    
    // phonebook.c
    char *names[4] = {"EMMA", "RODRIGO", "BRAIN", "DAVID"};
    char *phonebook[4] = {"617-555-0100", "617-555-0101", "617-555-0102", "617-555-0103"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("%s\n", phonebook[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}