#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen, strcpy
#include <ctype.h>  // toupper
#include <stdlib.h> // malloc, free

int main(void)
{
    // Copy Linked
    char *s = malloc(16);
    printf("s: ");
    scanf("%s", s);

    char *t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s); // linked!
    printf("t: %s\n", t); // linked!

    free(s);


    // Copy Unlinked
    char *u = malloc(16);
    printf("u: ");
    scanf("%s", u);

    char *v = malloc(strlen(u) + 1);

    for (int i = 0, n = strlen(u) + 1; i < n; i++)  // n = strlen(u) + 1 
    {                                               // to duplicate null terminator too
        v[i] = u[i];
    }

    v[0] = toupper(v[0]);

    printf("u: %s\n", u); // Not linked!
    printf("v: %s\n", v); // Not linked!


    // Copy Unlinked 2 - strcpy - in string.h
    char * w = malloc(strlen(u) + 1);
    strcpy(w, u);

    w[0] = toupper(w[0]);

    printf("u: %s\n", u); // Not linked!
    printf("w: %s\n", w); // Not linked!

    free(u);
    free(v);
    free(w);
}