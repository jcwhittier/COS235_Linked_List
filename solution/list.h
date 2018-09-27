#ifndef LIST_H_   /* Include guard */
#define LIST_H_


/******************************************************************************* 

                             	STRUCTS
            
*******************************************************************************/ 

/*
 *	A struct for representing an element of a singly linked list.
 *
 *	MEMBERS:
 *		struct *listData  
 *			A pointer *listData to the data to be held by the element of the list. 
 *  		This data could be a struct, int, char, or whatever you want.  
 *		struct ListElement *nextElement
 *			A pointer *nextElement points to the next element of the list.
 *			*nextElement should be initialized to NULL
 */
typedef struct ListElement
{
	int listData;
	struct ListElement *nextElement;
} ListElement;



/*
 *	A struct for representing an list. This is just a named pointer to the first element of the list
 *
 *	MEMBERS:
 *		ListElement *headElement  
 *			A pointer *headElement to the first element of the list. 
 *			*headElement should be initialized to NULL
 */
typedef struct List
{
	ListElement *headElement;
} List;


/******************************************************************************* 

                              GENERIC FUNCTIONS
            These functions will work regardless of the type used for listData
*******************************************************************************/ 

/*
 * 	Get the nextElement member of a ListElement
 */
ListElement* getNextElement(ListElement *listElement);


/*
 *	Set the nextElement member of a ListElement
 */
void setNextElement(ListElement *listElement, ListElement *nextElement);


/*
 * 	Return 1 if the list is empty, 0 otherwise
 */
int isEmpty(List *list);

/*
 *	Return a pointer to the element at index i in the given list
 *  Return a pointer to NULL if index is beyond the end of the list
 */
ListElement* getElement(List *list, int index);

/*
 * 	Add a given element to the end of a specified list.
 * 	The nextElement member of the field being inserted will be set to NULL
 */
void addElement(List *list, ListElement *listElement);
/*
 * 	Free all memory used by the list
 */
void destructList(List *list);

/*
 *	Return the number of elements in the list
 */
int listSize(List *list);


/*
 *	Insert a given element at the specified index in a specified list. Shifts
 *	all other elements to the right, increasing their index by 1. 
 *  Requires 0 <= index <= listSize(), otherwise the element should not be inserted.  
 */
void insertElement(List *list, ListElement *listElement, int index); 

/*
 * 	Remove the element at the specified index and return a pointer to the element
 *	Requires 0 <= index < listSize(), otherwise return NULL
 */
ListElement* removeElement(List *list, int index);


/******************************************************************************* 

                           TYPE-SPECIFIC FUNCTIONS
        Implemented using the generic functions defined above when possible.
*******************************************************************************/ 

/*
 *	Return the data in a list element
 */
int getElementData(ListElement *listElement);

/*
 *	Set the an element to point to the given data address
 */
void setElementData(ListElement *listElement, int listData);

/*
 *	Create a new element with the given data and add it to the list
 */
void addData(List *list, int listData);

/*
 * Print out the elements of list of ints in one line.
 */
void printList(List *list);

/*
 * 	Return the value (listData) of the element at the specified index.
 */
int getData(List *list, int index);

/*
 * Insert a new element with the given data at the specified index
 * NOTE: Can any pervious implemented operations be used here?
 */	
void insertData(List *list, int listData, int index);

/*
 * Remove the element at the specified index and return its value
 * Make sure to free the memory previously held by the ListElement.
 */
int removeData(List *list, int index);

/*
 * Reverse the list in place and return a pointer to the list
 */
List * reverse(List *list);

#endif /* LIST_H_ */

