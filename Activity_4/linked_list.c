// Expected Output:

// Is the stack empty? Yes
// Trying to pop from the empty stack...
// Pushing elements to the stack...
// 0 
// 1 0 
// 2 1 0 
// 3 2 1 0 
// 4 3 2 1 0 
// 5 4 3 2 1 0 
// Is the stack full? Yes
// Trying to push to the full stack...
// 5 4 3 2 1 0 
// Top item of the stack: 5
// temp_stack (made using pop/push only): 5 4 3 2 1 0 
// Popping items from the stack...
// 4 3 2 1 0 
// 3 2 1 0 
// 2 1 0 
// 1 0 
// 0 
// Is the stack empty? Yes

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->count = 0;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

int isFull(Stack* stack) {
    return (stack->count == MAX);
}

void push(Stack* stack, Data item) {
    if (isFull(stack)) {
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->count--;
}

Data peek(Stack* stack) {
    if (isEmpty(stack)) {
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

void display(Stack* stack) {
    if (!isEmpty(stack)) {
        Stack temp_stack1;
        initStack(&temp_stack1);
        Stack temp_stack2;
        initStack(&temp_stack2);
        while (!isEmpty(stack)) {
            push(&temp_stack1, peek(stack));
            pop(stack);
        }
        while (!isEmpty(&temp_stack1)) {
            push(&temp_stack2, peek(&temp_stack1));
            pop(&temp_stack1);
        }
        while (!isEmpty(&temp_stack2)) {
            Data item = peek(&temp_stack2);
            printf("%d ", item);
            push(&temp_stack1, item);
            pop(&temp_stack2);
        }
        while (!isEmpty(&temp_stack1)) {
            Data item = peek(&temp_stack1);
            push(stack, item);
            pop(&temp_stack1);
        }
        printf("\n");
    }
}


void visualize(Stack* stack) {
    if (!isEmpty(stack)) {
        Node* temp = stack->top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}