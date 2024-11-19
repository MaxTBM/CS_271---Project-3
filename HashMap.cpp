/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the implementations of a hash map class functions.
===========================================================================*/

#include <iostream>
#include <utility>
#include "HashMap.hpp"
#include "customexceptions.hpp"

using namespace std;

/*===========================================================================
Default constructor
Creates a hashmap with type K keys and type T values
Parameters: number of keys
Return: None
===========================================================================*/
template <class K, class V>
HashMap<K, V>::HashMap(long size)
{
    members_size = size;
    elements = 0;
    map = new Slot[members_size];

    for (int i = 0; i < members_size; ++i) {
        map[i].chain = DoublyLinkedList<V>();
    }
}

/*===========================================================================
Default copy constructor
Copy a hashmap to a new hashmap both with type K keys and type T values
Parameters: A hashmap
Return: None
===========================================================================*/
template <class K, class V>
HashMap<K, V>::HashMap(const HashMap<K, V> &other)
{
    
}