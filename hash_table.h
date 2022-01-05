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


// Hash memory creation/deletion
static htItem* htNewItem(const char* _key, const char* _value);
htHashTable* htNewHashTable();
static void htDelItem(htItem* item);
void htDelHashTable(htHashTable* ht);

// Hash functions
static int htHashFunction(char* string, int numBuckets);
static int htGetHash(const char* string, const int numBuckets, const int attempt);

// API
void htAPIInsert(htHashTable* ht, const char* key, const char* value);
char* htAPISearch(htHashTable* ht, const char* key);
void htAPIDelete(htHashTable* ht, const char* key);
