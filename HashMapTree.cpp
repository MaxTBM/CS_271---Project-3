/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.cpp
This file contains the implementations of a hash map tree class.
This class uses an implementation of RBTree.
===========================================================================*/

#include <iostream>
#include <utility>
#include <string>
#include <type_traits>
#include "HashMapTree.hpp"
#include "customexceptions.hpp"

/*===========================================================================
Default constructor
Creates a hashmap with type K keys and type T values
Parameters: number of keys
Return: None
===========================================================================*/
template <class K, class V>
HashMapTree<K, V>::HashMapTree(long size) : slots(size), elements(0) {
    hash_func = Hash<K>(slots);
    map = new RBTree<pair<K, V>>[slots];
}

/*===========================================================================
Default copy constructor
Copy a hashmap to a new hashmap both with type K keys and type T values
Parameters: A hashmap
Return: None
===========================================================================*/
template <class K, class V>
HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V> &other) {
    copy(other);
}

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class K, class V>
HashMapTree<K, V>::~HashMapTree() {
    delete[] map; // Free the allocated array of RBTree
}

/*===========================================================================
Overloading the = operator
Parameters: A hashmap of keys type K and values type T
Return: A copied hashmap of keys type K and values type T
===========================================================================*/
template <class K, class V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V> &other) {
    if (this != &other) {
        delete[] map; // Free the existing map
        copy(other);  // Copy the data from the other HashMapTree
    }
    return *this;
}

/*===========================================================================
Overloading the [] operator
Parameters: key of type K
Return: reference to the value associated with the key (of type V)
===========================================================================*/
template <class K, class V>
V& HashMapTree<K, V>::operator[](const K &key) {
    long index = hash_func.getHash(key);
    auto node = map[index].search(make_pair(key, V()));  // Search for (key, default value)
    // if (node == nullptr) {  // Key not found
    //     insert(key, V());  // Insert key with default value
    //     node = map[index].search(make_pair(key, V()));  // Search again after insertion
    // }
    // return node->value().second;  // Return reference to the value

    if (node != nullptr)
        {
            return node->value().second;
        }

    // Here the key isn't in the map
    throw key_not_found_exception(key);
}

/*===========================================================================
insert() function
Inserts a value using a key to do the hash computation 
and to do any comparisons. If a value with the same key is already present, 
it gets overwritten.
Parameters: key of type K, value of type T 
Return: None
===========================================================================*/
template <class K, class V>
void HashMapTree<K, V>::insert(const K &key, const V &value) {
    long index = hash_func.getHash(key);

    // Create a pair for insertion
    pair<K, V> new_pair = make_pair(key, value);

    // Search for an existing key
    RBTreeNode<pair<K, V>> *node = map[index].search(new_pair);

    if (node != nullptr) {
        // Key exists, update the value
        node->value().second = value;
    } else {
        // Key doesn't exist, insert a new pair
        cout << "Inserting key: " << key << ", value: " << value << endl;
        map[index].insert(new_pair);
        ++elements; // Update the count of elements in the hash map
    }
}

/*===========================================================================
search() function
Search for a pair key-value using a key. If the pair doesn't exist, return
null pointer
Parameters: key of type K
Return: Pointer to the key-value pair or null pointer
===========================================================================*/
template <class K, class V>
std::pair<K, V>* HashMapTree<K, V>::search(const K &key) {
    long index = hash_func.getHash(key);  

    // Search for the pair (key, default-constructed value)
    RBTreeNode<std::pair<K, V>>* node = map[index].search(make_pair(key, V()));

    // If the node is found, return a pointer to the value (pair)
    if (node != nullptr) {
        return &node->value();  
    }

    return nullptr;  // Return nullptr if the key was not found
}

/*===========================================================================
remove() function
Takes a pointer to the element to be removed and removes it from the data
structure.
Parameters: Pointer to pair to be removed
Return: None
===========================================================================*/
template <class K, class V>
void HashMapTree<K, V>::remove(pair<K, V>* remove_pair)
{
   long index = hash_func.getHash(remove_pair->first); 
   if (map[index].search(*remove_pair))
   {
       map[index].remove(*remove_pair); 
       elements--;
   }
   else
   {
        throw key_not_found_exception("Key not found during removal.");
   }
}

/*===========================================================================
The copy helper function
Copy a hashmap to a new hashmap both with type K keys and type T values
Parameters: A hashmap
Return: None
===========================================================================*/
template <class K, class V>
void HashMapTree<K, V>::copy(const HashMapTree<K, V> &other) {
    slots = other.slots;
    elements = other.elements;
    hash_func = other.hash_func;

    map = new RBTree<pair<K, V>>[slots];
    for (long i = 0; i < slots; ++i) {
        map[i] = other.map[i]; // Use the RBTree's assignment operator
    }
}


