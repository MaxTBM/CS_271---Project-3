/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the definitions of a hash map class. Using vector to handle
chaining.
===========================================================================*/

#include <iostream>
#include <utility>
#include <vector>


using namespace std;

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "Hash.cpp"

template <class K, class V> 
class HashMap
{
    private:
        // Dynamic array of vectors
        vector<pair<K, V>>* map;

        // Size of the hash map (number of slots) 
        long                slots;
        // Number of key-value pairs in the map
        long                elements;
        // Hash function instance
        Hash<K>             hash_func;

        // Helper function for copy constructor and assignment
        void                copy                            (const HashMap<K, V> &other);        

    public:
						    HashMap		                    (long size = 20); // Assume the map has 20 slots if no input in provided
						    HashMap		                    (const HashMap<K, V> &other);
						    ~HashMap		                (void);

		HashMap<K, V>&		operator=	                    (const HashMap<K, V> &other);
        V&                  operator[]                      (const K &key);

        void                insert                          (const K &key, const V &value);
        void                remove                          (pair<K, V>* remove_pair);
        pair<K, V>*         search                          (const K &key);
};

#endif