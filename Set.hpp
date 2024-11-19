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

template <class T> 
class Set
{
    private:

    public:
						        Set		                (T size);
						        Set		                (const Set<T> &set);
						        ~Set		            (void);
                                
		Set<T>*                 operator=	            (const Set<T> &set);

        void                    insert                  (const T &value);
        void                    remove                  (const T &value);
        bool                    search                  (const T &value);
};

#endif