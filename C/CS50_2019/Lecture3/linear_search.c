#include <stdio.h>
#include <string.h>

int main(void)
{
    int unsorted[10] = {8, 35, 2, 50, 123, 7, 5, 86, 17, 67};

    // for i from 0 to n-1
    //     if i'th element is 50
    //         return true
    // return false

    for (int i = 0, n = sizeof(unsorted) / sizeof(int); i < n; i++)
    {
        if (unsorted[i] == 50)
            // return true
    }
    // return false


    // numbers.c
    int numbers[6] = {4, 8, 15, 16, 23, 42};

    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("50 found\n");
            // return 0;
        }
    }
    printf("50 Not found\n");
    // return 1;


    // names.c
    char *names[4] = {"EMMA", "RODRIGO", "BRAIN", "DAVID"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i],"EMMA") == 0)  // 0 if same - declared in string.h
        {
            printf("EMMA found\n");
            // return 0;
        }
    }
    printf("EMMA not found\n")
    // return 1;
}