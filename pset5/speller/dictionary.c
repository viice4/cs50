// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26 * 27;

// Hash table
node *table[N];

int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int i = hash(word);
    node *curs = table[i];
    while (curs->next != NULL)
    {
        bool in = strcasecmp(word, curs->word);
        if (in)
        {
            return true;
        }
        else
        {
            curs = curs->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char word0 = word[0];
    char word1 = word[1];
    char fst = tolower(word0);
    char scd = tolower(word1);
    
    if (fst < 'a' || fst > 'z')
    {
        return 1;
    }

    if (scd < '\'' || (scd > '\'' && scd < 'a') || scd > 'z')
    {
        return 1;
    }

    int ifst = fst - 97;
    int iscd;
    if (scd == '\'')
    {
        iscd = scd - 12;
    }
    else
    {
        iscd = scd - 96; 
    }

    int index = ifst * 26 + iscd - 1;
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    if (!dic)
    {
        return false;
    }

    char iword[LENGTH + 1];
    while (fscanf(dic, "%s", iword) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not malooc.\n");
            return false;
        }

        fscanf(dic, "%s", n->word);
        n->next = NULL;
        int i = hash(n->word);
        if (table[i] == NULL)
        {
            table[i] = n;
            count++;
        }
        else
        {
            node *tmp = table[i];
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = n;
            count++;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp = NULL;
    node *curs = NULL;
    int free_count = 0;
    
    for (int i = 0; i < N; i++)
    {
        tmp = table[i];
        curs = table[i];
        while (curs != NULL)
        {
            curs = curs->next;
            free(tmp);
            tmp = tmp->next;
            free_count++;
        }
    }

    if (free_count == N)
    {
        return true;
    }
    return false;
}
