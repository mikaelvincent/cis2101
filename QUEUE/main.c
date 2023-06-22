#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

int main(int argc, char *argv[])
{
	Queue myQueue;
	initQueue(&myQueue);
	String menuOptions[10] = { "enqueue",
		"dequeue",
		"isEmpty",
		"isFull",
		"display",
		"visualize",
		"front",
		"removeItem",
		"removeEven",
		"doubleTheValue" };
	int choice;
	int value;
	int i;
	initQueue(&myQueue);

	do {
		system("cls");
		printf("MENU\n");
		for (i = 0; i < 10; ++i)
		{
			printf("[%d] %s\n", i + 1, menuOptions[i]);
		}
		printf("Enter your choice < 0 to EXIT>: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				enqueue(&myQueue, value);
				printf("\n");
				break;
			case 2:
				printf("\n");
				dequeue(&myQueue);
				break;
			case 3:
				printf("\n");
				if (isEmpty(myQueue) == 1)
				{
					printf("Queue is empty.\n\n");
				}
				else
				{
					printf("Queue is not empty.\n\n");
				}
				break;
			case 4:
				printf("\n");
				if (isFull(myQueue) == 1)
				{
					printf("Queue is full.\n\n");
				}
				else
				{
					printf("Queue is not full.\n\n");
				}
				break;
			case 5:
				printf("\n");
				display(myQueue);
				break;
			case 6:
				printf("\n");
				visualize(myQueue);
				break;
			case 7:
				printf("\n");
				printf("Front: %i\n\n", front(myQueue));
				break;
			case 8:
				printf("\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				removeItem(&myQueue, value);
				printf("\n");
				break;
			case 9:
				printf("\n");
				printf("Removed the following elems:\n\n");
				display(removeEven(&myQueue));
				break;
			case 10:
				printf("\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				printf("Elems affected: %i\n", doubleTheValue(&myQueue, value));
				printf("\n");
				break;
			case 0:
				printf("\n");
				printf("Thank you!\n\n");
				break;
			default:
				printf("\n");
				printf("Invalid choice...\n\n");
		}
		system("pause");
	} while (choice != 0);

	printf("\nBye!!\n");
	return 0;
}