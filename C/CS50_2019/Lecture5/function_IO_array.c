#include <stdio.h>
#include <stdlib.h> // malloc, free

void passArrayInt(int arr[]);
void passArrayStr(char *arr[]);
void passArrayInt_p(int *arr);
void passArrayStr_p(char **arr);
int *returnArrayInt(void);
char **returnArrayStr(void);

int main(void)
{
// INPUT array

    // Passing array of int to function
    int array_of_int[3] = {1, 2, 3};
    printf("%i\n", array_of_int[0]);
    passArrayInt(array_of_int);
    printf("%i\n", array_of_int[0]);

    // Passing array of int to function as a pointer
    int array_of_int_p[3] = {1, 2, 3};
    printf("%i\n", array_of_int_p[0]);
    passArrayInt_p(array_of_int_p);
    printf("%i\n", array_of_int_p[0]);

    // Passing array of pointers to char to function
    char* array_of_string[3] = {"abc", "def", "ghi"};
    printf("%s\n", array_of_string[0]);
    passArrayStr(array_of_string);
    printf("%s\n", array_of_string[0]);

    // Passing array of pointers to char to function as a pointer
    char* array_of_string_p[3] = {"abc", "def", "ghi"};
    printf("%s\n", array_of_string_p[0]);
    passArrayStr_p(array_of_string_p);
    printf("%s\n", array_of_string_p[0]);
    

// OUTPUT array

    // Function with output value of pointer to array of int
    int *new_array_of_int = returnArrayInt();
    printf("%i\n", new_array_of_int[0]);
    printf("%i\n", new_array_of_int[1]);
    printf("%i\n", new_array_of_int[2]);
    free(new_array_of_int);

    // Function with output value of pointer to array of pointers to char
    char **new_array_of_str = returnArrayStr();
    printf("%s\n", new_array_of_str[0]);
    printf("%s\n", new_array_of_str[1]);
    printf("%s\n", new_array_of_str[2]);
    free(new_array_of_str);
}


// INPUT array

// Function with input argument of array of int
void passArrayInt(int arr[])
{
    arr[0] = 10;
}

// Function with input argument of array of pointers to char
void passArrayStr(char *arr[])
{
    arr[0] = "modified";
}

// Function with input argument of array of int as a pointer
void passArrayInt_p(int *arr)
{
    arr[0] = 10;
}

// Function with input argument of array of pointers to char as ap pointer
void passArrayStr_p(char **arr)
{
    arr[0] = "modified";
}


// OUTPUT array

// 1. Use input array
// Function with input argument of array of int (to use for output value)
//               output value of pointer to array of int
int *getArrayInt_i(int arr[]) // or array of int as a pointer -- int *arr
{
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;

    return arr;
}

// 2. Use dynamically allocated memory(malloc)
// Function with output value of pointer to array of int
int *getArrayInt_p(void)
{
    int result[3] = malloc(sizeof(int) * 3);
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;
    return result;
}

// Function with output value of pointer to array of pointers to char
char **returnArrayStr(void)
{
    char *result[3] = malloc(sizeof(char) * 12);
    result[0] = "aaa";
    result[1] = "bbb";
    result[2] = "ccc";
    return result;
}