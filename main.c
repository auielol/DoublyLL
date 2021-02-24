/*
================================================================================
FILE        : main.c
AUTHOR      : Emmanuel Torres
DESCRIPTION : The program inserts elements into a doubly linked list
			: Deletes elements from the list and displays elements.
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
FUNCTION    : main
DESCRIPTION : Executes the main program that defines data, calls functions and
			  displays Doubly Linked list
ARGUMENTS   : int argc - argument count
			  int argv - argument vector
RETURNS     : int - return 0
================================================================================
*/
int main(int argc, char *argv[])
{
	LIST *L = (LIST*)malloc(sizeof(LIST));
	L->head = NULL;
	L->tail = NULL;
	L->count = 1;
	
	insertFront(L, 3);
	displayAll(L);
	insertFront(L, 2);
	displayAll(L);
	insertFront(L, 1);
	displayAll(L);
	
	insertRear(L, 5);
	displayAll(L);
	insertRear(L, 6);
	displayAll(L);
	
	insertAt(L, 4, 3);
	displayAll(L);
	insertAt(L, 7, 6);
	displayAll(L);
	insertAt(L, 0, 0);
	displayAll(L);
	
	removeFront(L);
	displayAll(L);
	removeRear(L);
	displayAll(L);
	removeRear(L);
	displayAll(L);
	
	insertAt(L, 8, 2);
	displayAll(L);
	
	removeAt(L, 2);
	displayAll(L);
	
	printMirror(L);
	
	printf("\nTHANK YOU!\n");
	
	return 0;
}
