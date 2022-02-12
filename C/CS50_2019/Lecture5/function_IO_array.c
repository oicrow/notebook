#include <stdio.h>
#include <stdlib.h> // malloc, free

void passArrayInt(int arr[]);
void passArrayStr(char *arr[]);
void passArrayInt_p(int *arr);
void passArrayStr_p(char **arr);
int *getArrayInt_i(int arr[]);
char **getArrayStr_i(char *arr[]);
int *getArrayInt_m(void);
char **getArratStr_m(void);
int *getArrayInt_s(void);
char **getArrayStr_s(void);
struct_array_int *getArrayInt_t(void);
struct_array_str *getArrayStr_t(void);

typedef struct
{
    int arr[3];
}
struct_array_int;

typedef struct
{
    char *arr[3];
}
struct_array_str;

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
//               output value of pointer to int as an array
int *getArrayInt_i(int arr[]) // or array of int as a pointer -- int *arr
{
    // Modify values of array
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;

    return arr;
}

// Function with input argument of array of pointer to char (to use for output value)
//               output value of pointer to pointer to char as an array
char **getArrayStr_i(char *arr[])  // or array of pointer to char as a pointer -- char **arr
{
    // Modify values of array
    arr[0] = "aaa";
    arr[1] = "bbb";
    arr[2] = "ccc";

    return arr;
}

// 2. Use dynamically allocated memory(malloc)
// Mallocated memory is stored in heap, so it doesn't disappear after the function call ended
// Function with output value of pointer to int as an array
int *getArrayInt_m(void)
{
    // Allocate memory for array of 3 int
    int *result = malloc(sizeof(int) * 3);
    if (result == NULL)
    {
        return NULL;
    }

    // Initialize values of array
    result[0] = 0;
    result[1] = 0;
    result[2] = 0;

    return result;
}

// Function with output value of pointer to pointers to char as an array
char **getArratStr_m(void)
{
    // Allocated memory for array of 3 pointer to char
    char **result = malloc(sizeof(char *) * 3);
    if (result == NULL)
    {
        return NULL;
    }

    // Initialize values of array
    result[0] = "aaa";
    result[1] = "bbb";
    result[2] = "ccc";

    return result;
}

// 3. Use static variable
// Static variable does not disappear even after the function call ended
// Function with output value of pointer to array of int
int *getArrayInt_s(void)
{
    // Declare static array of int
    static int arr[3];

    // Initialize values of array
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;

    return arr;
}

// Function with output value of pointer to array of pointer to char
char **getArrayStr_s(void)
{
    // Declare static array of pointer to char
    static char *arr[3];

    // Initialize values of array
    arr[0] = "aaa";
    arr[1] = "bbb";
    arr[2] = "ccc";

    return arr;
}

// 4. Use structure
// This actually works, because it returns contents of sturct_array_int, not pointer to struct_array_int
// Function with output value of structure including array of int
struct_array_int *getArrayInt_t(void)
{
    // Declare structure including array of int
    struct_array_int result;

    // Initialize values of array
    result->arr[0] = 0;
    result->arr[1] = 0;
    result->arr[2] = 0;

    return result;
}

// Function with output value of structure including array of pointer to char
struct_array_str *getArrayStr_t(void)
{
    // Declare structure including array of pointer to char
    struct_array_str result;

    // Initialize values of array
    result->arr[0] = "aaa";
    result->arr[1] = "bbb";
    result->arr[2] = "ccc";

    return result;
}