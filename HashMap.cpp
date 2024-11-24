/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the implementations of a hash map class functions.
===========================================================================*/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <type_traits>
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
    hash_func = Hash<K>(slots);
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
Overloading the = operator
Parameters: A hashmap of keys type K and values type T
Return: A copied hashmap of keys type K and values type T
===========================================================================*/
template <class K, class V>
HashMap<K, V>* HashMap<K, V>::operator=(const HashMap<K, V> &other)
{
    if (this != &other)
    {
        delete[] map;
        copy(other);
    }
    return *this;
}

/*===========================================================================
Overloading the [] operator
Parameters: key of type K
Return: reference to the value associated with the key (of type V)
===========================================================================*/
template <class K, class V>
V& HashMap<K, V>::operator[](const K &key)
{
    long index = hash_func.getHash(key);

    for (auto &pair : map[index])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }

    // Here the key isn't in the map
    // Check if the key is a string and throw exception
    if (is_same<K, string>::value)
    {
        throw KeyNotFoundException(key);
    }
    else
    {
        ostringstream oss;
        oss << key;
        throw KeyNotFoundException(oss.str());
    }
};

/*===========================================================================
insert() function
Inserts a value using a key to do the hash computation 
and to do any comparisons. If a value with the same key is already present, 
it gets overwritten.
Parameters: key of type K, value of type T 
Return: None
===========================================================================*/
template <class K, class V>
void HashMap<K, V>::insert(const K &key, const V &value)
{
    long index = hash_func.getHash(key);
    for (auto &pair : map[index])
    {
        // If the key already exists
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }

    // If the key doesn't exist, insert the new key-value pair
    map[index].push_back(make_pair(key, value));
    elements++;
}

/*===========================================================================
search() function
Search for a pair key-value using a key. If the pair doesn't exist, return
null pointer
Parameters: key of type K
Return: Pointer to the key-value pair or null pointer
===========================================================================*/
template <class K, class V>
pair<K, V>* HashMap<K, V>::search(const K &key)
{
    long index = hash_func.getHash(key);
    for (auto &pair : map[index])
    {
        // If the key is found
        if (pair.first == key)
        {
            return &pair;
        }
    }

    // If the key is not found, return nullptr
    return nullptr;
}

/*===========================================================================
remove() function
Takes a pointer to the element to be removed and removes it from the data
structure.
Parameters: Pointer to pair to be removed
Return: None
===========================================================================*/
template <class K, class V>
void HashMap<K, V>::remove(pair<K, V>* remove_pair)
{
    long index = hash_func.getHash(remove_pair->first);

    // Iterate through the vector at the calculated index
    for (auto i = map[index].begin(); i != map[index].end(); i++)
    {
        // Find the key-value pair to remove
        if (&(*i) == remove_pair)
        {
            map[index].erase(i);  // Remove the element from the vector
            elements--;
            return;
        }
    }
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
    hash_func = Hash<K>(slots);


    map = new vector<pair<K, V>>[slots];
    for (long i = 0; i < slots; i++)
    {
        map[i] = other.map[i];
    }
}

