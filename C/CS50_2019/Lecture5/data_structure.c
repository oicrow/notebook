#include <stdio.h>

typedef struct
{
    int red;
    int green;
    int blue;
} pixel;

int main(void)
{
    // struct : keyword to creat own structure
    // . : dot notaton to access a property of a structure
    // * : dereference operator to go to the address
    // ->: stands for (*ptr).argument

    pixel image[3];

    image[0].red = 0;
    image[0].green = 0;
    image[0].blue = 0;
    image[1].red = 255;
    image[1].green = 255;
    image[1].blue = 255;
    image[2].red = 0;
    image[2].green = 255;
    image[2].blue = 255;

    pixel *ptr_to_pixel = &image[0];
    ptr_to_pixel->red = 255;

    printf("%i\n", image[0].red);
}