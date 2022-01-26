// to resize a list, you need to re-create and insert
// in that case, inserting (resizing) is O(n), searching is O(log n) (given that it's sorted)
// to improve this inefficiency, you can also use linked list

#include <stdio.h>
#include <stdlib.h> // malloc, free, realloc

int main (void)
{
    // possible but list name changes
    int array[3] = {1, 2, 3};
    int new_array[4];

    for (int i = 0; i < 3; i++)
    {
        new_array[i] = array[i];
    }

    new_array[3] = 4;


    // insert without changing list name
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    tmp[3] = 4;

    free(list);
    list = tmp;

    for (int i = 0; i < 3; i++)
    {
        pirntf("%i\n", list[i]);
    }

    free(tmp);


    // another way using realloc
    int *list0 = malloc(3 * sizeof(int));
    if (list0 == NULL)
    {
        return 1;
    }

    list0[0] = 1;
    list0[1] = 2;
    list0[2] = 3;

    int *tmp0 = relloc(list0, 4 * sizeof(int));   // list = realloc(list, 4 *sizeof(int)); isn't good because it might orphan the original list0
    if (tmp0 == NULL)
    {
        free(list0);
        return 1;
    }
    list0 = tmp0;

    tmp0[3] = 4;

    for (int i = 0; i < 3; i++)
    {
        pirntf("%i\n", list0[i]);
    }

    free(tmp0);
}

// void* realloc(void* ptr, size_t size)
// : allocates memory, basically expanding from the original ptr
//                   , if needed, allocating new memory and returning the address of that new memory
// : if fails to realloc, returns NULL pointer
//
// So, it's better to use temporary pointer to store new address, and the original ptr as backup
//
// [x] list = realloc(list, 4 *sizeof(int));
//  -> if new memory is allocated or realloc fails, the original memory is lost -> memory leak
//
// [o] int *tmp = relloc(list, 4 * sizeof(int));
//     if (tmp == NULL)
//     {
//         free(list);
//         free(tmp);
//         return 1;
//     }
//     list = tmp;
//  -> Better, because it never lose or leak any memory