#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Activity_7.h"

VirtualSpace newVirtualSpace()
{
	VirtualSpace vs;

	int i;

	for (i = 0; i < MAX; i++)
	{
		vs.data[i].items = newProduct(0, "", 0, 0.0, 0, 0, 0);
		vs.data[i].link = -2;
	}

	vs.avail = 0;
	vs.StackListCount = 0;
	vs.QueueListCount = 0;

	return vs;

}

Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, int date, int month, int year)
{
	Product p;

	p.prodID = prodID;
	strcpy(p.prodName, prodName);
	p.prodQty = prodQty;
	p.prodPrice = prodPrice;
	p.prodExp = newDate(date, month, year);

	return p;

}

Date newDate(int date, int month, int year)
{
	Date d;

	d.date = date;
	d.month = month;
	d.year = year;

	return d;

}

void visualizeVirtualSpace(VirtualSpace vs)
{
	system("cls");
	printf("Displaying Virtual Space:\n");
	printf("\n");
	printf("%10s | %10s | %10s | %30s | %10s | %10s | %10s\n", "index", "link", "prodID", "prodName", "prodQty", "prodPrice", "prodExp");
	printf("------------------------------------------------------------------------------------------------------------\n");
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("%10d | ", i);
		printf("%10d | ", vs.data[i].link);
		printf("%10d | ", vs.data[i].items.prodID);
		printf("%30s | ", vs.data[i].items.prodName);
		printf("%10d | ", vs.data[i].items.prodQty);
		printf("%10.2f | ", vs.data[i].items.prodPrice);
		printf("%.2d-%.2d-%.4d\n", vs.data[i].items.prodExp.date, vs.data[i].items.prodExp.month, vs.data[i].items.prodExp.year);
	}

	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("avail: %d\n\n", vs.avail);
	printf("\n");
	system("pause");

}

void initStackLists(StackList *StackLists)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		*(StackLists + i) = -3;
	}
}

void initQueueLists(Queue QueueLists[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		QueueLists[i].front = -3;
		QueueLists[i].rear = -3;
	}
}

bool activateStackList(VirtualSpace *vs, StackList *stack)
{
	if (vs->StackListCount < MAX)
	{
		*stack = -1;
		vs->StackListCount = vs->StackListCount + 1;

		return true;
	}

	return false;

}

bool activateQueueList(VirtualSpace *vs, Queue *queue)
{
	if (vs->QueueListCount < MAX)
	{
		queue->front = -1;
		queue->rear = -1;
		vs->QueueListCount = vs->QueueListCount + 1;

		return true;
	}

	return false;

}

bool createStackList(VirtualSpace *vs, StackList *StackLists)
{
	int i = vs->StackListCount;
	return activateStackList(vs, (StackLists + i));

}

bool createQueueList(VirtualSpace *vs, Queue *QueueLists)
{
	int i = vs->QueueListCount;
	return activateQueueList(vs, (QueueLists + i));

}

void displayQueueList(VirtualSpace vs, Queue queue, int QueueCount)
{

	system("cls");

	if (isEmptyQueue(queue))
	{
		printf("QueueLists[%i] is EMPTY!\n", QueueCount);
	} else
	{
		printf("Displaying QueueLists[%i]:\n", QueueCount);
		printf("\n");

		printf("%10s | %10s | %10s | %30s | %10s | %10s | %10s\n", "index", "link", "prodID", "prodName", "prodQty", "prodPrice", "prodExp");
		printf("------------------------------------------------------------------------------------------------------------\n");

		while (queue.front != queue.rear)
		{
			printf("%10d | ", queue.front);
			printf("%10d | ", vs.data[queue.front].link);
			printf("%10d | ", vs.data[queue.front].items.prodID);
			printf("%30s | ", vs.data[queue.front].items.prodName);
			printf("%10d | ", vs.data[queue.front].items.prodQty);
			printf("%10.2f | ", vs.data[queue.front].items.prodPrice);
			printf("%.2d-%.2d-%.4d\n", vs.data[queue.front].items.prodExp.date, vs.data[queue.front].items.prodExp.month, vs.data[queue.front].items.prodExp.year);
			if (queue.front != queue.rear)
			{
				queue.front = vs.data[queue.front].link;
			}
		}

		printf("%10d | ", queue.front);
		printf("%10d | ", vs.data[queue.front].link);
		printf("%10d | ", vs.data[queue.front].items.prodID);
		printf("%30s | ", vs.data[queue.front].items.prodName);
		printf("%10d | ", vs.data[queue.front].items.prodQty);
		printf("%10.2f | ", vs.data[queue.front].items.prodPrice);
		printf("%.2d-%.2d-%.4d\n", vs.data[queue.front].items.prodExp.date, vs.data[queue.front].items.prodExp.month, vs.data[queue.front].items.prodExp.year);

		printf("------------------------------------------------------------------------------------------------------------\n");
	
	}

	printf("\n");
	printf("\n");
	system("pause");

}

