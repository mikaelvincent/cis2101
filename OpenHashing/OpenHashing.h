#ifndef OPEN_HASHING_H
#define OPEN_HASHING_H

typedef struct {
    char* date;
    char* month;
    char* year;
} Date;

typedef struct {
    char* firstName;
    char* middleName;
    char* lastName;
} Name;

typedef struct Student {
    int studentID;
    Name studentName;
    char studentSex;
    Date studentBirthdate;
} Student;

typedef struct SType {
    Student student;
    struct SType* link;
} SType;

typedef struct {
    SType** array;
    int count;
    int max;
} Dictionary;

// Function Prototypes
Dictionary* initDictionary(int max);
int hashFunction(char* lastName, int max);
int addStudent(Dictionary* dict, Student s);
Student* getStudent(Dictionary* dict, int id);
int deleteStudent(Dictionary* dict, int id);
void visualize(Dictionary* dict);
void clearDictionary(Dictionary* dict);

#endif //OPEN_HASHING_H
