// =================================================
// Minh Le, Nguyen Nguyen, Esther Zhang
// DoublyLinkedList.cpp
// This file contains the class method definitions
// for the doubly-linked list class.
// =================================================

#include <iostream>
#include <string>
#include <cassert>
#include "DoublyLinkedList.hpp"
using namespace std;

/*------------------------------------------------------------------
The List constructor: initialize the empty list
Preconditions: none
Postconditions: size = 0; head = NULL
Parameters: Void
Return: Void
------------------------------------------------------------------*/
template <class T>
    DoublyLinkedList<T>::DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

/*------------------------------------------------------------------
The List copy constructor: initialize the with list by deep copying 
other list
Preconditions: none
Postconditions: Copy of current list is created
Parameters: The list to be copied
Return: Void
------------------------------------------------------------------*/
template <class T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &mylist)
    {
        head = NULL;
        size = 0;
        // use the helper function to copy the list
        deep_copy(mylist);
    }

/*------------------------------------------------------------------
The List destructor: remove instance of the list class
Preconditions: none.
Postconditions: size = 0; head = NULL; tail = NULL
Parameters: Void
Return: Void
------------------------------------------------------------------*/
template <class T>
    DoublyLinkedList<T>::~DoublyLinkedList()
    {
        // use the helper function to deallocate resource
        delete_list();
    }

/*------------------------------------------------------------------
1. prepend() adds a value to the beginning of the linked list
Preconditions: none
Postconditions: size++; head = item;
Parameters: T type value of an item to be prepended to the list
Return: Void
------------------------------------------------------------------*/
template <class T>
void DoublyLinkedList<T>::prepend(const T &item)
{
    insert(item, 0);
}

/*------------------------------------------------------------------
2. append() adds a value to the end of the linked list
Preconditions: none
Postconditions: size++; tail = item;
Parameters: T type value of an item to be appended to the list
Return: Void
------------------------------------------------------------------*/
template <class T>
void DoublyLinkedList<T>::append(const T &item)
{
    insert(item, size);
}

/*------------------------------------------------------------------
Insert() adds a value to the specified position
Preconditions: Index <= Size, size!= 0
Postconditions: size++
Parameters: T type value to be inserted in the list and a index in the list
Return: Void
------------------------------------------------------------------*/
template <class T>
void DoublyLinkedList<T>::insert(const T &item, int index)
{
    assert(index >=0 && index <= size);

    Node* temp = new Node;
    
    // item that need to be added to the list
    temp -> item = item;
    temp -> next = NULL;
    temp -> prev = NULL;


    // Case 1: insert item to the first index
    if (index == 0) {
            if (size > 0) {
                head -> prev = temp;
            }
            temp -> next = head;
            head = temp;
        } 
        else {
            Node* ptr = head;
            for (int i = 1; i < index; i++) {
                ptr = ptr -> next;
            }
            // Case 2: insert into index 'size'
            if (index == size) {
                tail = temp;
                ptr -> next = temp;
                temp -> prev = ptr;
            }
            // Case 3: insert into index in the middle of the list 
            else {
                temp -> next = ptr -> next;
                temp -> prev = ptr;
                ptr -> next -> prev = temp;
                ptr -> next = temp;
            }
        }
        size++;
}


/*------------------------------------------------------------------
4. remove() deletes a value at desired position
Preconditions: position >= 0, position <= size and size != 0
Postconditions: size--
Parameters: Integer type value representing a supposed index in the list
Return: Void
------------------------------------------------------------------*/
template <class T>
    void DoublyLinkedList<T>::remove(int index)
    {
        assert (head != NULL && index >= 0 && index < size); 
    
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp -> next;
        }
        // Case 1: if remove the first index
        if (temp -> prev == NULL) {
            head = head -> next;
            if (head != NULL) {
                head -> prev = NULL;
            } 
            delete temp;
        } 
        // Case 2: if remove the last index
        else if (temp -> next == NULL){
            tail = temp -> prev;
            temp -> prev -> next = NULL;
            delete temp;
        }
        // Case 3: if remove index in the middle of the list
        else {
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
        }
        size--;
    }

