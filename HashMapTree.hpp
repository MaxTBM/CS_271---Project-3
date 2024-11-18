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

template <class K, class V> 
class HashMapTree
{
    private:

    public:
						        HashMapTree		                (void);
						        HashMapTree		                (const HashMapTree<K, V> &map);
						        ~HashMapTree		            (void);
		HashMapTree<K, V>*      operator=	                    (const HashMapTree<K, V> &map);

        void                    insert                          (const K &key, const V &value);
        void                    remove                          (const K &key);
        V&                      operator[]                      (const K &key);
        pair<K, V>*             search                          (const K &key);
};

#endif