
#define SIZE 50000

typedef struct Ht_item Ht_item;

// Defined Hash Table
struct Ht_item
{
   char* key;
   char* value;
};

// Hashing function
unsigned long HashFunction(char* string)
{
   unsigned long hashCounter = 0;
   for (int i; string[i]; i++)
      hashCounter += string[i];
   return hashCounter % SIZE;
}
