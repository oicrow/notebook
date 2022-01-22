#include <stdio.h>

int main(void)
{
    int age;
    printf("What's your age?\n");
    scanf("%d", &age);
    printf("You are at least %d days old.", age * 365);
}