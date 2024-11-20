/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
Hash.hpp
This file contains the implementations of a hash function class.
The function is the multiplication method
===========================================================================*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include "Hash.hpp"

using namespace std;

/*===========================================================================
Default constructor
Parameters: number of keys
Return: None
===========================================================================*/
template <class K>
Hash<K>::Hash(long num_slots = 20) 
{
    slots = num_slots;
}

/*===========================================================================
Default copy constructor
Parameters: A hash
Return: None
===========================================================================*/
template <class K>
Hash<K>::Hash(const Hash<K>& other)
{
    slots = other.slots;
}

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class K>
Hash<K>::~Hash()
{

}

/*===========================================================================
Overloading the = operator to assign a binary search tree node, functions
similar to the copy constructor
Parameters: A binary search tree node with value of type T
Return: A copied binary search tree node with value of type T
===========================================================================*/
template <class K>
Hash<K>& Hash<K>::operator=(const Hash<K>& other)
{
    if (this != &other) {
        slots = other.slots;
    }
    return *this;
}

/*===========================================================================
Hash function implementation (multiplication method)
Parameters: The key to hash
Return: The hash index for the key of long type
===========================================================================*/
template <class K>
long Hash<K>::func(const K& key) const
{
    return floor(slots * ((key * A) - floor(key * A)));
}