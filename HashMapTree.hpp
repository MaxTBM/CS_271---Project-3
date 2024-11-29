/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the definitions of a hash map tree class.
===========================================================================*/

#include <iostream>
#include <utility>

using namespace std;

#ifndef HASHMAPTREE_HPP
#define HASHMAPTREE_HPP

#include "RBTree.cpp"
#include "Hash.cpp"

template <class K, class V> 
class HashMapTree
{
    private:

    public:
						        HashMapTree		                (long size = 20); // Assume the map has 20 slots if no input in provided
						        HashMapTree		                (const HashMapTree<K, V> &other);
						        ~HashMapTree		            (void);

		HashMapTree<K, V>&      operator=	                    (const HashMapTree<K, V> &other);
        V&                      operator[]                      (const K &key);

        void                    insert                          (const K &key, const V &value);
        void                    remove                          (pair<K, V>* remove_pair);
        pair<K, V>*             search                          (const K &key);
};

#endif