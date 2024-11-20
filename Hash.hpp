/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
Hash.hpp
This file contains the definitions of a hash function class.
===========================================================================*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#ifndef HASH_HPP
#define HASH_HPP

const double A = 0.69;

template <class K> 
class Hash
{
    private:
        // Size of the hash map (number of slots) 
        long        slots;
    public:
        			Hash		                    (long num_slots);
					Hash                            (const Hash<K>& other);
					~Hash		                    (void);
                    
        long        func                            (const K& key) const;
};


#include "Hash.cpp"

#endif