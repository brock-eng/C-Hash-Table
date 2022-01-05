#include "hash_table.h"
#include <stdio.h>

int main()
{
   htHashTable* ht = htNewHashTable();
   htDelHashTable(ht);
   htAPIDelete(ht, "fart");
   printf("Hello world.");
}