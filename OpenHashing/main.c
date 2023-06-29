#include <stdio.h>
#include "OpenHashing.h"

int main() {
    // Initializing a dictionary with a max size of 10
    Dictionary* dict = initDictionary(10);

    // Test empty dictionary deletion
    printf("\n*** Test empty dictionary deletion ***\n");
    int deleteResult = deleteStudent(dict, 2);
    if (deleteResult) {
        printf("Deletion in an empty dictionary succeeded.\n");
    } else {
        printf("Deletion in an empty dictionary failed as expected.\n");
    }

    // Test students addition
    printf("\n*** Test students addition ***\n");
    Student s1 = {1, {"John", "Doe", "Smith"}, 'M', {"20", "01", "2000"}};
    Student s2 = {2, {"Jane", "Alice", "Johnson"}, 'F', {"10", "02", "1999"}};
    Student s3 = {3, {"Robert", "Lee", "Miller"}, 'M', {"15", "03", "2001"}};
    Student s4 = {1, {"Duplicate", "ID", "Test"}, 'M', {"01", "01", "2001"}};

    addStudent(dict, s1);
    addStudent(dict, s2);
    addStudent(dict, s3);
    // Adding a student with the same ID
    addStudent(dict, s4);
    
    visualize(dict);

    // Test student retrieval
    printf("\n*** Test student retrieval ***\n");
    Student* s = getStudent(dict, 2);
    if (s != NULL) {
        printf("Found student with ID 2: %s %s %s\n", s->studentName.firstName, s->studentName.middleName, s->studentName.lastName);
    } else {
        printf("Student with ID 2 not found\n");
    }

    // Test non-existing student deletion
    printf("\n*** Test non-existing student deletion ***\n");
    deleteResult = deleteStudent(dict, 5);
    if (deleteResult) {
        printf("Deletion of non-existing student succeeded.\n");
    } else {
        printf("Deletion of non-existing student failed as expected.\n");
    }

    // Test existing student deletion
    printf("\n*** Test existing student deletion ***\n");
    deleteResult = deleteStudent(dict, 2);
    if (deleteResult) {
        printf("Deletion of existing student succeeded.\n");
    } else {
        printf("Deletion of existing student failed.\n");
    }

    visualize(dict);

    // Test deleted student retrieval
    printf("\n*** Test deleted student retrieval ***\n");
    s = getStudent(dict, 2);
    if (s != NULL) {
        printf("Found student with ID 2: %s %s %s\n", s->studentName.firstName, s->studentName.middleName, s->studentName.lastName);
    } else {
        printf("Student with ID 2 not found\n");
    }

    // Test dictionary clearance
    printf("\n*** Test dictionary clearance ***\n");
    clearDictionary(dict);
    printf("Dictionary cleared successfully.\n");

    return 0;
}
