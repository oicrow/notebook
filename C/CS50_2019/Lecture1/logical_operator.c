#include <stdio.h>

int main(void)
{
    // OR ||
    char c;
    printf("Do you agree?\n");
    scanf("%c", &c);

    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }

    // AND &&
    int x = 0;
    int y = 1;

    if (x && y)
    {
        printf("Both x and y are not 0.\n");
    }

    // NOT !
    if (!x && y)
    {
        printf("x is 0 and y is not 0.\n");
    }
}