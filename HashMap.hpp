/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the definitions of a hash map class.
===========================================================================*/

#include <iostream>
#include <utility>
#include "DoublyLinkedList.hpp"
#include "DoublyLinkedList.cpp"

using namespace std;

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

template <class K, class V> 
class HashMap
{
    private:
        struct Slot
        {
            K key;
            DoublyLinkedList<V> chain; // Doubly linked list to store values for the key
        }

        long members_size; // Size of the hash map (number of slots)
        long elements; // Number of key-value pairs in the map
        Slot *map; // Dynamic array of slots
        // Hash function to compute the slot index
        long                hash                            (const K &key) const;
        // Helper function for copy constructor and assignment
        void                copy                            (const HashMap<K, V> &other);

        

    public:
						    HashMap		                    (long size = 20);
						    HashMap		                    (const HashMap<K, V> &other);
						    ~HashMap		                (void);

		HashMap<K, V>*		operator=	                    (const HashMap<K, V> &other);
        V&                  operator[]                      (const K &key);

        void                insert                          (const K &key, const V &value);
        void                remove                          (const K &key);
        pair<K, V>*         search                          (const K &key);
};


#include "HashMap.cpp"

#endif