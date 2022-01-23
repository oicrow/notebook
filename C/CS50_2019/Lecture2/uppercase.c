#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[16];
    printf("Input: ");
    scanf("%s", s);

    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') //
        {                               //  #include <ctype.h>
            printf("%c", s[i] - 32);    //
        }                               //  printf("%c", toupper(s[i]));
        else                            //
        {                               //
            printf("%c", s[i]);         //
        }                               //
    }
    printf("\n");
}