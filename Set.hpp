/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the definitions of a set class.
===========================================================================*/

#include <iostream>
#include <utility>

using namespace std;

#ifndef SET_HPP
#define SET_HPP

#include "HashMap.hpp"

template <class T> 
class Set
{
    private:
        HashMap<T, bool>        map;

    public:
						        Set		                (long size = 20);
						        Set		                (const Set<T> &other);
						        ~Set		            (void);
                                
		Set<T>&                 operator=	            (const Set<T> &other);

        void                    insert                  (const T &value);
        void                    remove                  (const T &value);
        bool                    search                  (const T &value);
};

#endif