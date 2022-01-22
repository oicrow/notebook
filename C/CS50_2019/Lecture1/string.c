#include <stdio.h>

int main(void)
{
    char answer[10];
    printf("what's your name?\n");
    scanf("%s", answer);
    printf("hello %s\n", answer);
}