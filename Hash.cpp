/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
Hash.hpp
This file contains the implementations of a hash function class.
The function is the division method
===========================================================================*/

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <limits>
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
Hash function implementation (division method)
Parameters: The key to hash
Return: The hash index for the key of long type
===========================================================================*/
template <class K>
long Hash<K>::getHash(K key)
{
    unsigned long long k = 0;

    // Check if the key is a string
    if constexpr (is_same<K, string>::value) {
        // Convert string key into a numeric value by summing ASCII values
        for (char c : key) {
            k = (k * 31 + static_cast<unsigned long long>(c));
        }
    } else {
        k = static_cast<unsigned long long>(key);
    }

    return static_cast<long>(k % slots);
}

