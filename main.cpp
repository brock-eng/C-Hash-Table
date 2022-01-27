#include "hash_table.h"
#include <stdio.h>
#include "prime.h"

inline void sprint(const char* string)
{
   if (!string)
   {
      printf("Null");
      printf("\n");
      return;
   }
   printf(string);
   printf("\n");
}

int main()
{
   htHashTable* ht = htAPICreate();
   
   htAPIInsert(ht, "10 + 10 =", "20");
   htAPIInsert(ht, "15 + 15", "30");
   htAPIInsert(ht, "test key", "test value");
   htAPIInsert(ht, "bolony", "sandwich");

   sprint(htAPISearch(ht, "unknown key"));
   sprint(htAPISearch(ht, "bolony"));
   sprint(htAPISearch(ht, "test key"));

   htAPIDelTable(ht);
   
   int x = 2;
   int y = nextPrime(x);

   for (int i = 0; y < 100000000; i++)
   {
      printf("%d ", y);
      if (i % 10 == 0) printf("\n");
      y = nextPrime(y);
   }
   return 0;
}