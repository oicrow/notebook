#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float average(int length, int array[]);

int main(void)
{
    // fixed
    // int n = 3;
    const int N = 3;    // UNchangable
    int scores[N];      // int scores[3] = {72, 73, 33};
    scores[0] = 72;     // int score1 = 72;
    scores[1] = 73;     // int score2 = 73;
    scores[2] = 33;     // int score3 = 33;

    printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / N);

    // dynamic
    int n;
    printf("Number of cookies: ");
    scanf("%d", &n);

    int cookies[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Cookies %i: ", i + 1);
        scanf("%d", &cookies[i]);
    }

    printf("Average Cookies: %.1f\n", average(n, cookies));
}

float average(int length, int array[])
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return (float) sum /(float) length; // up-cast if there's only one (float)
}