#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s= "HI!";     // 4 bytes: 'H', 'I', '!', \0 (Null Terminator)

    for (int i = 0, n = strlen(s); i < n; i++)  // for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}