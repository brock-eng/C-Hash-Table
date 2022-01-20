#include "hash_table.h"
#include <stdio.h>

int main()
{
   htHashTable* ht = htNewHashTable();
   htDelHashTable(ht);
   htAPIInsert(ht, "Color", "Red");
   htAPIInsert(ht, "Material", "Steel");
   htAPIInsert(ht, "Profession", "Painter");

   printf(htAPISearch(ht, "Color"));
   printf(htAPISearch(ht, "Material"));
   printf(htAPISearch(ht, "Profession"));
}