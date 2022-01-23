#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 8 bits = 1 byte
    // RAM: random access memory
    // run program -> data stored in RAM

    // data types
    bool boolean = true;        // 1 byte
    char character = 'A';       // 1 byte   %c
    int integer = 123;          // 4 bytes  $i
    float float_number = 0.1    // 4 bytes  %f
    long long_number = 123;     // 8 bytes  %l
    double double_number = 123; // 8 bytes  %l
    char *string = "hello";     // ? bytes  %s

    char c1 = 'h';
    char c2 = 'i';
    char c3 = '!';

    printf("%c%c%c\n", c1, c2, c3);

    // explicit casting
    printf("%i%i%i\n", (int) c1, (int) c2, (int) c3);
    // implicit casting
    printf("%i%i%i\n", c1, c2, c3);
}