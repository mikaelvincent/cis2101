#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Activity_7.h"

int main(int argc, char *argv[])
{
	VirtualSpace vs = newVirtualSpace();

	StackList StackLists[MAX];
	initStackLists(StackLists);

	Queue QueueLists[MAX];
	initQueueLists(QueueLists);

	String menuOptions[6] = {"visualizeVirtualSpace",
		"displayList",
		"createQueue",
		"createStack",
		"insertData",
		"deleteData" };

	String insertOptions[2] = {"enqueue",
		"push"};

	String deleteOptions[2] = {"dequeue",
		"pop"};

	int choice;
	int option;
	int i;
	bool response;
	Product newData = newProduct(0, "", 0, 0.0, 0, 0, 0);

	do {
		system("cls");
		printf("MENU\n");
		for (i = 0; i < 6; i++)
		{
			printf("[%d] %s\n", i + 1, menuOptions[i]);
		}

		printf("\n");
		printf("Enter your choice < 0 to EXIT>: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: // visualizeVirtualSpace
				visualizeVirtualSpace(vs);
				break;

			case 2: // displayList
				if (vs.QueueListCount > 0 || vs.StackListCount > 0)
				{
					for(i = 0; i < vs.QueueListCount; i++)
					{
						displayQueueList(vs, QueueLists[i], i);
						printf("\n");
					}
					for(i = 0; i < vs.StackListCount; i++)
					{
						displayStackList(vs, StackLists[i], i);
						printf("\n");
					}
				} else
				{
					system("cls");
					printf("No Lists have been created!\n");
					printf("\n");
					printf("\n");
					system("pause");
				}
				break;

			case 3: // createQueue
				printf("\n");
				response = createQueueList(&vs, QueueLists);
				// print here
				if (response)
				{
					printf("QueueList was successfully created!\n");
				}
				else
				{
					printf("There was an issue with creating the QueueList!\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				break;

			case 4: // createStack
				printf("\n");
				response = createStackList(&vs, StackLists);
				// print here
				if (response)
				{
					printf("StackList was successfully created!\n");
				}
				else
				{
					printf("There was an issue with creating the StackList!\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				break;

			case 5: // insertData
				system("cls");
				int listChoice;
				bool validChoice = true;

				for (i = 0; i < 2; i++)
				{
					printf("[%d] %s\n", i + 1, insertOptions[i]);
				}
				printf("\n");
				printf("Enter your choice: ");
				scanf("%d", &option);
				option = option - 1;

				if ((option == 0 && vs.QueueListCount <= 0) || (option == 1 && vs.StackListCount <= 0)) 
				{
					validChoice = false;
				}

				if (option != 0 && option != 1)
				{
					validChoice = false;
				}

				if (validChoice && option == 0)
				{
					printf("\n");
					for (i = 0; i < vs.QueueListCount; i++)
					{
						printf("queueLists[%i]\n", i);
					}
					printf("\n");
					printf("Enter queueList index to insert in: ");
					scanf("%i", &listChoice);
					if (listChoice < 0 || listChoice >= vs.QueueListCount)
					{
						validChoice = false;
					}
				} else if (validChoice && option == 1)
				{
					printf("\n");
					for (i = 0; i < vs.StackListCount; i++)
					{
						printf("stackLists[%i]\n", i);
					}
					printf("\n");
					printf("Enter stackList index to insert in: ");
					scanf("%i", &listChoice);
					if (listChoice < 0 || listChoice >= vs.StackListCount)
					{
						validChoice = false;
					}
				}

				if (validChoice)
				{
					Product newData;
					printf("\n");
					printf("Enter prodID: ");
					scanf("%i", &newData.prodID);

					printf("Enter prodName: ");
					scanf("%s", newData.prodName);

					printf("Enter prodQty: ");
					scanf("%i", &newData.prodQty);

					printf("Enter prodPrice: ");
					scanf("%lf", &newData.prodPrice);

					printf("Enter prodExp.date: ");
					scanf("%i", &newData.prodExp.date);

					printf("Enter prodExp.month: ");
					scanf("%i", &newData.prodExp.month);

					printf("Enter prodExp.year: ");
					scanf("%i", &newData.prodExp.year);

					if (option == 0)
					{
						response = enqueue(&vs, newData, &QueueLists[listChoice]);
					}
					else
					{
						response = push(&vs, newData, &StackLists[listChoice]);
					}
				}
				else
				{
					response = false;
				}

				printf("\n");
				if (response)
				{
					printf("Product successfully added!\n");
				}
				else
				{
					printf("There was an issue with adding the product!\n");
				}
				printf("\n");
				printf("\n");
				system("pause");
				break;

			case 6: // deleteData
				system("cls");
				validChoice = true;

				for (i = 0; i < 2; i++)
				{
					printf("[%d] %s\n", i + 1, deleteOptions[i]); // assuming deleteOptions[] is defined in your program
				}
				printf("\n");
				printf("Enter your choice: ");
				scanf("%d", &option);
				option = option - 1;

				if ((option == 0 && vs.QueueListCount <= 0) || (option == 1 && vs.StackListCount <= 0)) 
				{
					validChoice = false;
				}

				if (option != 0 && option != 1)
				{
					validChoice = false;
				}

				if (validChoice && option == 0)
				{
					printf("\n");
					for (i = 0; i < vs.QueueListCount; i++)
					{
						printf("queueLists[%i]\n", i);
					}
					printf("\n");
					printf("Enter queueList index to delete from: ");
					scanf("%i", &listChoice);
					if (listChoice < 0 || listChoice >= vs.QueueListCount)
					{
						validChoice = false;
					}
				} else if (validChoice && option == 1)
				{
					printf("\n");
					for (i = 0; i < vs.StackListCount; i++)
					{
						printf("stackLists[%i]\n", i);
					}
					printf("\n");
					printf("Enter stackList index to delete from: ");
					scanf("%i", &listChoice);
					if (listChoice < 0 || listChoice >= vs.StackListCount)
					{
						validChoice = false;
					}
				}
				printf("\n");
				if (validChoice)
				{
					if (option == 0)
					{
						if(isEmptyQueue(QueueLists[listChoice]))
						{
							printf("The selected queue is empty. Nothing to delete.\n");
							validChoice = false;
						}
						else
						{
							dequeue(&vs, &QueueLists[listChoice]);
							printf("Data successfully deleted from queue!\n");
						}
					}
					else
					{
						if(isEmptyStack(StackLists[listChoice]))
						{
							printf("The selected stack is empty. Nothing to delete.\n");
							validChoice = false;
						}
						else
						{
							pop(&vs, &StackLists[listChoice]);
							printf("Data successfully deleted from stack!\n");
						}
					}
				} else
				{
					if (!validChoice)
					{
						printf("There was an issue with deleting the data!\n");
					}
				}
				printf("\n");
				printf("\n");
				system("pause");
				break;

			case 0: // EXIT
				printf("\n");
				printf("Thank you!\n");
				printf("\n");
				printf("\n");
				system("pause");
				break;

			default: // invalid
				printf("\n");
				printf("\n");
				printf("Invalid choice...\n");
				printf("\n");
				printf("\n");
				system("pause");
		}

	} while (choice != 0);

	system("cls");

	return 0;

}