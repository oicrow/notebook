#include <stdio.h>

int main(void)
{
    int counter = 0;
    printf("%d\n", counter);

    counter = counter + 1;
    counter += 1;
    counter ++;

    printf("%d\n", counter);
}