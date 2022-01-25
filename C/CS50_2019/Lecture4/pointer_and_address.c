#include <stdio.h>

int main (void)
{
    // &: AddressOf operator
    // *: GoTo operator
    // %p: format for address

    int n = 50;     // variable n for value 50
    int *p = &n;    // pointer p for the address of variable n

    printf("%i\n", n);  // the value of variable n
    printf("%p\n", &n); // the address of variable n
    printf("%i\n", *&n);// the value of variable n
    printf("%p\n", p);  // the value of p (= the address of variable n)
    printf("%i\n", *p); // the value that pointer p is pointing at (= value of n)
}