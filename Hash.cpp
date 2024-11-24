/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
Hash.hpp
This file contains the implementations of a hash function class.
The function is the multiplication method
===========================================================================*/

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <type_traits>
#include "Hash.hpp"

using namespace std;

/*===========================================================================
Default constructor
Parameters: number of keys
Return: None
===========================================================================*/
template <class K>
Hash<K>::Hash(long num_slots)
{
    slots = num_slots;
}

/*===========================================================================
Default copy constructor
Parameters: A hash
Return: None
===========================================================================*/
template <class K>
Hash<K>::Hash(const Hash<K> &other)
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
Overloading the = operator, functions similar to the copy constructor
Parameters: A hash with value of type T
Return: A hash with value of type T
===========================================================================*/
template <class K>
Hash<K> &Hash<K>::operator=(const Hash<K> &other)
{
    if (this != &other)
    {
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
long Hash<K>::getHash(K key)
{
    long k = 0;
    string key_s;

    // Check if the key is a string
    if (is_same<K, string>::value)
    {
        key_s = key;
    }
    else
    {
        ostringstream oss;
        oss << key;
        key_s = oss.str();
    }

    // Add ASCII values of characters in the string
    for (int i = 0; i < key_s.length(); i++) {
        k += int(key_s[i]);
    }

    return floor(slots * ((k * A) - floor(k * A)));
}

