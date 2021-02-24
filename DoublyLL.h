/*
================================================================================
FILE        : main.c
AUTHOR      : Emmanuel Torres
DESCRIPTION : Interface file for function prototypes, global variables and data 
			  structures used for Doubly Linked List operations
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
#include <stdio.h>
#include <stdlib.h>

/*
================================================================================
Data Structures
================================================================================
*/
typedef struct node
{
	int data;
	struct node *prev, *next;
}NODE;

typedef struct list
{
	int count;
	struct node *head, *tail;
}LIST;

/*
================================================================================
Function Prototypes
================================================================================
*/
void createDoubly(LIST *L, int data);
void insertFront(LIST *L, int data);
void insertRear(LIST *L, int data);
void insertAt(LIST *L, int data, int p);
void removeFront(LIST *L);
void removeRear(LIST *L);
void removeAt(LIST *L, int p);
void printMirror(LIST *L);
void getDisplay(LIST *L);
void displayAll(LIST *L);
