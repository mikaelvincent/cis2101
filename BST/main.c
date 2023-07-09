#include <stdio.h>
#include "MyHeader.h"

int main() {
    BST *list;
    initBST(&list);

    // Create some products
    Product prod1 = createProduct(101, "Product 1", 50, 9.99);
    Product prod2 = createProduct(102, "Product 2", 30, 19.99);
    Product prod3 = createProduct(103, "Product 3", 40, 14.99);
    Product prod4 = createProduct(104, "Product 4", 70, 29.99);
    Product prod5 = createProduct(105, "Product 5", 60, 39.99);

	// Test the insertBST function
	insertBST(&list, prod1);
	// Add other products using addElement function
	addElement(&list, prod2);
	addElement(&list, prod3);
	addElement(&list, prod4);
	addElement(&list, prod5);

    // Display BST using inorder traversal
    printf("Inorder traversal of the BST:\n");
    inorderBST(list);

    // Test isMember function
    printf("Is 102 in the BST? %s\n", isMember(list, 102) ? "Yes" : "No");
    printf("Is 106 in the BST? %s\n", isMember(list, 106) ? "Yes" : "No");

    // Test max and min functions
    NodeType *maxNode = max(list);
    NodeType *minNode = min(list);
    printf("Max node: ");
    displayProduct(maxNode->data);
    printf("Min node: ");
    displayProduct(minNode->data);

    // Test removeElement function
    printf("Removing element 103 (iterative method):\n");
    removeElement(&list, 103);
    inorderBST(list);

    // Test deleteElement function
    printf("Deleting element 102 (recursive method):\n");
    deleteElement(list, 102);
    inorderBST(list);

    return 0;
}
