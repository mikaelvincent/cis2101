// Expected Output:
// 10 20 30
// 5 10 20 30
// 5 10 15 20 30
// Item 20 found
// Item 15 is at index: 2
// 5 10 15 30
// 10 15 30
// 10 15
// 10
// 10 25
// 10

#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h" // "StaticArray.h" or "DynamicArray.h"

int main(int argc, char *argv[]) {
    printf("Dynamic Arrray:\n");
	List list = newList(5);

    // Insert elements at the rear of the list
    insertRear(&list, 10);
    insertRear(&list, 20);
    insertRear(&list, 30);
    displayList(list);

    // Insert an element at the front of the list
    insertFront(&list, 5);
    displayList(list);

    // Insert an element at a specific position
    insertAt(&list, 15, 2);
    displayList(list);

    // Search for an item
    if(searchItem(list, 20)){
        printf("Item 20 found\n");
    } else {
        printf("Item 20 not found\n");
    }

    // Get an item's index
    int index = getItem(list, 15);
    printf("Item 15 is at index: %d\n", index);

    // Delete an item
    deleteItem(&list, 20);
    displayList(list);

    // Delete the front item
    deleteFront(&list);
    displayList(list);

    // Delete the rear item
    deleteRear(&list);
    displayList(list);

    // Delete an item at a specific position
    deleteAt(&list, 1);
    displayList(list);

    // Insert an item into the sorted position
    insertSorted(&list, 25);
    displayList(list);

    // Delete all instances of an item
    insertRear(&list, 25);
    insertRear(&list, 25);
    deleteAllItem(&list, 25);
    displayList(list);

	// Delete list by setting it to an empty state (if static)
	// Delete list and deallocate memory (if dynamic)
	deleteList(&list);

    return 0;
}
