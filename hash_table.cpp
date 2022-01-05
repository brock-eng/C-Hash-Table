#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

// Hash table size
const int SIZE = 53;

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