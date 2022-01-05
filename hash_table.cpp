#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "hash_table.h"

// Hash table size
const int SIZE = 53;

const static htItem HT_DELETED = { NULL, NULL };

static htItem* htNewItem(const char* _key, const char* _value)
{
   htItem* item = (htItem*)malloc(sizeof(htItem));
   item->key = _strdup(_key);
   item->value = _strdup(_value);
}

htHashTable* htNewHashTable()
{
   htHashTable* ht= (htHashTable*)malloc(sizeof(htHashTable));

   ht->size = SIZE;
   ht->count = 0;
   ht->items = (htItem**)calloc((size_t)ht->size, sizeof(htItem*));
   return ht;
}

static void htDelItem(htItem* item)
{
   free(item->key);
   free(item->value);
   free(item);
}

void htDelHashTable(htHashTable* ht)
{
   for (int i = 0; i < ht->size; i++)
   {
      htItem* item = ht->items[i];
      if (item != NULL)
      {
         htDelItem(item);
      }
   }

   free(ht->items);
   free(ht);
}

static int htHashFunction(const char* string, const int prime, const int numBuckets)
{
   int hash = 0;
   int stringLength = strlen(string);
   for (int i = 0; i < stringLength; i++)
   {
      hash += (long)pow(prime, (stringLength - (i + 1))) * string[i];
      hash = hash % numBuckets;
   }
   return (int)hash;
}

// Double hashing collision resolution
static int htGetHash(const char* string, const int numBuckets, const int attempt)
{
   const int HT_PRIME1 = 257;
   const int HT_PRIME2 = 263;
   const int hashA = htHashFunction(string, HT_PRIME1, numBuckets);
   const int hashB = htHashFunction(string, HT_PRIME2, numBuckets);

   return (hashA + (attempt * (hashB + 1))) % numBuckets;
}

// Insert a new key/value pair
void htAPIInsert(htHashTable* ht, const char* key, const char* value)
{
   htItem* item = htNewItem(key, value);
   int attempt = 0;
   int index = htGetHash(item->key, ht->size, attempt);
   htItem* curItem = ht->items[index];
   attempt++;
   while (curItem != NULL) // Collision handling
   {
      index = htGetHash(item->key, ht->size, attempt);
      curItem = ht->items[index];
      attempt++;
   }
   ht->items[index] = item;
   ht->count++;
   return;
}

// Return the value for a given key
char* htAPISearch(htHashTable* ht, const char* key)
{
   int attempt = 0;
   int index = htGetHash(key, ht->size, attempt);
   htItem* item = ht->items[index];
   attempt++;
   while (item != NULL)
   {
      if (strcmp(item->key, key) == false)
      {
         return item->value;
      }
      index = htGetHash(key, ht->size, attempt);
      item = ht->items[index];
      attempt++;
   }
   return NULL;
}

// Mark a given key as 'deleted'
void htAPIDelete(htHashTable* ht, const char* key)
{

}