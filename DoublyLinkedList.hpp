// =================================================
// Minh Le, Nguyen Nguyen, Esther Zhang
// DoublyLinkedList.hpp
// This file contains the List class declaration. 
// =================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

template <class T>
class DoublyLinkedList
{
    private:
        struct Node
        {
            T item;
            Node *prev;
            Node *next;
        };
        Node *head;
        Node *tail;
        int size;

        // Helper Function
        // make a deep copy of a list
        void deep_copy (const DoublyLinkedList<T>& L);

        // delete all things in a list 
		void delete_list ();

    public:
                                DoublyLinkedList    (void);                                   
                                DoublyLinkedList    (const DoublyLinkedList<T> &myList);
                                ~DoublyLinkedList   (void);
        void                    prepend             ( const T &item );
        void                    append              ( const T &item );
        void                    insert              ( const T &item, int index );   
        void                    remove              ( int index );
        int                     search              ( const T &item ) const;
        T&                      operator[]          ( int index );
        int                     length              ( void ) const;
        bool                    empty               (void) const;
        DoublyLinkedList<T>     concat              (const DoublyLinkedList<T> &list ) const;
        DoublyLinkedList<T>		operator=	        ( const DoublyLinkedList<T> &mylist );
        
        // overload the << operator using a friend function for easier output
        // Parameters: an ostream object, a reference to the DoublyLinkedList object 
        // Return Value: returns the ostream object (os) with the elements of the list,
        //              seperated by space
        friend ostream &        operator<<          ( ostream &os, DoublyLinkedList<T> &mylist )
        {
            Node *ptr = mylist.head;
            while ( ptr != NULL )
            {
                if ( ptr->next != NULL )
                    os << ptr->item << " ";
                else
                    os << ptr->item;
                ptr = ptr->next;
            }
                
            return os;	
        }
};

// #include "DoublyLinkedList.cpp"

#endif