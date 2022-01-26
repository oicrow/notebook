#include <stdio.h>
#include <stdlib.h> // malloc, free

int main (void)
{
    ///// adding lines to phonebook.csv /////
    // Open file
    FILE *file = fopen("phonebook.csv", "a");   // a pointer to a file named "phonebook.csv"
    // FILE: data type of file
    // fopen: open a file
    //      : 1st argument - name of file
    //      : 2nd argument - "r" to read, "w" to write, "a" to append (write overwrites, and append adds)
    //      : output - the address of the file opened
    // CSV: Comma Separated Value (one of the file extensions)

    // Get strings from user
    char *name = malloc(16);
    char *number = malloc(16);
    printf("Name: ");
    scanf("%s", name);
    printf("Number: ");
    scanf("%s", number);

    // Print (write) strings to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);    

    free(name);
    free(number);
}

// FILE* fopen(const char* fileName, const char* fileMode)
// fileName: name of the file including path
// fileMode:      - mode    - read - overwrite - add - create file
//           "r"  - read    -  o   -     x     -  x  -    x Error
//           "w"  - write   -  x   -     o     -  x  -      o
//           "a"  - append  -  x   -     x     -  o  -      o
//           "r+" - read+   -  o   -     o     -  x  -    x Error
//           "w+" - write+  -  o   -     o     -  x  -      o
//           "a+" - append+ -  o   -     x     -  o  -      o

// int fclose(FILE* filePointer)
// return: 0 if closed successfully, -1(EOF) otherwise