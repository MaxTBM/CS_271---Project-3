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

class KeyException : public exception {
private:
    string message;

public:
    explicit KeyException(const string &msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif