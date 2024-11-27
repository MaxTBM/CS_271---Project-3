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

class KeyNotFoundException : public std::exception {
private:
    std::string message;

public:
    // Template constructor to handle any type
    template <typename T>
    explicit KeyNotFoundException(const T &any) {
        std::ostringstream oss;
        oss << "'" << any << "' not found.";
        message = oss.str();
    }

    // Override what() to return the message
    const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif