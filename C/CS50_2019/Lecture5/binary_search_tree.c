// binary search tree

//         4        <- root node 
//       ↙  ↘
//     2       6
//   ↙↘     ↙↘
//   1  3    5   7

// Link nodes in hierarchy as two demensional linked list
// Recursive: Everything to the left of each node (left child or subtree) is smaller
//          : Everything to the right of each node (right child or subtree) is larger
// Pros: binary search - O(log n)
//     : insert - O(log n) -> there are algorithms that insert value with the tree balanced
//     : dynamic, since it's using pointers like linked list
// Cons: spend more space (2 pointers needed instead of 1)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

node *search_node(node *tree, int value);

int main(void)
{
    // Creating a tree
    node *tree = NULL;

    // node 4
    node *tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        return -1;
    }
    tmp->number = 4;
    tmp->left = NULL;
    tmp->right = NULL;
    tree = tmp;

    // noed 2
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree);
        return -1;
    }
    tmp->number = 2;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->left = tmp;

    // node 1
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree->left);
        free(tree);
        return -1;
    }
    tmp->number = 1;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->left->left = tmp;

    // node 3
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree->left->left);
        free(tree->left);
        free(tree);
        return -1;
    }
    tmp->number = 3;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->left->right = tmp;

    // node 6
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree->left->right);
        free(tree->left->left);
        free(tree->left);
        free(tree);
        return -1;
    }
    tmp->number = 6;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->right = tmp;

    // node 5
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree->right);
        free(tree->left->right);
        free(tree->left->left);
        free(tree->left);
        free(tree);
        return -1;
    }
    tmp->number = 5;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->right->left = tmp;

    // node 7
    tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        free(tree->right->left);
        free(tree->right);
        free(tree->left->right);
        free(tree->left->left);
        free(tree->left);
        free(tree);
        return -1;
    }
    tmp->number = 7;
    tmp->left = NULL;
    tmp->right = NULL;
    tree->right->right = tmp;


    // search values in the tree
    search_node(tree, 1);
    search_node(tree, 2);
    search_node(tree, 4);
    search_node(tree, 6);
    search_node(tree, 7);
    search_node(tree, 0);
    search_node(tree, 9);
    search_node(tree, 5);

    // free the tree
    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left->right);
    free(tree->left->left);
    free(tree->left);
    free(tree);

    return 0;
}

node *search_node(node *tree, int value)
{
    if (tree == NULL)
    {
        printf("%i is not in the tree.\n", value);
        return tree;
    }
    else if (value < tree->number)
    {
        return search_node(tree->left, value);
    }
    else if (value > tree->number)
    {
        return search_node(tree->right, value);
    }
    else // if (value == tree->number)
    {
        printf("%i is founded.\n", value);
        return tree;
    }
}