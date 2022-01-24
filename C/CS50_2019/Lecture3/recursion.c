#include <stdio.h>

void draw1(int h);
void draw2(int h);

int main(void)
{
    int height;
    printf("Height: ");
    scanf("%d", &height);

    draw1(height);
    draw2(height);
}

void draw1(int h)
{
    for (int i = 1; i <=h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void draw2(int h)
{
    if (h == 0)
    {
        return;
    }
    
    draw2(h - 1);
    
    for (int i = 1; i <= h; i++)
    {
        printf("#");
    }
    printf("\n");
}