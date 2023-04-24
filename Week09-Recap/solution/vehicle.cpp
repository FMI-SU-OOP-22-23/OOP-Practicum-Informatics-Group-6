#include "vehicle.h"

Vehicle::Vehicle(const char* registration, 
        const char* description, std::size_t space)
    : m_registration(registration), m_description(description), 
        m_space(space) {}

const char* Vehicle::registration() const
{
    return m_registration.c_str();
}

const char* Vehicle::description() const
{
    return m_description.c_str();
}

std::size_t Vehicle::space() const
{
    return m_space;
}