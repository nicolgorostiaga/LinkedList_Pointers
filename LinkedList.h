/*--- LinkedList.h --------------------------------------------------------
  This header file contains the declarations of LinkedList, a class for
  singly-linked lists.
                    Lab #5.1 and Projects 5.1 & 5.2
                              
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
 --------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;
class LinkedList
{
 public:

	 LinkedList();
     /* -------------------------------------------------------------------
     Constructs an empty LinkedList object.

      Precondition:  None.
      Postcondition: This list's data members have been initialized 
          for an empty list.
     ---------------------------------------------------------------------*/
	 int size()const{
		 return mySize;
	 };
	 /* -------------------------------------------------------------------
	 Retrieves the number of nodes in the list.

	 Precondition:  Retrieve the value stored in the mySize.
	 Postcondition: returns mySize.
	 ---------------------------------------------------------------------*/
	 void display(ostream &out)const;
	 /* ------------------------------------------------------------------
	 Display a list.

	 Precondition: The ostream out is open.
	 Postcondition: The list represented by this List object has been 
	 inserted into out.
	 ---------------------------------------------------------------------*/
 
	 void insert(ElementType dataValue);
	/*----------------------------------------------------------------------
     Insert a value into the LinkedList in a sorted order.

     Precondition:  The parameter contains the data item to insert into an
                    ordered linked list. The field variable mySize needs
                    to be modified. 
     Postcondition: dataValue has been inserted into this LinkedList
         object at the position determined by its value.
	-----------------------------------------------------------------------*/

	 void erase(ElementType dataValue);
	/*----------------------------------------------------------------------
     Removes a node containing the value from the LinkedList.

     Precondition:  A data element from the list.                       
     Postcondition: The data value at the position determined by its value
                    has been removed(depending upon if it is in the list)
                    from this LinkedList object. 
	-----------------------------------------------------------------------*/
	 void helpereraser(ElementType dataValue);
	 /*----------------------------------------------------------------------
	 Removes a node containing the value from the LinkedList.

	 Precondition:  A data element from the list.
	 Postcondition: The data value at the position determined by its value
	 has been removed(depending upon if it is in the list)
	 from this LinkedList object.
	 -----------------------------------------------------------------------*/

	~LinkedList();
   /*----------------------------------------------------------------------
   Destroys a LinkedList object.

   Precondition: 
   Postcondition: The memory dynamically allocated by the constructor
   is returned to the heap.
   -----------------------------------------------------------------------*/

  LinkedList(const LinkedList& origList);
  /*----------------------------------------------------------------------
  Construct a copy of a LinkedList object.

  Precondition: The list is a const reference parameter.
  Postcondition: A copy of the list has been constructed.
  -----------------------------------------------------------------------*/

  const LinkedList & operator=(const LinkedList& RightSide);
  /*----------------------------------------------------------------------
  Assign a copy of a LinkedList object to the current object.

  Precondition:  The rightSide is a const reference parameter.
  Postcondition:  A copy of rightSide has been assigned to this object.
  A const reference to this list is returned.
  -----------------------------------------------------------------------*/

private:
  class Node
  {
    public:
		ElementType data;
		Node * next;
		Node() : data(NULL), next(NULL) {};
		Node(ElementType dataValue) : data(dataValue), next(NULL) {}
		/* -----------------------------------------------------------------
		The Node class constructor initializes a Node's data members.
        
        Precondtion: receives a data value and ElementType value;
        Postcondition: The data and next members have been set to
                       dataValue and 0, respectively.
		-------------------------------------------------------------------*/

   }; //--- end of Node class
  typedef Node * NodePointer;

  //------ DATA MEMBERS OF LinkedList ---------//
  NodePointer first;
  int mySize;

}; //--- end of LinkedList class----//

ostream & operator<<(ostream & out, const LinkedList &intList);
/* -------------------------------------------------------------------
Overloaded the insertion operator for the LinkedList object.

Precondition:The ostream out is open.
PostCondition: The intList represented by this LinkedList object 
has been inserted into ostream out(via display()); 
reference to out is returned.
---------------------------------------------------------------------*/

#endif
