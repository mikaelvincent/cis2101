#include <stdio.h>
#include <stdlib.h>
#include "static_array.h" // "static_array.h" or "linked_list.h"

int main() {

    Stack stack;

    // initialize the stack
    initStack(&stack);

    // check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    // try to pop from empty stack
    printf("Trying to pop from the empty stack...\n");
    pop(&stack);
    
    // push elements to the stack
    printf("Pushing elements to the stack...\n");
    for (int i = 0; i < MAX; i++) {
        push(&stack, i);
        visualize(&stack);
    }

    // check if the stack is full
    printf("Is the stack full? %s\n", isFull(&stack) ? "Yes" : "No");

    // try to push when the stack is full
    printf("Trying to push to the full stack...\n");
    push(&stack, MAX);
    visualize(&stack);

    // peek at the top item
    printf("Top item of the stack: %d\n", peek(&stack));

    // visualizing temp_stack using pop/pull operations only *
    printf("temp_stack (made using pop/push only): ");
    display(&stack);

    // pop items from the stack
    printf("Popping items from the stack...\n");
    while (!isEmpty(&stack)) {
        pop(&stack);
        visualize(&stack);
    }

    // check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
