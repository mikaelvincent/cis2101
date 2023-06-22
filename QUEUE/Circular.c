#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

void initQueue(Queue *q)
{
	q->front = 7;
	q->rear = 6;

	int i;
	for (i = 0; i < MAX; i++)
	{
		q->elems[i] = EMPTY;
	}
}

void enqueue(Queue *q, int item)
{
	if (!isFull(*q))
	{
		q->rear = (q->rear + 1) % MAX;
		q->elems[q->rear] = item;
	}
}

void dequeue(Queue *q)
{
	if (!isEmpty(*q))
	{
		q->elems[q->front] = EMPTY;
		q->front = (q->front + 1) % MAX;
	}
}

int front(Queue q)
{
	if (!isEmpty(q))
	{
		return q.elems[q.front];
	}
	return EMPTY;
}

bool isEmpty(Queue q)
{
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q)
{
	return (q.rear + 2) % MAX == q.front;
}

void visualize(Queue q)
{
	int i;
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("------------------------\n");
	for (i = 0; i < MAX; ++i)
	{
		printf("%5d | ", i);
		if (q.elems[i] != EMPTY)
		{
			printf("%5d | ", q.elems[i]);
		}
		else
		{
			printf("%5s | ", "EMPTY");
		}
		if (i == q.front)
		{
			printf("FRONT ");
		}
		if (i == q.rear)
		{
			printf("REAR");
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void display(Queue q)
{
	printf("Queue: ");
	if (!isEmpty(q))
	{
		int i = q.front;
		do { 	printf("%d ", q.elems[i]);
			i = (i + 1) % MAX;
		} while (i != (q.rear + 1) % MAX);
	}
	else
	{
		printf("The queue is empty!");
	}
	printf("\n");
}

int countQueue(Queue q)
{
	if (isEmpty(q))
	{
		return 0;
	}
	else if (isFull(q))
	{
		return MAX - 1;
	}
	else
	{
		if (q.rear >= q.front)
		{
			return q.rear - q.front + 1;
		}
		else
		{
			return MAX - q.front + q.rear + 1;
		}
	}
}

bool removeItem(Queue *q, int item)
{
	if (isEmpty(*q))
	{
		return false;
	}

	int size = countQueue(*q);
	bool found = false;

	for (int i = 0; i < size; ++i)
	{
		int val = front(*q);
		dequeue(q);

		if (val == item && !found)
		{
			found = true;
		}
		else
		{
			enqueue(q, val);
		}
	}

	return found;
}

Queue removeEven(Queue *q)
{
	Queue removedEven;
	initQueue(&removedEven);
	int size = countQueue(*q);
	for (int i = 0; i < size; ++i)
	{
		int val = front(*q);
		dequeue(q);
		if (val % 2 == 0)
		{
			enqueue(&removedEven, val);
		}
		else
		{
			enqueue(q, val);
		}
	}

	return removedEven;
}

int doubleTheValue(Queue *q, int value)
{
	if (isEmpty(*q))
	{
		return 0;
	}

	int size = countQueue(*q);
	int replacements = 0;

	for (int i = 0; i < size; ++i)
	{
		int val = front(*q);
		dequeue(q);
		if (val % value == 0)
		{
			enqueue(q, 2 *val);
			replacements++;
		}
		else
		{
			enqueue(q, val);
		}
	}

	return replacements;
}