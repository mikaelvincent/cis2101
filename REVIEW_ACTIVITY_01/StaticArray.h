#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <stdbool.h>

#define MAX 10

typedef int DATA;

typedef struct {
	DATA elems[MAX];
	int count;
} List;

void initList(List *list);
List newList();
void displayList(List list);
bool insertFront(List *list, DATA item);
bool insertRear(List *list, DATA item);
bool insertSorted(List *list, DATA item);
bool insertAt(List *list, DATA item, int loc);
bool searchItem(List list, DATA key);
int getItem(List list, DATA key);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAt(List *list, int loc);
bool deleteItem(List *list, DATA key);
int deleteAllItem(List *list, DATA key);
void deleteList(List *list); // sets the list to an empty state, added to have same test code for DynamicArray

#endif
