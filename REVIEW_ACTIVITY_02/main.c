// Expected Output:
// 15 10 5
// 15 10 5 20 25
// 15 10 7 5 20 25
// Element 20 found in the list
// Element 20 is at location 4
// 10 7 5 20 25
// 10 7 5 20
// 10 7 20
// 10 20
// 20
// 10 20 30 50 60

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char *argv[]) {
    // Create a new list
    List myList;
    initList(&myList);

    // Insert elements at the front
    insertFront(&myList, 5);
    insertFront(&myList, 10);
    insertFront(&myList, 15);

    // Display the list
    displayList(myList);

    // Insert elements at the rear
    insertRear(&myList, 20);
    insertRear(&myList, 25);

    // Display the list
    displayList(myList);

    // Insert an element at a specified location
    insertAt(&myList, 7, 2);

    // Display the list
    displayList(myList);

    // Search for an element
    int key = 20;
    if (searchItem(myList, key)) {
        printf("Element %d found in the list\n", key);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    // Get the location of an element
    printf("Element %d is at location %d\n", key, getItem(myList, key));

    // Delete the front element
    deleteFront(&myList);

    // Display the list
    displayList(myList);

    // Delete the rear element
    deleteRear(&myList);

    // Display the list
    displayList(myList);

    // Delete an element at a specific location
    deleteAt(&myList, 2);

    // Display the list
    displayList(myList);

    // Delete a specific item
    deleteItem(&myList, 7);

    // Display the list
    displayList(myList);

    // Delete all occurrences of a specific item
    deleteAllItem(&myList, 10);

    // Display the list
    displayList(myList);

    // Insert elements in sorted order
    insertSorted(&myList, 50);
    insertSorted(&myList, 60);
    insertSorted(&myList, 10);
    insertSorted(&myList, 30);

    // Display the sorted list
    displayList(myList);

	// Free memory used by the list
	clearList(&myList);


    return 0;
}
