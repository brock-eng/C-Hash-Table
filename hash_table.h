#pragma once

// Hash table item
typedef struct {
   char* key;
   char* value;
} htItem;

// Hash table structure
typedef struct {
   int size, count;
   htItem** items;
} htHashTable;


// Item/table creation/deletion
static htItem* htNewItem(const char* _key, const char* _value);
static void htDelItem(htItem* item);
void htAPIDelTable(htHashTable* ht);
htHashTable* htAPICreate();

// Hash functions
static int htHashFunction(char* string, int numBuckets);
static int htGetHash(const char* string, const int numBuckets, const int attempt);

// Table usage
void htAPIInsert(htHashTable* ht, const char* key, const char* value);
char* htAPISearch(htHashTable* ht, const char* key);
void htAPIDelete(htHashTable* ht, const char* key);
