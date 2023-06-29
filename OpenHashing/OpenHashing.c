#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OpenHashing.h"

// Simple polynomial rolling hash function for strings
int hashFunction(char* lastName, int max) {
    int p = 31;
    int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for (char* c=lastName; *c != '\0'; ++c) {
        hash_value = (hash_value + (*c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value % max;
}

Dictionary* initDictionary(int max) {
    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    dict->array = (SType**)calloc(max, sizeof(SType*));
    dict->count = 0;
    dict->max = max;
    return dict;
}

int addStudent(Dictionary* dict, Student s) {
    int index = hashFunction(s.studentName.lastName, dict->max);
    SType* newNode = (SType*)malloc(sizeof(SType));
    newNode->student = s;
    newNode->link = dict->array[index];
    dict->array[index] = newNode;
    dict->count++;
    return index;
}

Student* getStudent(Dictionary* dict, int id) {
    for (int i = 0; i < dict->max; i++) {
        SType* node = dict->array[i];
        while (node != NULL) {
            if (node->student.studentID == id) {
                return &(node->student);
            }
            node = node->link;
        }
    }
    return NULL;
}

int deleteStudent(Dictionary* dict, int id) {
    for (int i = 0; i < dict->max; i++) {
        SType* node = dict->array[i];
        SType* prevNode = NULL;
        while (node != NULL) {
            if (node->student.studentID == id) {
                if (prevNode == NULL) {
                    dict->array[i] = node->link;
                } else {
                    prevNode->link = node->link;
                }
                free(node);
                dict->count--;
                return 1;
            }
            prevNode = node;
            node = node->link;
        }
    }
    return 0;
}

void visualize(Dictionary* dict) {
    for (int i = 0; i < dict->max; i++) {
        printf("Index %d:\n", i);
        SType* node = dict->array[i];
        while (node != NULL) {
            printf("    ID: %d, Name: %s %s %s\n",
                node->student.studentID,
                node->student.studentName.firstName,
                node->student.studentName.middleName,
                node->student.studentName.lastName);
            node = node->link;
        }
    }
}

void clearDictionary(Dictionary* dict) {
    for (int i = 0; i < dict->max; i++) {
        SType* node = dict->array[i];
        while (node != NULL) {
            SType* temp = node;
            node = node->link;
            free(temp);
        }
    }
    free(dict->array);
    free(dict);
}
