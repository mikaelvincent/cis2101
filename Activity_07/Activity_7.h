#ifndef ACTIVITY_7_H

#define ACTIVITY_7_H
#define MAX 20

typedef char String[30];

typedef struct
{
	int date;
	int month;
	int year;
}
Date;

typedef struct
{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
}
Product;

typedef struct
{
	Product items;
	int link;
}
SType;

typedef struct
{
	SType data[MAX];
	int avail;
	int StackListCount;
	int QueueListCount;
}
VirtualSpace;

typedef int StackList;

typedef struct
{
	int front;
	int rear;
}
Queue;

VirtualSpace newVirtualSpace();
Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, int date, int month, int year);
Date newDate(int date, int month, int year);
int allocSpace(VirtualSpace *vs);
void deallocSpace(VirtualSpace *vs, int index);
void visualizeVirtualSpace(VirtualSpace vh);
void initStackLists(StackList *StackLists);
void initQueueLists(Queue *QueueLists);
bool activateStackList(VirtualSpace *vs, StackList *stack);
bool activateQueueList(VirtualSpace *vs, Queue *queue);
bool createStackList(VirtualSpace *vs, StackList *StackLists);
bool createQueueList(VirtualSpace *vs, Queue *QueueLists);
void displayQueueList(VirtualSpace vs, Queue queue, int QueueCount);
void displayStackList(VirtualSpace vs, StackList stack, int StackCount);
bool isEmptyQueue(Queue queue);
bool isEmptyStack(StackList stack);
bool enqueue(VirtualSpace *vs, Product data, Queue *q);
void dequeue(VirtualSpace *vs, Queue *q);
bool push(VirtualSpace *vs, Product data, StackList *s);
void pop(VirtualSpace *vs, StackList *s);

#endif