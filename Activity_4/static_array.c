// Expected Output:

// Is the stack empty? Yes
// Trying to pop from the empty stack...
// Pushing elements to the stack...
// 0
// 0 1
// 0 1 2
// 0 1 2 3
// 0 1 2 3 4
// 0 1 2 3 4 5
// Is the stack full? Yes
// Trying to push to the full stack...
// 0 1 2 3 4 5
// Top item of the stack: 5
// temp_stack (made using pop/push only): 0 1 2 3 4 5
// Popping items from the stack...
// 0 1 2 3 4
// 0 1 2 3
// 0 1 2
// 0 1
// 0
// Is the stack empty? Yes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "static_array.h"

void initStack(Stack * stack) {
    stack -> top = -1;
}

int isEmpty(Stack * stack) {
    if (stack -> top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Stack * stack) {
    if (stack -> top >= MAX - 1) {
        return 1;
    }
    return 0;
}

void push(Stack * stack, Data item) {
    if (!isFull(stack)) {
        stack -> top++;
        stack -> elems[stack -> top] = item;
    }
}

void pop(Stack * stack) {
    if (!isEmpty(stack)) {

        stack -> top--;
    }
}

Data peek(Stack * stack) {
    return stack -> elems[stack -> top];
}

void display(Stack * stack) {
    if (!isEmpty(stack)) {
        Stack temp_stack;
        initStack( & temp_stack);
        int i, temp = stack -> top;
        for (i = 0; i <= temp; i++) {
            push( & temp_stack, peek(stack));
            pop(stack);
        }
        for (i = temp; i >= 0; i--) {
            push(stack, peek( & temp_stack));
            pop( & temp_stack);
            printf("%i ", temp_stack.elems[i]);
        }
    }
    printf("\n");
}

void visualize(Stack * stack) {
    if (!isEmpty(stack)) {
        int i;
        for (i = 0; i <= stack -> top; i++) {
            printf("%i ", stack -> elems[i]);
        }
        printf("\n");
    }
}