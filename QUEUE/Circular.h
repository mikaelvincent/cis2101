#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <stdbool.h>
#define MAX 10
#define EMPTY 10000

typedef char String[30];

typedef struct
{
	int elems[MAX];
	int front;
	int rear;
}

Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void visualize(Queue q);
void display(Queue q);
int countQueue(Queue q);
bool removeItem(Queue *q, int item);
Queue removeEven(Queue *q);
int doubleTheValue(Queue *q, int value);

#endif