/*------------------------------------------------------------------
5. search() finds the index of the first instance of item in the list.
If item is not in the list, returns -1.
Preconditions: size > 0
Postconditions: none.
Parameters: T type value representing a supposed item in the list
Return: Integer value representing an supposed index of an item in the list
------------------------------------------------------------------*/
template <class T>
    int DoublyLinkedList<T>::search(const T &item) const
    {
        int count = 0;
        Node *iterate = head;
        // iterate through the list and find the 'item'
        while (iterate != NULL && iterate->item != item)
        {
            iterate = iterate->next;
            count++;
        }
        // if found, return the index
        if (iterate != NULL && iterate->item == item)
        {
            return count;
        }
        // if not, return -1
        else
        {
            return -1;
        }
    }

/*------------------------------------------------------------------
6. operator[] allow access to an element inside the brackets
Valid indices are 0 to size-1.
Invalid indices generate a run-time error and end the program.
Preconditions: index >= 0, head != NULL, index < size
Postconditions: size > 0, head != NULL
Parameters: Integer value representing a supposed index of the list
Return: T type value depdending on what's stored in the list
------------------------------------------------------------------*/
template <class T>
    T &DoublyLinkedList<T>::operator[](int index)
    {
        assert(head != NULL && index >= 0 && index < size);
        Node *iterate = head;
        for (int i = 0; i < index; i++)
        {
            iterate = iterate->next;
        }
        return iterate->item;
    }

/*------------------------------------------------------------------
7. length()
Return the number of elements in a list
Preconditions: none.
Postconditions: none.
Parameters: Void
Return: Integer value depending on the size of the list
------------------------------------------------------------------*/
template <class T>
    int DoublyLinkedList<T>::length(void) const
    {
        return size;
    }

/*------------------------------------------------------------------
8. empty()
This method returns true if the list is empty and returns false otherwise.
Preconditions: none.
Postconditions: none.
Parameters: Void
Return: Boolean value depending on state of the list
------------------------------------------------------------------*/
template <class T>
    bool DoublyLinkedList<T>::empty (void) const {
        return (head == NULL);
    }

/*------------------------------------------------------------------
9. concat
This method concatenates two existing lists to return a newly created lis
Preconditions: none.
Postconditions: none.
Parameters: A list to be concatenated with the other
Return: A new concatenated list from too list
------------------------------------------------------------------*/
template <class T>
    DoublyLinkedList<T> DoublyLinkedList<T>::concat (const DoublyLinkedList<T> &list ) const {
        // copy the current list
        DoublyLinkedList<T> newList(*this);
        // use helper function to copy the list we want to concatenate
        newList.deep_copy(list);
        return newList;
    }

/*------------------------------------------------------------------
11. operator=
This method assigns one list from another by destructing the
current list and then behaving like a copy constructor.
Preconditions: none.
Postconditions: list = mylist.list.
Parameters: A list to be copied
Return: A doubly linked list
------------------------------------------------------------------*/
template <class T>
    DoublyLinkedList<T> DoublyLinkedList<T>::operator= ( const DoublyLinkedList<T> &mylist ) {
        if (this != &mylist) {
            // delete the current resource stored in list
            delete_list();
            // use helper function to perform deep copy
            deep_copy(mylist);
        }
        return (*this);
    }

// ********************** Private (Helper) Functions ************************

/*------------------------------------------------------------------
delete_list deallocates all the nodes associated with "this" list.
Preconditions: none.
Postconditions: size = 0; head = NULL; tail = NULL
Parameters: Void
Return: Void
------------------------------------------------------------------*/
template <class T>
    void DoublyLinkedList<T>::delete_list()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        size = 0;
    }


/*------------------------------------------------------------------
deep_copy iterate through the wanted list and append it to this list.
Preconditions: none.
Postconditions: none.
Parameters: The list to be copied
Return: Void
------------------------------------------------------------------*/
template <class T>
    void DoublyLinkedList<T>::deep_copy (const DoublyLinkedList<T>& L) {
        Node* current = L.head;

        while (current != NULL) {
            append(current->item);
            current = current->next;
        }
    }
