#include "prime.h"
#include <math.h>

bool isPrime(int num)
{
   if (num < 2) return 0;
   else if (num < 4) return 1;
   else if (num % 2 == 0 || num % 3 == 0) return 0;
   else
   {
      for (int i = 5; i < floor(sqrt(num)); i++)
      {
         if (num % i == 0) return 0;
      }
      return 1;
   }
}

int nextPrime(int num)
{
   num++;
   while (!isPrime(num))
   {
      num++;
   }
   return num;
}