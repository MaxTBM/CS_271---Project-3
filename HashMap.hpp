/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the definitions of a hash map class.
===========================================================================*/

#include <iostream>
#include <utility>

using namespace std;

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

template <class K, class V> 
class HashMap
{
    private:
        
    public:
						    HashMap		                    (void);
						    HashMap		                    (const HashMap<K, V> &map);
						    ~HashMap		                (void);
		HashMap<K, V>*		operator=	                    (const HashMap<K, V> &map);

        void                insert                          (const K &key, const V &value);
        void                remove                          (const K &key);
        V&                  operator[]                      (const K &key);
        pair<K, V>*         search                          (const K &key);
};

#endif