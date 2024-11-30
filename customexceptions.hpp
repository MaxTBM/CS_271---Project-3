/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the custom exceptions for all of our programs.
===========================================================================*/

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using namespace std;

#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

class key_not_found_exception : public exception
{
private:
    string message;

public:
    // Template constructor to handle any type
    template <typename T>
    explicit key_not_found_exception(const T &any)
    {
        ostringstream oss;
        oss << "Key '" << any << "' not found.";
        message = oss.str();
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class value_not_in_tree_exception : public exception
{
public:
    const char *what() const throw()
    {
        return "Error: The value is not in the tree.";
    }
};

class empty_tree_exception : public exception
{
public:
    const char *what() const throw()
    {
        return "Error: This is an empty tree.";
    }
};
#endif