#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cursor_Based.h"

Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap vh;
	
	int i;
	
	for(i = 0; i < MAX; i++){
		vh.elems[i].elem = newStudent(0,"",' ',"");
		vh.elems[i].next = i - 1;
	}
	
	vh.avail = MAX - 1;
	
	return vh;
}
int allocSpace(VirtualHeap *vh){
	int retVal = vh->avail;
	
	if(retVal != -1){
		vh->avail = vh->elems[vh->avail].next;
	}
	
	return retVal;
}
void insertFront(VirtualHeap *vh, List *list, Student s){
	List temp = allocSpace(vh);
	
	if(temp != -1){
		vh->elems[temp].elem = s;
		vh->elems[temp].next = *list;
		*list = temp;
	}
}

void displayList(VirtualHeap vh, List list) {
    printf("Displaying List:\n");
    printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
    printf("---------------------------------------------\n");
    while (list != -1) {
        printf("%5d | %4d - %-23s | %d\n", list, vh.elems[list].elem.studID, vh.elems[list].elem.studName, vh.elems[list].next);
        list = vh.elems[list].next;
    }
    printf("---------------------------------------------\n\n");
}


void visualizeSpace(VirtualHeap vh){
	printf("Displaying Virtual Heap:\n");
	int i;
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	for(i = 0; i < MAX; i++){
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0){
			printf("%30s | ", "EMPTY"); 
		} else {
			printf("%4d - %-23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

void deallocSpace(VirtualHeap *vh, int index){
	vh->elems[index].next = vh->avail;
	vh->elems[index].elem = newStudent(0, "", ' ', "");
	vh->avail = index;
}

Student removeStudent(VirtualHeap *vh, List *list, String keyword) {
    Student removedStudent = newStudent(0, "", ' ', "");

    List trav = *list;
    List prev = -1;
    while(trav != -1) {
        if(strcmp(vh->elems[trav].elem.studName, keyword) == 0) {
            removedStudent = vh->elems[trav].elem;
            if(prev == -1) {
                *list = vh->elems[trav].next;
			} else {
                vh->elems[prev].next = vh->elems[trav].next;
			}
            deallocSpace(vh, trav);
            break;
        }

        prev = trav;
        trav = vh->elems[trav].next;
    }

    return removedStudent;
}