void displayStackList(VirtualSpace vs, StackList stack, int StackCount)
{

	system("cls");

	if (isEmptyStack(stack))
	{
		printf("StackLists[%i] is EMPTY!\n", StackCount);
	} else
	{
		printf("Displaying StackLists[%i]:\n", StackCount);
		printf("\n");

		printf("%10s | %10s | %10s | %30s | %10s | %10s | %10s\n", "index", "link", "prodID", "prodName", "prodQty", "prodPrice", "prodExp");
		printf("------------------------------------------------------------------------------------------------------------\n");

		while (stack >= 0)
		{
			printf("%10d | ", stack);
			printf("%10d | ", vs.data[stack].link);
			printf("%10d | ", vs.data[stack].items.prodID);
			printf("%30s | ", vs.data[stack].items.prodName);
			printf("%10d | ", vs.data[stack].items.prodQty);
			printf("%10.2f | ", vs.data[stack].items.prodPrice);
			printf("%.2d-%.2d-%.4d\n", vs.data[stack].items.prodExp.date, vs.data[stack].items.prodExp.month, vs.data[stack].items.prodExp.year);

			stack = vs.data[stack].link;
		}

		printf("------------------------------------------------------------------------------------------------------------\n");

	}

	printf("\n");
	printf("\n");
	system("pause");

}

bool isEmptyQueue(Queue queue)
{
	return queue.front < 0 || queue.rear < 0;
}

bool isEmptyStack(StackList stack)
{
	if (stack < 0)
	{
		return true;
	}
	return false;
}

void deallocSpace(VirtualSpace *vs, int index)
{

	vs->data[index].items = newProduct(0, "", 0, 0.0, 0, 0, 0);
	vs->data[index].link = -2;
	vs->avail = index;

}

int allocSpace(VirtualSpace *vs)
{

	int index = -3;
	int i;

	if(vs->avail >= 0)
	{
		index = vs->avail;
		
		for (i = vs->avail; i < MAX - 1; i++)
		{
			vs->avail = (vs->avail + 1) % MAX;
			if (vs->data[vs->avail].link == -2)
			{
				return index; // returns index (available for use) and sets avail to another available index
			}
		}
		vs->avail = -3;
		return index; // returns index (available for use) but sets avail to -3 (full)

	} else
	{
		for (i = 0; i < MAX - 1; i++)
		{
			vs->avail = (vs->avail + 1) % MAX;
			if (vs->data[vs->avail].link == -2)
			{
				index = vs->avail;
				return index; // returns index (available for use) and sets avail to another available index
			}
		}
		vs->avail = -3;
		return index; // returns -3 as index (no available) and sets avail to -3 (full)
	}

}

bool enqueue(VirtualSpace *vs, Product data, Queue *q)
{
	int index = allocSpace(vs);

	if (index >= 0)
	{
		vs->data[index].items = data;
		vs->data[index].link = q->front;

		q->front = index;
		if (q->rear == -1)
		{
			q->rear = index;
			vs->data[index].link = -1;
		}
		return true;
	}
	return false;
}

bool push(VirtualSpace *vs, Product data, StackList *s)
{
    int index = allocSpace(vs);

    if (index >= 0)
    {
        vs->data[index].items = data;
        vs->data[index].link = *s;

        *s = index;
        return true;
    }
    return false;
}

void pop(VirtualSpace *vs, StackList *s)
{
    if (*s < 0)
    {
        printf("The stack is empty. Nothing to pop.\n");
        return;
    }

    int toPop = *s;
    *s = vs->data[*s].link;
    deallocSpace(vs, toPop);
}

void dequeue(VirtualSpace *vs, Queue *q)
{
    // if the queue has only one element
    if (q->front == q->rear)
    {
        deallocSpace(vs, q->front);
        q->front = q->rear = -1;
        return;
    }

    // find the index of the item before the rear
    int beforeRear = q->front;
    while (vs->data[beforeRear].link != q->rear)
    {
        beforeRear = vs->data[beforeRear].link;
    }

    // deallocate the rear item
    deallocSpace(vs, q->rear);

    // update the rear pointer and the link of the new rear item
    q->rear = beforeRear;
    vs->data[beforeRear].link = -1;
}