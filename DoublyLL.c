/*
================================================================================
FILE        : main.c
AUTHOR      : Emmanuel Torres
DESCRIPTION : Functions for Doubly Linked List
COPYRIGHT   : February 21, 2020
REVISION HISTORY
Date: 					By: 				Description:
================================================================================
February, 22, 2020		Emmanuel Torres		Creation
February, 23, 2020		Emmanuel Torres		Debugging
February, 24, 2020		Emmanuel Torres		Debugging and Finalization
================================================================================
Header Files
================================================================================*/
#include "DoublyLL.h"
/*
================================================================================
FUNCTION    : createDoubly
DESCRIPTION : Creates Doubly Linked List from empty list
ARGUMENTS   : LIST *L
			: int data
RETURNS     : void 
================================================================================
*/
void createDoubly(LIST *L, int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	L->head = NULL;
	
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (L->head == NULL)
	{
		L->head = L->tail = newNode;
	}
	else
	{
		L->tail->next = newNode;
		newNode->prev = L->tail;
		L->tail = newNode;
	}
}
/*
================================================================================
FUNCTION    : insertFront
DESCRIPTION : Inserts element at the front of the list
ARGUMENTS   : LIST *L
			: int data
RETURNS     : void 
================================================================================
*/
void insertFront(LIST *L, int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	
	if (L->head == NULL)
	{
		createDoubly(L, data);
	}
	else
	{
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
	
		L->head->prev = newNode;
		newNode->next = L->head;
		L->head = newNode;
	
		L->count++;
	}
}
/*
================================================================================
FUNCTION    : insertRear
DESCRIPTION : Inserts element at the rear of the list
ARGUMENTS   : LIST *L
			  int data
RETURNS     : void 
================================================================================
*/
void insertRear(LIST *L, int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
 
    newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	L->tail->next = newNode;
	newNode->prev = L->tail;
	L->tail= newNode;
    	
    L->count++;
}
/*
================================================================================
FUNCTION    : insertAt
DESCRIPTION : Inserts element at the nth position of the list
ARGUMENTS   : LIST *L
			  int data
			  int p
RETURNS     : void 
================================================================================
*/
void insertAt(LIST *L, int data, int p)
{
	int i;
	
	if (p == 0)
	{
		insertFront(L, data);
	}
	else if (p >= L->count)
	{
		insertRear(L, data);
	}
	else
	{
		NODE *newNode = (NODE*)malloc(sizeof(NODE));
		NODE *tempNode = L->head;
		
		newNode->data = data;
    	
    	for (i = 1; i < p; i++)
    	{
    		tempNode = tempNode->next;
		}
		
		newNode->prev = tempNode;
		newNode->next = tempNode->next;
		tempNode->next = newNode;
		newNode->next->prev = newNode;
		
		L->count++;
	}
}
/*
================================================================================
FUNCTION    : removeFront
DESCRIPTION : Deletes element at the front of the list
ARGUMENTS   : LIST *L
RETURNS     : void 
================================================================================
*/
void removeFront(LIST *L)
{
	NODE *tempNode = L->head;
	
	L->head = tempNode->next;
}
/*
================================================================================
FUNCTION    : removeRear
DESCRIPTION : Deletes element at the rear of the list
ARGUMENTS   : LIST *L
RETURNS     : void 
================================================================================
*/
void removeRear(LIST *L)
{
	NODE *tempNode = L->tail;
	
	L->tail->prev->next = NULL;
	L->tail = L->tail->prev;
}
/*
================================================================================
FUNCTION    : removeAt
DESCRIPTION : Deletes element at the nth position of the list
ARGUMENTS   : LIST *L
RETURNS     : void 
================================================================================
*/
void removeAt(LIST *L, int p)
{
	int i;
	
	NODE *tempNode = L->head;
	
	for (i = 1; i < p; i++)
	{
		if(tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
	}
	
	tempNode->next = tempNode->next->next;
}
/*
================================================================================
FUNCTION    : printMirror
DESCRIPTION : Reverses elements in the list
ARGUMENTS   : LIST *L
RETURNS     : void 
================================================================================
*/
void printMirror(LIST *L)
{
	NODE *previousNode;
	NODE *currentNode;
	NODE *tempNode;
	
	previousNode = currentNode = tempNode = L->head;
    previousNode = previousNode->next->next;
    currentNode = currentNode->next;
    tempNode->next = NULL;
    currentNode->next = tempNode;
    
    while (previousNode != NULL)
    {
        tempNode = currentNode;
        currentNode = previousNode;
        previousNode = previousNode->next;
        currentNode->next = tempNode;
    }
    L->head = currentNode;
	
	printf("\nREVERSED LIST: ");
	getDisplay(L);
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}
/*
================================================================================
FUNCTION    : getDisplay
DESCRIPTION : Displays Singly Linked List
ARGUMENTS   : NODE *h
RETURNS     : void 
================================================================================
*/
void getDisplay(LIST *L)
{
    NODE *tempNode = L->head;
    
    while(tempNode != NULL)
    {
        printf(" %d ",tempNode->data);
        
        tempNode = tempNode->next;
    }
}
/*
================================================================================
FUNCTION    : displayAll
DESCRIPTION : Display format
ARGUMENTS   : NODE *h
RETURNS     : void 
================================================================================
*/
void displayAll(LIST *L)
{
	printf("\nLIST %d: ", L->count);
	getDisplay(L);
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}
