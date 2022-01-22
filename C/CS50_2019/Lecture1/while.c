#include <stdio.h>

int main(void)
{
    // while
    int i = 0;
    while (i < 5)
    {
        printf("hello world\n");
        i++;
    }

    // do-while
    int n;
    do
    {
        printf("Positive Integer: ");
        scanf("%d", &n);
    }
    while (n < 1);
    printf("%d", n);
}