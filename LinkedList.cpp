/*--- LinkedList.cpp --------------------------------------------------
This implementation file contains the definitions of LinkedList.

LinkedList() : Constructs an empty LinkedList object.
display():Display a list.
ostream &operator<<():Overloaded the insertion operator for LinkedList object.
insert():Insert a value into the LinkedList in a sorted order.
erase(): Removes a node containing the value from the LinkedList.
~LinkedList():Destroys a LinkedList object.
LinkedList(const LinkedList& origList):Construct a copy of a LinkedList object.
const LinkedList & operator=():Assign a copy of a LinkedList object to the
current object.
ostream & operator<<():Overloaded the insertion operator for the LinkedList
object.
helpereraser():Removes a node containing the value from the LinkedList.

Student Name: Nicol Salgado
Course:CSCI 1107

---------------------------------------------------------------------*/
#include <iostream>
#include<new>
using namespace std;

#include "LinkedList.h"

LinkedList::LinkedList() : first(0), mySize(0) {};
/* -------------------------------------------------------------------
Constructs an empty LinkedList object.
---------------------------------------------------------------------*/
void LinkedList::display(ostream &out)const {
	Node *ptr = first;
	for (; ptr != NULL;) {
		out << ptr->data;
		ptr = ptr->next;
	}
}
/* -------------------------------------------------------------------
Display a list.
---------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const LinkedList &intList) {
	intList.display(out);
	return out;
}
/* -------------------------------------------------------------------
Overloaded the insertion operator for the LinkedList object.
---------------------------------------------------------------------*/
void LinkedList::insert(ElementType dataValue) {
	Node *nptr = new(nothrow) Node(dataValue);
	// empty list
	if (first == NULL) {
		first = nptr;
	}
	// not empty list
	else {
		Node *curptr = first;
		Node *predptr = new Node(*nptr);
		for (; curptr != NULL && curptr->data < dataValue;) {
			predptr = curptr;
			curptr = curptr->next;
		}
		nptr->next = predptr->next;
		predptr->next = nptr;
	}
	mySize++;
}
/* -------------------------------------------------------------------
Insert a value into the LinkedList in a sorted order.
---------------------------------------------------------------------*/
void LinkedList::erase(ElementType dataValue) {
	//If the list is empty
	if (first == NULL) {
		cout << "Node of value " << dataValue << " can not be deleted,because the list is empty." << endl;
	}
	//If the list is not empty
	else {
		helpereraser(dataValue);	
	}
}
/* -------------------------------------------------------------------
Removes a node containing the value from the LinkedList.
---------------------------------------------------------------------*/
LinkedList::~LinkedList() {
	Node *ptr = first;
	for (; ptr != NULL;) {
		first = ptr->next;
		delete ptr;
		ptr = first;
	}
	if (first == 0)
		cout << "list destroyed." << endl;
	else
		cout << "list NOt destroyed" << endl;
}
/* -------------------------------------------------------------------
Destroys a LinkedList object.
---------------------------------------------------------------------*/
LinkedList::LinkedList(const LinkedList& origList) {
	if (origList.mySize == NULL)
		first = NULL;
	else {
		NodePointer origptr = origList.first;
		NodePointer lastptr = new Node(*origptr);
		first = lastptr;
		origptr = origptr->next;
		// Go through the origList
		for (; origptr != NULL;) {
			NodePointer currentptr = new Node(*origptr); //copy data in current node of origList
			lastptr->next = currentptr;  //add currentptr to end of list
			lastptr = lastptr->next; //move lastPtr forward
			origptr = origptr->next; //move to next node in origList
		}
	}
	mySize++;
}

/* -------------------------------------------------------------------
Construct a copy of a LinkedList object.
---------------------------------------------------------------------*/
const LinkedList & LinkedList::operator=(const LinkedList& origList) {
	if (origList.mySize == NULL)
		this->~LinkedList();
	else {
		NodePointer origptr = origList.first;
		NodePointer lastptr = new Node(*origptr);
		first = lastptr;
		origptr = origptr->next;
		// Go through the origList
		for (; origptr != NULL;) {
			NodePointer currentptr = new Node(*origptr); //copy data in current node of origList
			lastptr->next = currentptr;  //add currentptr to end of list
			lastptr = lastptr->next; //move lastPtr forward
			origptr = origptr->next; //move to next node in list
		}
	}
	return *this;
}
/* -------------------------------------------------------------------
Assign a copy of a LinkedList object to the current object.
---------------------------------------------------------------------*/
void LinkedList::helpereraser(ElementType dataValue) {
	Node *nptr = new(nothrow) Node(dataValue); // new pointer
	Node *curptr = first; // current pointer
	Node *predptr = NULL; // previous pointer
	for (; curptr != NULL;) {
		//Find location to delete
		if (curptr->data == dataValue)
			break;
		// value not found move predptr and curptr
		else {
			predptr = curptr;
			curptr = curptr->next;
		}
	}
	// If node is never found
	if (curptr == NULL) {
		cout << "Node of value " << dataValue << " was never found in the list." << endl;
	}
	//If node is found 
	else {
		// Delete at the beginning of the list
		if (first == curptr) {
			first = first->next;
		}
		//Delete after the first node
		else {
			predptr->next = curptr->next;
		}
		delete curptr;// delete node pointed by curptr
		mySize--;
	}
}
/* -------------------------------------------------------------------
Removes a node containing the value from the LinkedList.
---------------------------------------------------------------------*/