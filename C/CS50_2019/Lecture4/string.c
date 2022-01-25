#include <stdio.h>

typedef char *string;   // creat a data type named 'string', which actually is a pointer to char

int main (void)
{
    // definition of string
    // 1. an array of char
    //  char s[n] = "string!";
    //  > s[0] == 's', ... , s[6] = '!'
    //
    // 2. a pointer to the first char
    //  char *s = "string!";
    //  > s -> 's', ... , s+6 -> '!', s+7 -> '\0' (Null Terminator)

    char *s0 = "EMMA";
    string s1 = "RODRIGO";

    printf("%s\n", s0);     // "EMMA"
    
    printf("%p\n", s0);     // 0x--- (address of 'E')
    printf("%p\n", &s0[0]); // 0x--- (address of 'E')
    
    printf("%c\n", *s0);    // 'E'
    printf("%c\n", *(s0+1));// 'M'
    printf("%c\n", *(s0+2));// 'M'
    printf("%c\n", *(s0+3));// 'A'

    printf("%c\n", s0[0]);  // 'E'
    printf("%c\n", s0[1]);  // 'M'
    printf("%c\n", s0[2]);  // 'M'
    printf("%c\n", s0[3]);  // 'A' 
}