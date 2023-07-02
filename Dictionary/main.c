#include <stdio.h>
#include "MyHeader.h"

int main() {
    // Create a new VSpace with a size of 10
    VSpace vs = newVSpace(10);
    
    printf("Created a new VSpace of size 10.\n");

    // Visualize the current state
    visualize(vs);

    // Add some elements to the VSpace
    if (addElement(&vs, 5)) {
        printf("Successfully added 5 to the VSpace.\n");
    } else {
        printf("Failed to add 5 to the VSpace.\n");
    }

    if (addElement(&vs, 7)) {
        printf("Successfully added 7 to the VSpace.\n");
    } else {
        printf("Failed to add 7 to the VSpace.\n");
    }

    // Visualize the current state
    visualize(vs);

    // Try to add an element that already exists
    if (addElement(&vs, 7)) {
        printf("Successfully added 7 to the VSpace.\n");
    } else {
        printf("Failed to add 7 to the VSpace because it already exists.\n");
    }

    // Remove an element from the VSpace
    if (removeElement(&vs, 5)) {
        printf("Successfully removed 5 from the VSpace.\n");
    } else {
        printf("Failed to remove 5 from the VSpace.\n");
    }

    // Visualize the current state
    visualize(vs);

    // Try to remove an element that doesn't exist
    if (removeElement(&vs, 10)) {
        printf("Successfully removed 10 from the VSpace.\n");
    } else {
        printf("Failed to remove 10 from the VSpace because it does not exist.\n");
    }

    // Add more elements to test realloc
    for(int i = 8; i < 20; i++) {
        if (addElement(&vs, i)) {
            printf("Successfully added %d to the VSpace.\n", i);
        } else {
            printf("Failed to add %d to the VSpace.\n", i);
        }
    }

    // Visualize the current state
    visualize(vs);

    return 0;
}
