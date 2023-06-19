#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

HourlyEmployee newEmployee(int id, String name, String gender, float hours) {
    HourlyEmployee he;

    he.idNumber = id;
    strcpy(he.name, name);
    strcpy(he.gender, gender);
    he.totalHoursWorked = hours;

    return he;
}

void displayEmployee(HourlyEmployee he) {
    printf("ID: %d\n", he.idNumber);
    printf("NAME: %s\n", he.name);
    printf("GENDER: %s\n", he.gender);
    printf("HOURS WORKED: %.2f\n", he.totalHoursWorked);
}

int initList(List * list) {
    list -> max = 2;
    list -> employees = (HourlyEmployee * ) malloc(sizeof(HourlyEmployee) * list -> max);
    if (list->employees == NULL) {
        return 0;  // return failure
    }
    list -> count = 0;
    return 1;  // return success
}

int addEmployee(List * list, HourlyEmployee emp) {
    if (list -> count == list -> max) {
        list -> max *= 2;
        list -> employees = (HourlyEmployee * ) realloc(list -> employees, sizeof(HourlyEmployee) * list -> max);
        if (list->employees == NULL) {
            return 0;  // return failure
        }
    }
    list -> employees[(list -> count) ++] = emp;
    return 1;  // return success
}

void displayEmployeeList(List list) {
    int i;
    printf("%10s | %30s | %10s\n", "ID", "NAME", "GENDER");
    for (i = 0; i < list.count; i++) {
        printf("%10d | %30s | %10s\n", list.employees[i].idNumber, list.employees[i].name, list.employees[i].gender);
    }
    printf("END OF LIST\n\n");
}

List getFemaleEmployees(List list) {
    List femaleList;
    initList( & femaleList);
    for (int i = 0; i < list.count; i++) {
        if (strcmp(list.employees[i].gender, "female") == 0) {
            addEmployee( & femaleList, list.employees[i]);
        }
    }
    return femaleList;
}

void freeList(List * list) {
    free(list -> employees);
    list -> employees = NULL;
    list -> count = list -> max = 0;
}