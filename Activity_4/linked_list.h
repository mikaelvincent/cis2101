#ifndef LINKED_LIST_H

#define MAX 6 // Define maximum stack size

typedef int Data;

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int count;
} Stack;

void initStack(Stack * stack);
int isEmpty(Stack * stack);
int isFull(Stack * stack);
void push(Stack * stack, Data item);
void pop(Stack * stack);
Data peek(Stack * stack);
void display(Stack * stack);
void visualize(Stack * stack);

#endif
