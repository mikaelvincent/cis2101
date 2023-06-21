//Expected Output:

//
// Testing normal insertions into list1:
// Displaying List:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     7 |    3 - Charlie                 | 8   
//     8 |    2 - Bob                     | 9   
//     9 |    1 - Alice                   | -1  
// ---------------------------------------------
//
// Displaying Virtual Heap:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     0 |                          EMPTY | -1  
//     1 |                          EMPTY | 0   
//     2 |                          EMPTY | 1   
//     3 |                          EMPTY | 2   
//     4 |                          EMPTY | 3   
//     5 |                          EMPTY | 4   
//     6 |                          EMPTY | 5   
//     7 |    3 - Charlie                 | 8   
//     8 |    2 - Bob                     | 9   
//     9 |    1 - Alice                   | -1
// ---------------------------------------------
// AVAILABLE: 6
//
//
// Testing normal insertions into list2:
// Displaying List:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     5 |    5 - Eve                     | 6
//     6 |    4 - David                   | -1
// ---------------------------------------------
//
// Displaying Virtual Heap:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     0 |                          EMPTY | -1
//     1 |                          EMPTY | 0
//     2 |                          EMPTY | 1
//     3 |                          EMPTY | 2
//     4 |                          EMPTY | 3
//     5 |    5 - Eve                     | 6
//     6 |    4 - David                   | -1
//     7 |    3 - Charlie                 | 8
//     8 |    2 - Bob                     | 9
//     9 |    1 - Alice                   | -1
// ---------------------------------------------
// AVAILABLE: 4
//
//
// Testing removal of existing student from list1:
// Removed student: 2 - Bob
// Displaying List:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     7 |    3 - Charlie                 | 9
//     9 |    1 - Alice                   | -1
// ---------------------------------------------
//
// Displaying Virtual Heap:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     0 |                          EMPTY | -1
//     1 |                          EMPTY | 0
//     2 |                          EMPTY | 1
//     3 |                          EMPTY | 2
//     4 |                          EMPTY | 3
//     5 |    5 - Eve                     | 6
//     6 |    4 - David                   | -1
//     7 |    3 - Charlie                 | 9
//     8 |                          EMPTY | 4
//     9 |    1 - Alice                   | -1
// ---------------------------------------------
// AVAILABLE: 8
//
//
// Testing removal of existing student from list2:
// Removed student: 4 - David
// Displaying List:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     5 |    5 - Eve                     | -1
// ---------------------------------------------
//
// Displaying Virtual Heap:
// INDEX |                       ELEMENTS | NEXT
// ---------------------------------------------
//     0 |                          EMPTY | -1
//     1 |                          EMPTY | 0
//     2 |                          EMPTY | 1
//     3 |                          EMPTY | 2
//     4 |                          EMPTY | 3
//     5 |    5 - Eve                     | -1
//     6 |                          EMPTY | 8
//     7 |    3 - Charlie                 | 9
//     8 |                          EMPTY | 4
//     9 |    1 - Alice                   | -1
// ---------------------------------------------
// AVAILABLE: 6
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cursor_Based.h"

int main(int argc, char* argv[]) {
    // Create a new virtual heap
    VirtualHeap vh = newVirtualHeap();
    // Initialize two empty lists
    List list1 = -1, list2 = -1;

    // Create some students
    Student s1 = newStudent(1, "Alice", 'F', "CS");
    Student s2 = newStudent(2, "Bob", 'M', "EE");
    Student s3 = newStudent(3, "Charlie", 'M', "ME");
    Student s4 = newStudent(4, "David", 'M', "EE");
    Student s5 = newStudent(5, "Eve", 'F', "CS");

    // Insert the students into the list1
    printf("\nTesting normal insertions into list1:\n");
    insertFront(&vh, &list1, s1);
    insertFront(&vh, &list1, s2);
    insertFront(&vh, &list1, s3);
    displayList(vh, list1);
    visualizeSpace(vh);

    // Insert the students into the list2
    printf("\nTesting normal insertions into list2:\n");
    insertFront(&vh, &list2, s4);
    insertFront(&vh, &list2, s5);
    displayList(vh, list2);
    visualizeSpace(vh);

    // Remove a student from the list1
    printf("\nTesting removal of existing student from list1:\n");
    Student removedStudent = removeStudent(&vh, &list1, "Bob");
    printf("Removed student: %d - %s\n", removedStudent.studID, removedStudent.studName);
    displayList(vh, list1);
    visualizeSpace(vh);

    // Remove a student from the list2
    printf("\nTesting removal of existing student from list2:\n");
    removedStudent = removeStudent(&vh, &list2, "David");
    printf("Removed student: %d - %s\n", removedStudent.studID, removedStudent.studName);
    displayList(vh, list2);
    visualizeSpace(vh);

    return 0;
}
