#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }

    // implicitly returns 0 if all is well and it ended successfully
    // if not, use return 1 or -1 to notify that it ended with some error
    printf("\n\nphase 2\n");
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}