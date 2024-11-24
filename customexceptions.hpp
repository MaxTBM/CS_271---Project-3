/*===========================================================================
Hoa Nguyen, Nguyen Nguyen, Amaya Joshi
18 November 2024
HashMap.hpp
This file contains the custom exceptions for all of our programs.
===========================================================================*/

#include <iostream>
#include <exception>
#include <string>
using namespace std;

#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

class KeyNotFoundException : public exception {
private:
    string message;

public:
    explicit KeyNotFoundException(const string &msg) : message(msg) {}
    const char *what() const noexcept override {
        return ("Key not found: " + message).c_str();
    }
};

#endif