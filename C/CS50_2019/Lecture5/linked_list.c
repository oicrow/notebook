// precaution: NULL is pointer to nowhere (0x0, or hexadecimal 0)
//           : NUL is character '\0', represented with binary 0

// + linked list can resize list so easily
//     -> insert: O(1)
// - but since you alwaysneed to access from the root node along the list, only linear search is available
//     -> search: O(n)
// - also, you need to sacrifice more memory to store the pointer to the next node


#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{

}