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


static htItem* htNewItem(const char* _key, const char* _value);
htHashTable* htNewHashTable();
static void htDelItem(htItem* item);
void htDelHashTable(htHashTable* ht);
