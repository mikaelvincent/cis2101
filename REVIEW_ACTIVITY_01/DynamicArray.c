#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"

void initList(List *list){
	list->elems = (DATA*) malloc(sizeof(DATA) * list->max);
	list->count = 0;
}

List newList(int max){
	List list;
	list.max = max;
	initList(&list);
	return list;
}

void displayList(List list){
	for(int i = 0; i < list.count; i++){
		printf("%d ", list.elems[i]);
	}
	printf("\n");
}

bool insertFront(List *list, DATA item){
	if(list->count >= list->max){
		list->max *= 2;
		list->elems = (DATA*) realloc(list->elems, sizeof(DATA) * list->max);
	}
	for(int i = list->count; i > 0; i--){
		list->elems[i] = list->elems[i-1];
	}
	list->elems[0] = item;
	list->count++;
	return true;
}

bool insertRear(List *list, DATA item){
	if(list->count >= list->max){
		list->max *= 2;
		list->elems = (DATA*) realloc(list->elems, sizeof(DATA) * list->max);
	}
	list->elems[list->count] = item;
	list->count++;
	return true;
}

bool insertSorted(List *list, DATA item){
	if(list->count >= list->max){
		list->max *= 2;
		list->elems = (DATA*) realloc(list->elems, sizeof(DATA) * list->max);
	}
	int i = 0;
	while(i < list->count && list->elems[i] < item){
		i++;
	}
	for(int j = list->count; j > i; j--){
		list->elems[j] = list->elems[j-1];
	}
	list->elems[i] = item;
	list->count++;
	return true;
}

bool insertAt(List *list, DATA item, int loc){
	if(loc < 0 || loc > list->count){
		return false;
	}
	if(list->count >= list->max){
		list->max *= 2;
		list->elems = (DATA*) realloc(list->elems, sizeof(DATA) * list->max);
	}
	for(int i = list->count; i > loc; i--){
		list->elems[i] = list->elems[i-1];
	}
	list->elems[loc] = item;
	list->count++;
	return true;
}

bool searchItem(List list, DATA key){
	for(int i = 0; i < list.count; i++){
		if(list.elems[i] == key){
			return true;
		}
	}
	return false;
}

int getItem(List list, DATA key){
	for(int i = 0; i < list.count; i++){
		if(list.elems[i] == key){
			return i;
		}
	}
	return -1;
}

bool deleteFront(List *list){
	if(list->count == 0){
		return false;
	}
	for(int i = 0; i < list->count - 1; i++){
		list->elems[i] = list->elems[i+1];
	}
	list->count--;
	return true;
}

bool deleteRear(List *list){
	if(list->count == 0){
		return false;
	}
	list->count--;
	return true;
}

int deleteAt(List *list, int loc){
	if(loc < 0 || loc >= list->count){
		return -1;
	}
	for(int i = loc; i < list->count - 1; i++){
		list->elems[i] = list->elems[i+1];
	}
	list->count--;
	return loc;
}

bool deleteItem(List *list, DATA key){
	int loc = getItem(*list, key);
	if(loc == -1){
		return false;
	}
	return deleteAt(list, loc);
}

int deleteAllItem(List *list, DATA key){
	int count = 0;
	while(deleteItem(list, key)){
		count++;
	}
	return count;
}

void deleteList(List *list){
	free(list->elems);
	list->elems = NULL;
	list->count = 0;
	list->max = 0;
}