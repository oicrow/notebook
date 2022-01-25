#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main (void)
{
    char *s, t;
    printf("s: ");
    scanf("%s", s);
    printf("t: ");
    scanf("%s", t);


    // strcmp - in string.h
    // if same, returns 0
    // otherwise, return non-zero
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    

    // compare each char
    if (strlen(s) != strlen(t))
    {
        printf("Different\n");
    }
    else
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] != t[i])
            {
                printf("Different\n");
                break;
            }
            else if (i == n-1)
            {
                printf("Same\n");
            }
        }
    }


    // wrong example
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    // because s and t store different addresses
    printf("%p\n!=\n%p\n", s, t);

}