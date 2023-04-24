#include "vehicleAssistant.h"

VehicleAssistant::VehicleAssistant()
    : m_size(0), m_capacity(INITIAL_CAPACITY)
{
    this->vehicles = new Vehicle*[INITIAL_CAPACITY];
}

VehicleAssistant::~VehicleAssistant()
{
    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        delete this->vehicles[i];
    }
    delete[] this->vehicles;
}

void VehicleAssistant::resize()
{
    Vehicle** newVehicles = new Vehicle*[this->m_capacity * INCREASE_STEP];

    for (std::size_t i = 0; i < this->m_size; ++i)
    {
        newVehicles[i] = this->vehicles[i];
    }

    delete[] this->vehicles;
    this->vehicles = newVehicles;
    this->m_capacity *= INCREASE_STEP;
}

Vehicle* VehicleAssistant::allocateNewVehicle(const char* registration, const char* desctiption, std::size_t space)
{
    if (this->m_size == this->m_capacity)
    {
        resize();
    }

    this->vehicles[this->m_size++] = new Vehicle(registration, desctiption, space);

    return this->vehicles[this->m_size - 1];
}