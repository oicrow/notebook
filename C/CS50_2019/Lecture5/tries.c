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

int char_to_index(char character);
int noChild(trie *curr);
void insert(trie *head, char *word);
int search(trie *head, char *word);
void delete(trie *head, char *word);
void delete_trie(trie **curr, trie **prev);

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

    // Test if delete all well
    insert(head, "abc");
    delete(head, "abc");

    // insert words
    insert(head, "cookie");
    insert(head, "cheese");
    insert(head, "chocolate");
    insert(head, "butter");
    insert(head, "greentea");
    insert(head, "tart");
    insert(head, "pie");

    // search words
    search(head, "cookie");     // O
    search(head, "cookies");    // X 
    search(head, "cheese");     // O
    search(head, "cheesy");     // X
    search(head, "chocolate");  // O
    search(head, "blueberry");  // X
    search(head, "pancake");    // X

    // delete words
    delete(head, "cookie");     // O
    delete(head, "cheesepool"); // X is already not in the trie.
    delete(head, "piepie");     // X is already not in the trie.
    delete(head, "choco");      // X is already not in the trie.
    delete(head, "green");      // X is already not in the tire.
    delete(head, "tart");       // O
    delete(head, "tart");       // X

    // delete all
    delete_trie(&head, NULL);

    return;
}

// Function to convert a char to index of trie's character (array)
//  : big or small letters are accepted but not distinguished
int char_to_index(char character)
{
    // Ensure it's capital letter
    if (character >= 97 && character <= 122)
    {
        character -= 32;
    }

    return (int) character - 65;
}

// Function to check if the trie does not have any child trie
//  : returns - 1, if trie has no child
//            - 0, if trie has any child
int noChild(trie *curr)
{
    // Check for every character[i]
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        // If any character[i] points at any other trie, return 0
        if (curr->character[i] != NULL)
        {
            return 0;
        }
    }

    // If every character[i] points at NULL, return 1
    return 1;
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
    // Ensure word is not blank
    if (word == "")
    {
        printf("Word is blank.\n");
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
//  : big or small letters are accepted but not distinguished
int search(trie *head, char *word)
{
    // Return 0 if trie is empty
    if (head == NULL)
    {
        printf("The trie is empty.\n");
        return 0;
    }
    // Return 0 if word is blank
    if (word == "")
    {
        printf("Word is blank.\n");
        return 0;
    }

    trie *curr = head;
    int i = 0;

    // Follow along tries corresponding to each letter of word, if exists
    while (curr->character[char_to_index(word[i])] != NULL)
    {
        curr = curr->character[char_to_index(word[i])];
        i++;

        // If it's end of the word, see if it's a leaf trie
        if (!word[i])
        {
            if (curr->isLeaf == 1)  // If it's leaf trie, return 1
            {
                printf("%s is in the trie.\n", word);
                return 1;
            }
            else                    // If it's not leaf trie, return 0
            {
                printf("%s is not in the trie.\n", word);
                return 0;
            }
        }
    }

    // If there's no path in the middle, return 0
    printf("%s is not in the trie.\n", word);
    return 0;
}

// Function to delete a string from trie
//  : big or small letters are accepted but not distinguished
void delete(trie *head, char *word)
{
    // Ensure head exists
    if (head == NULL)
    {
        printf("Invalid trie.\n");
        return;
    }
    // Ensure word is not blank
    if (word == "")
    {
        printf("Word is blank.\n");
        return;
    }

    // Move curr to the last trie of the word, prev to the trie right before curr
    trie *curr = head;
    trie *prev = head;
    int i = 0;
    while (word[i]) // Repeat for every letter, until the end of the word
    {
        // If there's no path in the middle, return
        if (curr->character[char_to_index(word[i])] == NULL)
        {
            printf("%s is already not in the trie.\n", word);
            return;
        }

        // Move curr and prev one trie below respectively
        curr = curr->character[char_to_index(word[i])];
        if (i != 0) // (don't move prev for the first recurrence)
        {
            prev = prev->character[char_to_index(word[i - 1])];
        }

        // Move to next letter of word
        i++;
    }

    // If path exists but it doesn't end there, return
    if (curr->isLeaf == 0)  // (because word does not exsist then)
    {
        printf("%s is already not in the trie.\n", word);
        return;
    }

    // Mark curr is not leaf, so that the word is deleted
    curr->isLeaf = 0;

    // Free curr, if it is not necessary because it represents no word
    // Recur to clean up the tries above
    // (if parent trie has no other child and not leaf, delete the parent too)
    while (noChild(curr) && curr->isLeaf == 0)
    {
        // Move curr and prev one trie above respectively
        // prev->curr, tmp:idle  --->  prev->curr(original prev)->tmp(original curr)
        int j = 0;          // int j to recur for every letter of word
        trie *tmp = curr;   // temporarily represents the former curr
        curr = head;        // Initialize curr to head
        prev = head;        // Initialize prev to head
        while (word[j] && (curr->character[char_to_index(word[j])] != tmp))
        {   // Recur until curr points at the trie right before tmp
            // Move curr and prev one trie below respectively
            curr = curr->character[char_to_index(word[j])];
            if (j != 0) // (don't move prev for the first recurrence)
            {
                prev  = prev->character[char_to_index(word[j - 1])];
            }

            // Move to next letter of word
            j++;
        }

        // Unlink tmp and curr, which were originally prev and curr before moving
        curr->character[char_to_index(word[j])] = NULL;

        // Then delete tmp (original curr)
        free(tmp);

        // If curr == head, that is, there's no trie to free any more, return
        if (curr == head)
        {
            return;
        }
        
        // Move to next letter of word
        i++;
    }
}

// Function to delete and free entire trie
void delete_trie(trie **curr, trie **prev)
{
    // Ensure trie is not empty (only when the first call by user)
    if ((prev == NULL) && (*curr == NULL))
    {
        printf("The trie doesn't exsist.\n");
        return;
    }

    // Delete all child tries below (Recur)
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if ((*curr)->character[i] != NULL)   // (if exists)
        {
            delete_trie(&((*curr)->character[i]), curr);
        }
    }

    if (prev != NULL)   // If it's not the first call (if it's recursively called)
    {
        // Find corresponding i that satisfies (*prev)->character[i] == (*curr)
        int i = 0;
        while ((*prev)->character[i] != (*curr))
        {
            i++;
        }

        // Unlink them
        (*prev)->character[i] = NULL;
    }
    
    // Free the current trie
    free(*curr);
    
    return;
}