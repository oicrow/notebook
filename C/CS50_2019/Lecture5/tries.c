// Trie (tries: short for retrieval)
//  : a tree, whose nodes are arrays
//  : spend far more memory but provide instant access for elements
//  : an array represents the roots of the trie
//  : search takes constant time, so it's O(1)

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

#define _CRT_SECURE_NO_WARNINGS
#define CHAR_SIZE 26

typedef struct trie
{
    int isLeaf;   // 1 if it's a leaf node, 0 if not
    struct trie *character[CHAR_SIZE];
} trie;

///////////////////////////// prototypes of functions here ///////////////////////////////

int main(void)
{
    // Make head node
    trie *head = malloc(sizeof(trie));
    if (head == NULL)
    {
        return -1;
    }
    head->isLeaf = 0;
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        head->character[i] = NULL;
    }
}

int char_to_index(char character);
{
    // Ensure it's capital letter
    if (character >= 97 && character <= 122)
    {
        character -= 32;
    }

    return (int) character - 65;
}

// Function to insert a string into a trie
//  : big or small letters are accepted but not distinguished
void insert(trie *head, char *word)
{
    // Ensure head exists
    if (head == NULL)
    {
        printf("Invalid trie.\n");
        return;
    }

    trie *curr_trie = head;

    // Repeat for each letter of word
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        int curr_index = char_to_index(word[i]);

        // if the path doesn't exist, make new node
        if (curr_trie->character[curr_index] == NULL)
        {
            curr_trie->character[curr_index] = malloc(sizeof(trie));
            if (curr_trie->character[curr_index] == NULL)
            {
                printf("Insert failed.\n");
                return;
            }

            // and initialize its isLeaf and character[]
            curr_trie->character[curr_index]->isLeaf = 0;
            for (int j = 0; j < CHAR_SIZE; j++)
            {
                curr_trie->character[curr_index]->character[j] = NULL;
            }
        }

        // Move to corresponding following trie
        curr_trie = curr_trie->character[curr_index];
    }

    // Make the last trie as a leaf
    curr_trie->isLeaf = 1;
}

// Function to check if a string is in a trie
//  : returns - 1, if the string is found
//            - 0, otherwise
int search(trie *head, char *word)
{
    // Return 0 if trie is empty
    if (head == NULL)
    {
        printf("The trie is empty.\n", word);
        return 0;
    }

    trie *curr = head;
    int length = strlen(word);
    int i = 0;

    while (curr->character[char_to_index(word[i])] != NULL)
    {
        curr = curr->character[char_to_index(word[i])];
    }


}