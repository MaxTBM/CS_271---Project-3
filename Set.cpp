/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.cpp
This file contains the implementations of a set class.
===========================================================================*/

#include <iostream>
#include <utility>
#include <string>
#include <type_traits>
#include "Set.hpp"
#include "customexceptions.hpp"

/*===========================================================================
Default constructor
Parameters: Number of keys for the hash map.
Return: None
===========================================================================*/
template <class T>
Set<T>::Set(long size)
{
    map = HashMap<T, bool>(size);
}

/*===========================================================================
Default copy constructor
Parameters: Another set
Return: None
===========================================================================*/
template <class T>
Set<T>::Set(const Set<T> &other)
{
    map = other.map;
}

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class T>
Set<T>::~Set()
{

}

/*===========================================================================
Overloading the = operator, functions similar to the copy constructor
Parameters: A set with value of type T
Return: A set with value of type T
===========================================================================*/
template <class T>
Set<T> &Set<T>::operator=(const Set<T> &other)
{
    if (this != &other)
    {
        map = other.map;
    }
    return *this;
}

/*===========================================================================
search() function
Search for A value in the set, which is a key in the hashmap
Parameters: value of type T
Return: Boolean value depending on the value's presence
===========================================================================*/
template <class T>
bool Set<T>::search(const T &value)
{
    return map.search(value) != nullptr;
}

/*===========================================================================
insert() function
Inserts a value using into the set if a value with the same value is not
already present.
Parameters: Value of type T
Return: None
===========================================================================*/
template <class T>
void Set<T>::insert(const T &value)
{
    if (!search(value))
    {
        map.insert(value, true);
    }
}

/*===========================================================================
remove() function
Takes value to be removed and removes it from the set.
Parameters: Value to be removed
Return: None
===========================================================================*/
template <class T>
void Set<T>::remove(const T &value)
{
    auto pair = map.search(value);
    if (pair != nullptr)
    {
        map.remove(pair);
    }
    else
    {
        throw KeyNotFoundException(value);
    }
}

