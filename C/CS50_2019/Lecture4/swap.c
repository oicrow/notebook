#include <stdio.h>

void swap(int *a, int *b);
void swap_wrong(int a, int b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x: %i, y: %i\n", x, y);
    swap(&x, &y);
    printf("x: %i, y: %i\n", x, y);
}

void swap(int *a, int *b)       // Call by Reference
{
    int tmp = *a;
    *a = *b;                    // access the variable of main stack frame by pointer
    *b = tmp;                   // access the variable of main stack frame by pointer
}

void swap_wrong(int a, int b)   // Call by Value (by default)
{                               // duplicating the arguments and not touching the original
    int tmp = a;
    a = b;
    b = tmp;
}