// Expected Output:

// Products arranged by expiry date (from earliest to latest):
// 1: Product1, 7-20-2023
// 2: Product2, 8-22-2023
// 4: Product4, 9-30-2023
// 3: Product3, 10-25-2023
// 
// Products with quantity lesser than 15:
// 4: Product4, Quantity: 5
// 1: Product1, Quantity: 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[30];

typedef struct {
	int date;
	int month;
	int year;
} MyDate;

typedef struct {
	int prodID;
	String prodName;
	char category;   // each bit is one category
	int qty;
	MyDate expiryDate;
} Product;

typedef struct {
	Product *prods;
	int top;	
	int max;
} ProductStack;

typedef struct node{
	Product prod;
	struct node *next;
} ProdNode, *ProductList, *ProdPtr;

typedef struct {
	ProdPtr front;
	ProdPtr rear;
} ProductQueue;

MyDate newDate(int month, int date, int year) {
	MyDate d = {date, month, year};
	
	return d;
}

Product newProduct(int id, String name, char category, int qty, MyDate expiry) {
	Product p;
	
	p.prodID = id;
	strcpy(p.prodName, name);
	p.category = category;
	p.qty = qty;
	p.expiryDate = expiry;
	
	return p;
}

ProductStack newProductStackList(int size) {
	ProductStack list;
	
	list.prods = malloc(sizeof(Product) * size);
	list.top = 0;
	list.max = size;
	
	return list;
}

ProductQueue newProductQueue() {
	ProductQueue pq;
	
	pq.front = pq.rear = NULL;
	
	return pq;
}

