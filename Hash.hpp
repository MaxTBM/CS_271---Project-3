/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
Hash.hpp
This file contains the definitions of a hash function class.
===========================================================================*/

#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

#ifndef HASH_HPP
#define HASH_HPP



template <class K>  
class Hash
{
    private:
        // Size of the hash map (number of slots)
        long            slots;
    public:
        			    Hash		                    (long num_slots = 20);
					    Hash                            (const Hash<K>& other);
					    ~Hash		                    (void);

        Hash<K>&        operator=                       (const Hash<K>& other);
                    
        long            getHash                         (K key);
};

#include "Hash.cpp"

#endif