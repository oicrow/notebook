#include <stdio.h>

void modifyArrayInt(int array_of_int[]);
void modifyArrayStr(char *array_of_string[]);

int main(void)
{
    // Function with input argument of array of int
    int array_of_int[3] = { 1, 2, 3 };
    printf("%i\n", array_of_int[0]);
    modifyArrayInt(array_of_int);
    printf("%i\n", array_of_int[0]);

    // Function with input argument of array of pointers to char
    char* array_of_string[3] = { "abc", "def", "ghi" };
    printf("%s\n", array_of_string[0]);
    modifyArrayStr(array_of_string);
    printf("%s\n", array_of_string[0]);
}

// Function with input argument of array of int
void modifyArrayInt(int array_of_int[])
{
    array_of_int[0] = 10;
}

// Function with input argument of array of pointers to char
void modifyArrayStr(char *array_of_string[])
{
    array_of_string[0] = "modified";
}