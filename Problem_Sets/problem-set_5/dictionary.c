// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int sizes[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Figuring out where to put the node
    int hash_value = hash(word);

    node *n = table[hash_value];

    if (n == NULL)
    {
        return false;
    }

    node *cursor = n;

    while (strcasecmp(cursor->word, word) != 0)
    {
        cursor = cursor->next;

        if (cursor == NULL)
        {
            return false;
        }
    }

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Making Node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(source);
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        // Figuring out where to put the node
        int hash_value = hash(word);

        node *starting_node = table[hash_value];

        // no nodes for this hash, let's start the list
        if (starting_node == NULL)
        {
            table[hash_value] = n;
            sizes[hash_value] = 0;
        }
        // otherwise append 1 item to the list
        else
        {
            n->next = starting_node;
            table[hash_value] = n;
        }

        sizes[hash_value]++;
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        counter += sizes[i];
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        if (cursor == NULL)
        {
            continue;
        }

        while (cursor->next != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        free(cursor);
    }

    return true;
}
