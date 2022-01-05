#include "hash_table.h"
#include <stdio.h>

int main()
{
   htHashTable* ht = htNewHashTable();
   htDelHashTable(ht);
   printf("Hello world.");
}