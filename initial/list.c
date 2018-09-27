#include <stdio.h>
#include <stdlib.h>

#include "list.h"


/******************************************************************************* 

                              GENERIC FUNCTIONS
            These functions will work regardless of the type used for listData
*******************************************************************************/ 

/*
 * 	Get the nextElement member of a ListElement
 */
ListElement* getNextElement(ListElement *listElement){
	return listElement->nextElement;
}


/*
 *	Set the nextElement member of a ListElement
 */
void setNextElement(ListElement *listElement, ListElement *nextElement){
	listElement->nextElement = nextElement;
}


/*
 * 	Return 1 if the list is empty, 0 otherwise
 */
int isEmpty(List *list){
	if (list->headElement == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/*
 *	Return a pointer to the element at index i in the given list
 *  Return a pointer to NULL if index is beyond the end of the list
 */
ListElement* getElement(List *list, int index){
	int elementIndex;
	ListElement* tempElement = NULL;
	
	if (!isEmpty(list)){
		tempElement = list->headElement;
		for (elementIndex = 1; elementIndex <= index; elementIndex++){
				if (tempElement != NULL) {
					tempElement = getNextElement(tempElement);
				}		
		}
	}
	
	return tempElement;
}

/*
 * 	Add a given element to the end of a specified list.
 * 	The nextElement member of the field being inserted will be set to NULL
 */
void addElement(List *list, ListElement *listElement){
	if (isEmpty(list)){
		list->headElement = listElement;
	} else {
		ListElement* tempElement = list->headElement;
		
		while (getNextElement(tempElement) != NULL){
			tempElement = getNextElement(tempElement);
		}
		
		setNextElement(listElement, NULL);
		setNextElement(tempElement, listElement);
	}
}

/*
 * 	Free all memory used by the list
 */
void destructList(List *list){
	if (!isEmpty(list)){
		
		ListElement* tempElement = list->headElement;
		
		while (tempElement != NULL){	
			ListElement* nextElement = getNextElement(tempElement);
			free(tempElement);
			tempElement = nextElement;
		}
		
		list->headElement = NULL;
	}
	
	
}

/*
 *	IMPLEMENT THIS
 *	Return the number of elements in the list
 */
int listSize(List *list);


/*	IMPLEMENT THIS
 *	Insert a given element at the specified index in a specified list. Shifts
 *	all other elements to the right, increasing their index by 1. 
 *  Requires 0 <= index <= listSize(), otherwise the element should not be inserted.  
 */
void insertElement(List *list, ListElement *listElement, int index); 

/* 	IMPLEMENT THIS
 * 	Remove the element at the specified index and return a pointer to the element
 *	Requires 0 <= index < listSize(), otherwise return NULL
 */
ListElement* removeElement(List *list, int index);








/******************************************************************************* 

                           TYPE-SPECIFIC FUNCTIONS
        Implement these using the generic functions defined above when possible.
*******************************************************************************/ 

/*
 *	Return the data in a list element
 */
int getElementData(ListElement *listElement){
	return listElement->listData;
}

/*
 *	Set the an element to point to the given data address
 */
void setElementData(ListElement *listElement, int listData){
	listElement->listData = listData;
}

/*
 *	Create a new element with the given data and add it to the list
 */
void addData(List *list, int listData){
	ListElement* newElement = malloc(sizeof(ListElement));
	setNextElement(newElement, NULL);
	setElementData(newElement, listData);
	addElement(list, newElement);
}

/*
 * Print out the elements of list of ints in one line.
 */
void printList(List *list){
	printf("LIST: ");
	
	if (list == NULL){
		printf("IS NULL");
	} else if (isEmpty(list)){
		printf("IS EMPTY");
	} else {
		/* print all the elements in the list */
		ListElement* tempElement = list->headElement;
		
		while (tempElement != NULL){
			if (getNextElement(tempElement) != NULL){
				printf("%d, ", getElementData(tempElement));
				tempElement = getNextElement(tempElement);
			} else {
				printf("%d", getElementData(tempElement));
				break;
			}		
		}		
	}
	/* print a new line */
	printf("\n");
}

/* 	IMPLEMENT THIS
 * 	Return the value (listData) of the element at the specified index.
 * 	NOTE: Can any pervious implemented operations be used here?
 */
int getData(List *list, int index);

/* IMPLEMENT THIS
 * Insert a new element with the given data at the specified index
 * NOTE: Can any pervious implemented operations be used here?
 */	
void insertData(List *list, int listData, int index);

/* IMPLEMENT THIS
 * Remove the element at the specified index and return its value
 * Make sure to free the memory previously held by the ListElement.
 * NOTE: Can any pervious implemented operations be used here?
 */
int removeData(List *list, int index);


/*	OPTIONAL
 * 	Return a sorted copy of the list made up of new elements
 * 	You may use a simple sorting algorithm like insertion sort.
 */
List * sort(List *list);


int main(){
	int i;
	
	/* create a new List called myList */
	List myList;
	/* set the headElement of the list to be a NULL pointer */
	myList.headElement = NULL;	
	
	/* print out what the list looks like */
	printList(&myList);
		
	/* add some items to the list and successively print the list*/
	for (i = 0; i < 8; i++){
		addData(&myList, i);
		printList(&myList);	
	}
	
	/* destruct the list */
	destructList(&myList);
	printList(&myList);
	/* destruct an empty list? */
	destructList(&myList);
	printList(&myList);
	
	/* Now add some elements again. */
	for (i = 8; i < 13; i++){
		addData(&myList, i);
		printList(&myList);	
	}
	
	/* Now test size, get, insert, and remove */

	exit(EXIT_SUCCESS);
}
