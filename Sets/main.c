// Expected Output:

// Adding elements to set a:
// true
// true
// true
// true
// true
// true
// true
// true
// true
// true
// 
// Adding elements to set b:
// true
// true
// true
// true
// true
// true
// true
// true
// true
// true
//
// Adding invalid elements to set a:
// false
// false
// false
//
// Displaying set a:
// 0 2 4 6 8 10 12 14 16 18
//
// Displaying set b:
// 1 3 5 7 9 11 13 15 17 19
//
// Removing elements from set a:
// true
// true
// true
// true
// true
//
// Removing elements from set b:
// true
// true
// true
// true
// true
//
// Displaying set a:
// 0 4 8 12 16
//
// Displaying set b:
// 1 5 9 13 17
//
// Removing invalid elements form set a:
// false
// false
// false
//
// Displaying set a:
// 0 4 8 12 16
//
// Adding elements to set a:
// true
// true
// true
//
// Displaying set a:
// 0 1 4 5 8 9 12 16 
//
// Displaying set b:
// 1 5 9 13 17
//
// Displaying union of set a and b:
// 0 1 4 5 8 9 12 13 16 17
//
// Displaying intersection of set a and b:
// 1 5 9
//
// Displaying difference of set a and b:
// 0 4 8 12 16 
//
// Displaying symmetric difference of set a and b:
// 0 4 8 12 13 16 17 
//
// Displaying cardinality of set a: 8
// Displaying cardinality of set b: 5

#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

int main(int argc, char *argv[]) {
	
	system("cls");

	Set a = newSet();
	Set b = newSet();
	
	String boolean[2] = {"false",
		"true"};
	
	printf("Adding elements to set a:\n");
	printf("%s\n", boolean[addElement(&a, 0)]);
	printf("%s\n", boolean[addElement(&a, 2)]);
	printf("%s\n", boolean[addElement(&a, 4)]);
	printf("%s\n", boolean[addElement(&a, 6)]);
	printf("%s\n", boolean[addElement(&a, 8)]);
	printf("%s\n", boolean[addElement(&a, 10)]);
	printf("%s\n", boolean[addElement(&a, 12)]);
	printf("%s\n", boolean[addElement(&a, 14)]);
	printf("%s\n", boolean[addElement(&a, 16)]);
	printf("%s\n", boolean[addElement(&a, 18)]);
	
	printf("\n");
	
	printf("Adding elements to set b:\n");
	printf("%s\n", boolean[addElement(&b, 1)]);
	printf("%s\n", boolean[addElement(&b, 3)]);
	printf("%s\n", boolean[addElement(&b, 5)]);
	printf("%s\n", boolean[addElement(&b, 7)]);
	printf("%s\n", boolean[addElement(&b, 9)]);
	printf("%s\n", boolean[addElement(&b, 11)]);
	printf("%s\n", boolean[addElement(&b, 13)]);
	printf("%s\n", boolean[addElement(&b, 15)]);
	printf("%s\n", boolean[addElement(&b, 17)]);
	printf("%s\n", boolean[addElement(&b, 19)]);
	
	printf("\n");
	
	printf("Adding invalid elements to set a:\n");
	printf("%s\n", boolean[addElement(&a, 20)]);
	printf("%s\n", boolean[addElement(&a, 100)]);
	printf("%s\n", boolean[addElement(&a, -100)]);
	
	printf("\n");
	
	printf("Displaying set a:\n");
	displaySet(a);
	printf("\n");

	printf("\n");
	
	printf("Displaying set b:\n");
	displaySet(b);
	printf("\n");
	
	printf("\n");
	
	printf("Removing elements from set a:\n");
	printf("%s\n", boolean[removeElement(&a, 2)]);
	printf("%s\n", boolean[removeElement(&a, 6)]);
	printf("%s\n", boolean[removeElement(&a, 10)]);
	printf("%s\n", boolean[removeElement(&a, 14)]);
	printf("%s\n", boolean[removeElement(&a, 18)]);
	
	printf("\n");
	
	printf("Removing elements from set b:\n");
	printf("%s\n", boolean[removeElement(&b, 3)]);
	printf("%s\n", boolean[removeElement(&b, 7)]);
	printf("%s\n", boolean[removeElement(&b, 11)]);
	printf("%s\n", boolean[removeElement(&b, 15)]);
	printf("%s\n", boolean[removeElement(&b, 19)]);
	
	printf("\n");
	
	printf("Displaying set a:\n");
	displaySet(a);
	printf("\n");
	
	printf("\n");
	
	printf("Displaying set b:\n");
	displaySet(b);
	printf("\n");
	
	printf("\n");
	
	printf("Removing invalid elements form set a:\n");
	printf("%s\n", boolean[removeElement(&a, 20)]);
	printf("%s\n", boolean[removeElement(&a, 100)]);
	printf("%s\n", boolean[removeElement(&a, -100)]);
	
	printf("\n");
	
	printf("Displaying set a:\n");
	displaySet(a);
	printf("\n");
	
	printf("\n");
	
	printf("Adding elements to set a:\n");
	printf("%s\n", boolean[addElement(&a, 1)]);
	printf("%s\n", boolean[addElement(&a, 5)]);
	printf("%s\n", boolean[addElement(&a, 9)]);
	
	printf("\n");
	
	printf("Displaying set a:\n");
	displaySet(a);
	printf("\n");
	
	printf("\n");
	
	printf("Displaying set b:\n");
	displaySet(b);
	printf("\n");
	
	printf("\n");
	
	printf("Displaying union of set a and b:\n");
	displaySet(unionSet(a, b));
	printf("\n");
	
	printf("\n");
	
	printf("Displaying intersection of set a and b:\n");
	displaySet(intersectionSet(a, b));
	printf("\n");
	
	printf("\n");
	
	printf("Displaying difference of set a and b:\n");
	displaySet(differenceSet(a, b));
	printf("\n");
	
	printf("\n");
	
	printf("Displaying symmetric difference of set a and b:\n");
	displaySet(symmetricDiffSet(a, b));
	printf("\n");
	
	printf("\n");
	
	printf("Displaying cardinality of set a: %i\n", cardinality(a));
	printf("Displaying cardinality of set b: %i\n", cardinality(b));
	
	printf("\n");
	
	return 0;
}
