#pragma once

#include "myString.h"

class Vehicle
{
private:
    MyString m_registration;
    MyString m_description;
    std::size_t m_space;

public:
    Vehicle(const char* registration, 
        const char* description, std::size_t space);

    const char* registration() const;
    const char* description() const;
    std::size_t space() const;
};