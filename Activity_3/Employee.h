#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef char String[30];

typedef struct {
    int idNumber;
    String name;
    String gender;
    float totalHoursWorked;
}
HourlyEmployee, * EmployeeList;

typedef struct {
    EmployeeList employees;
    int count;
    int max;
}
List;

HourlyEmployee newEmployee(int id, String name, String gender, float hours);
void displayEmployee(HourlyEmployee he);
int initList(List * list);
int addEmployee(List * list, HourlyEmployee emp);
void displayEmployeeList(List list);
List getFemaleEmployees(List list);
void freeList(List * list);

#endif