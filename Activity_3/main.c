#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

int main() {
    // Create a List
    List empList;
    if(!initList(&empList)) {
        printf("Failed to initialize list. Exiting.\n");
        return -1;
    }

    // Create Employees
    HourlyEmployee emp1 = newEmployee(1, "John Doe", "male", 40.0);
    HourlyEmployee emp2 = newEmployee(2, "Jane Doe", "female", 45.0);
    HourlyEmployee emp3 = newEmployee(3, "Alice", "female", 38.5);

    // Display Individual Employees
    printf("Individual Employee Details:\n");
    displayEmployee(emp1);
    displayEmployee(emp2);
    displayEmployee(emp3);
    printf("\n");

    // Add Employees to the List
    if (!addEmployee(&empList, emp1) || !addEmployee(&empList, emp2) || !addEmployee(&empList, emp3)) {
        printf("Failed to add employees. Exiting.\n");
        freeList(&empList);
        return -1;
    }

    // Display the Employee List
    printf("Employee List:\n");
    displayEmployeeList(empList);
    printf("\n");

    // Display the Female Employee List
    printf("Female Employee List:\n");
    List femaleList;
    if (!initList(&femaleList)) {
        printf("Failed to initialize female list. Exiting.\n");
        freeList(&empList);
        return -1;
    }

    femaleList = getFemaleEmployees(empList);
    displayEmployeeList(femaleList);
    printf("\n");

    // Free the Lists
    freeList(&empList);
    freeList(&femaleList);

    return 0;
}
