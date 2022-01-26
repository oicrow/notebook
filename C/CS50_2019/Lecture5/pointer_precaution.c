#include <stdio.h>

int main (void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 10;
    // *y = 20;     // ! buggy ! pointer y is pointing at nowhere. So can't store any values!

    free(x);

    // Likewise, scanf doesn't work as follows
    //
    //  char *s;
    //  printf("s: ");
    //  scanf("%s", s);
    // 
    // because s is pointing at nowhere!
    // Instead, try array or allocate memory
    
    char array_string[16];
    printf("array_string: ");
    scanf("%s", array_string);
    
    char *pointer_string = malloc(16);
    printf("pointer_string: ");
    scanf("%s", pointer_string);

    printf("%s\n%s\n", array_string, pointer_string);

    free(pointer_string);
}