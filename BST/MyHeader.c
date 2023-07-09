#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyHeader.h"

//using recursive method
void addElement(BST **list, Product item)
{	
	if(isEmpty(*list))
	{
		BST *newProd = malloc(sizeof(BST));
		newProd->data = item;
		newProd->left = NULL;
		newProd->right = NULL;
		*list = newProd;
	} else if((*list)->data.prodID > item.prodID)
	{
		addElement(&(*list)->left, item);
	} else if((*list)->data.prodID < item.prodID)
	{
		addElement(&(*list)->right, item);
	}
	
}

// using iterative method
void insertBST(BSTPtr *list, Product item)
{
	BST *newProd = malloc(sizeof(BST));
	newProd->data = item;
	newProd->left = NULL;
	newProd->right = NULL;
	
	if(isEmpty(*list))
	{
		*list = newProd;
		return;
	}
	
	NodeType *current = *list;
	bool isInserted = false;
	
	while(!isInserted)
	{
		if(newProd->data.prodID < current->data.prodID)
		{
			if (current->left == NULL)
			{
				current->left = newProd;
				isInserted = true;
			} else
			{
				current = current->left;
			}
		} else if(newProd->data.prodID > current->data.prodID)
		{
			if (current->right == NULL)
			{
				current->right = newProd;
				isInserted = true;
			} else
			{
				current = current->right;
			}
		} else if(newProd->data.prodID == current->data.prodID)
		{
			isInserted = true;
			free(newProd);
			printf("A product with same ID already exists! Insert not completed.\n");
		}
	}

}

// using iterative method
void removeElement(BST **list, int prodID)
{
    if (isEmpty(*list)) return;

    NodeType *parent = NULL;
    NodeType *current = *list;

    while (current != NULL)
    {
        if (prodID == current->data.prodID)
            break;
        parent = current;
        current = prodID < current->data.prodID ? current->left : current->right;
    }

    if (current == NULL) return;

    if (current->left != NULL && current->right != NULL) 
    {
        NodeType *successor = current->right;
        parent = current;

        while (successor->left != NULL)
        {
            parent = successor;
            successor = successor->left;
        }

        current->data = successor->data;
        current = successor;
    }

    NodeType *child = current->left != NULL ? current->left : current->right;

    if (parent == NULL)
    {
        *list = child;
    }
    else
    {
        if (current == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }

    free(current);
}

// using recursive method
BST *deleteElement(BST *list, int prodID)
{
    if (list == NULL) 
        return list;

    if (prodID < list->data.prodID)
        list->left = deleteElement(list->left, prodID);
    else if (prodID > list->data.prodID)
        list->right = deleteElement(list->right, prodID);
    else
    {
        if (list->left == NULL)
        {
            NodeType *temp = list->right;
            free(list);
            return temp;
        }
        else if (list->right == NULL)
        {
            NodeType *temp = list->left;
            free(list);
            return temp;
        }

        NodeType *temp = min(list->right);
        list->data = temp->data;
        list->right = deleteElement(list->right, temp->data.prodID);
    }
    return list;
}

void inorderBST(BST *list)
{
	if (isEmpty(list))
	{
		return;
	}
	if(list->left != NULL)
	{
		inorderBST(list->left);
	}
	displayProduct(list->data);
	if(list->right != NULL)
	{
		inorderBST(list->right);
	}
}

void preorderBST(BST *list)
{
	if (isEmpty(list))
	{
		return;
	}
	displayProduct(list->data);
	if(list->left != NULL)
	{
		preorderBST(list->left);
	}
	if(list->right != NULL)
	{
		preorderBST(list->right);
	}
}

void postorderBST(BST *list)
{
	if (isEmpty(list))
	{
		return;
	}
	if(list->left != NULL)
	{
		postorderBST(list->left);
	}
	if(list->right != NULL)
	{
		postorderBST(list->right);
	}
	displayProduct(list->data);
}

BST *newBST()
{
	BST *newBST = NULL;
	return newBST;	
}

void initBST(BST **list)
{
	*list = NULL;	
}

bool isEmpty(BST *list)
{
	if (list != NULL)
	{
		return false;
	}
	return true;
}

Product createProduct(int id, char *name, int qty, float price)
{
	Product retVal;
	
	retVal.prodID = id;
	strcpy(retVal.prodName, name);
	retVal.prodQty = price;
	retVal.prodPrice = price;
	
	return retVal;
}

// use the following format: {<id> | <prodName>}
void displayProduct(Product prod)
{
	printf("{ %5i | %20s | %5i | %5.2f }\n", prod.prodID, prod.prodName, prod.prodQty, prod.prodPrice);
}

NodeType* max(BST *list)
{
	NodeType *current = list;
	while (current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

NodeType* min(BST *list)
{
	NodeType *current = list;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

bool isMember(BST *list, int prodID)
{
    NodeType *current = list;
    
    while(current != NULL)
    {
        if(prodID == current->data.prodID)
            return true;
        else if(prodID < current->data.prodID)
            current = current->left;
        else
            current = current->right;
    }
    
    return false;
}