//create add product that adds all the product in linked list sorted by id
void addProduct(ProductList *list, Product p) {
	ProdPtr newNode = malloc(sizeof(ProdNode));
	newNode->prod = p;
	newNode->next = NULL;

	if (*list == NULL || (*list)->prod.prodID >= newNode->prod.prodID) {
		newNode->next = *list;
		*list = newNode;
	} else {
		ProdPtr current = *list;
		while (current->next != NULL && current->next->prod.prodID < newNode->prod.prodID) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

// Push operation for ProductStack
void push(ProductStack *stack, Product product) {
    if (stack->top == stack->max) {
        printf("Stack Overflow\n");
        return;
    }
    stack->prods[stack->top++] = product;
}

// Pop operation for ProductStack
Product pop(ProductStack *stack) {
    if (stack->top == 0) {
        printf("Stack Underflow\n");
        // Ideally we would handle the underflow situation more gracefully. 
        // Here for simplicity we return an empty product.
        Product emptyProduct;
        return emptyProduct;
    }
    return stack->prods[--stack->top];
}

// Peek operation for ProductStack
Product peek(ProductStack *stack) {
    if (stack->top == 0) {
        printf("Stack is Empty\n");
        // Ideally we would handle the empty stack situation more gracefully. 
        // Here for simplicity we return an empty product.
        Product emptyProduct;
        return emptyProduct;
    }
    return stack->prods[stack->top - 1];
}

ProductStack arrangeByExpiry(ProductList list) {
    ProductStack stack = newProductStackList(100);  // Assuming maximum 100 products for this example
    ProductStack tempStack = newProductStackList(100);  // Temporary stack to hold items while rearranging

    ProdPtr current = list;
    while (current != NULL) {
        Product p = current->prod;

        // If the stack is empty or the new product expires later than the top product in the stack,
        // then push the new product onto the stack.
        if (stack.top == 0 || 
            (stack.prods[stack.top - 1].expiryDate.year < p.expiryDate.year || 
            (stack.prods[stack.top - 1].expiryDate.year == p.expiryDate.year && stack.prods[stack.top - 1].expiryDate.month < p.expiryDate.month) || 
            (stack.prods[stack.top - 1].expiryDate.year == p.expiryDate.year && stack.prods[stack.top - 1].expiryDate.month == p.expiryDate.month && stack.prods[stack.top - 1].expiryDate.date < p.expiryDate.date))) {

            push(&stack, p);
        } else {
            // If the new product expires earlier than the top product in the stack,
            // then pop items from the stack and push onto the tempStack until we find 
            // a product that expires earlier than the new product, then push the new product.
            while(stack.top != 0 && 
                !(stack.prods[stack.top - 1].expiryDate.year < p.expiryDate.year || 
                (stack.prods[stack.top - 1].expiryDate.year == p.expiryDate.year && stack.prods[stack.top - 1].expiryDate.month < p.expiryDate.month) || 
                (stack.prods[stack.top - 1].expiryDate.year == p.expiryDate.year && stack.prods[stack.top - 1].expiryDate.month == p.expiryDate.month && stack.prods[stack.top - 1].expiryDate.date < p.expiryDate.date))) {

                push(&tempStack, pop(&stack));
            }
            push(&stack, p);
            // Pop all items from tempStack back onto the main stack
            while(tempStack.top != 0) {
                push(&stack, pop(&tempStack));
            }
        }

        current = current->next;
    }
    
    return stack;
}

//create a function that removes all product in the queue and returns the removed product into a product linked list where quantity is lesser than the specified value 
ProductList getLessQuantity(ProductQueue *prodQueue, int thresholdQty) {
	ProductList list = NULL;
	
	while (prodQueue->front != NULL) {
		ProdPtr node = prodQueue->front;
		prodQueue->front = node->next;
		
		if (node->prod.qty < thresholdQty) {
			node->next = list;
			list = node;
		} else {
			free(node);
		}
		
		if (prodQueue->front == NULL) {
			prodQueue->rear = NULL;
		}
	}
	
	return list;
}

int main() {
    // Initialize product list
    ProductList productList = NULL;

    // Initialize product queue
    ProductQueue prodQueue = newProductQueue();

    // Creating some sample products
    Product p1 = newProduct(1, "Product1", 'A', 10, newDate(7, 20, 2023));
    Product p2 = newProduct(2, "Product2", 'B', 20, newDate(8, 22, 2023));
    Product p3 = newProduct(3, "Product3", 'C', 15, newDate(10, 25, 2023));
    Product p4 = newProduct(4, "Product4", 'D', 5, newDate(9, 30, 2023));

    // Add these products to the list
    addProduct(&productList, p1);
    addProduct(&productList, p2);
    addProduct(&productList, p3);
    addProduct(&productList, p4);

    // Arrange products by expiry into a stack
    ProductStack stack = arrangeByExpiry(productList);

    printf("Products arranged by expiry date (from earliest to latest):\n");
    int i;
    for(i = 0; i < stack.top; i++) {
        printf("%d: %s, %d-%d-%d\n", stack.prods[i].prodID, stack.prods[i].prodName, 
        stack.prods[i].expiryDate.month, stack.prods[i].expiryDate.date, stack.prods[i].expiryDate.year);
    }

	// Now lets add these products to the queue
	ProdPtr current = productList;
	while(current != NULL) {
	    ProdPtr node = malloc(sizeof(ProdNode));
	    node->prod = current->prod;
	    node->next = NULL;
	
	    if (prodQueue.rear == NULL) {
	        prodQueue.front = prodQueue.rear = node;
	        continue;  // Continue with the next iteration of the loop, not return from the function
	    }
	    prodQueue.rear->next = node;
	    prodQueue.rear = node;
	
	    current = current->next;
	}

    // Extract the products with quantity lesser than 15
    ProductList lessQtyList = getLessQuantity(&prodQueue, 15);
    printf("\nProducts with quantity lesser than 15:\n");
    current = lessQtyList;
    while(current->next != NULL) {
        printf("%d: %s, Quantity: %d\n", current->prod.prodID, current->prod.prodName, current->prod.qty);
        current = current->next;
    }

    return 0;
}