/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the implementations of a hash map class functions.
===========================================================================*/

#include <iostream>
#include <utility>
#include <vector>
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
    slots = size;
    elements = 0;
    hash_func(slots);
    map = new vector<pair<K, V>>[slots];
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
    copy(other);
}

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class K, class V>
HashMap<K, V>::~HashMap()
{
    delete[] map;
}

/*===========================================================================
Assignment operator
Overloading the = operator to assign a binary search tree node, functions
similar to the copy constructor
Parameters: A binary search tree node with value of type T
Return: A copied binary search tree node with value of type T
===========================================================================*/
template <class K, class V>
HashMap<K, V> *HashMap<K, V>::operator=(const HashMap<K, V> &other)
{
    if (this != &other)
    {
        delete[] map;
        copy(other);
    }
    return *this;
}

/*===========================================================================
The copy helper function
Copy a hashmap to a new hashmap both with type K keys and type T values
Parameters: A hashmap
Return: None
===========================================================================*/
template <class K, class V>
void HashMap<K, V>::copy(const HashMap<K, V> &other)
{
    slots = other.slots;
    elements = other.elements;
    hash_func(slots);

    map = new vector<pair<K, V>>[slots];
    for (long i = 0; i < slots; i++)
    {
        map[i] = other.map[i];
    }
}

