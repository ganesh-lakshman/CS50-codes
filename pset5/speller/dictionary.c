// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26 * 26 * 26; //26 buckets

// Hash table is array of linked list,an aray in which every element in that array is pointer to that node

node *table[N];

//add data
/*node *n = malloc(sizeof(node));
strcpy(n->word,"hello");
n->next == NULL;*/

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int i = hash(word);
    /* for (node *tmpr8 = table[i]; tmpr8 != NULL; tmpr8 = tmpr8->next)
     {
         printf("%s\n",tmpr8->word);
     }*/
    for (node *tmpr = table[i]; tmpr != NULL; tmpr = tmpr->next)
    {
        if (strcasecmp(tmpr->word, word) == 0)
        {
            return true;
        }
        /*else
        {
            return false
        }*/
        //return strcasecmp(tmpr->word, word);
    }
    //return true;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO it assigns a number to the particular string so that it can go to that particular linked list
    //which bucket
    /* unsigned int hash_value = 0;
     for (int i = 0, n = strlen(word); i < n; i++)
     {
          hash_value = (hash_value << 2) ^ word[i];
     }
     return hash_value % N; //N is size of hashtable*/
    // unsigned int hashvalue = 0;
    /* if((int)word[0]<=122 || (int)word[0]>=97)
      {
          hashvalue = (int)word[0]-97;
      }
      return hashvalue;*/
    unsigned long hash = 5381;

    int c = *word;

    c = tolower(c);

    while (*word != 0)

    {

        hash = ((hash << 5) + hash) + c;

        c = *word++;

        c = tolower(c);

    }

    return hash % N;


}
int sizes = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary
    //read strings one word at a time
    //creae a new node for each word
    //use hash on that word amd obtaina value,to determine which linked list to insert a particular word

    //insert node into hash table at that location that hash fun given
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char *words = NULL;
    words = malloc(100);

    while (fscanf(file, "%s", words) != EOF)
    {
        node *n = malloc(sizeof(node));
        //fscanf(file, "%s", words); dumbest mistake
        // node *n = malloc(sizeof(node));
        if (n != NULL)
        {
            strcpy(n->word, words);
            n->next = NULL;
        }
        unsigned int i = hash(n->word);
        if (table[i] == NULL)
        {
            table[i] = n;
            sizes++;
            // return true;
        }
        else if (table[i] != NULL)
        {
            n->next = table[i];
            table[i] = n;
            // return true;
            sizes++;
        }
    }
    fclose(file);
    free(words);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int size = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *tmpr = table[i]; tmpr != NULL; tmpr = tmpr->next)
        {
            size++;
        }
    }

    //return sizes;
    return size;
}




// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp1 = table[i]->next;//free behind memory not infront once freed we shouldnt touch it
            free(table[i]);
            table[i] = tmp1;
        }
    }

    return true;
}
