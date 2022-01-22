#include <stdio.h>

int main (void)
{
    int x, y;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else        // else if (x == y)
    {
        printf("x is equal to y\n");
    }
}