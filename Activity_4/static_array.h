#ifndef STACK_H

#define MAX 6

typedef int Data;

typedef struct {
    Data elems[MAX];
    int top;
}
Stack;

void initStack(Stack * stack);
int isEmpty(Stack * stack);
int isFull(Stack * stack);
void push(Stack * stack, Data item);
void pop(Stack * stack);
Data peek(Stack * stack);
void display(Stack * stack);
void visualize(Stack * stack);

#endif