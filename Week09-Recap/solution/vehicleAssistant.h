#pragma once

#include "vehicle.h"

class VehicleAssistant
{
private:
    static const std::size_t INITIAL_CAPACITY = 2;
    static const std::size_t INCREASE_STEP = 2;

    Vehicle** vehicles;
    std::size_t m_size;
    std::size_t m_capacity;

    void resize();

public:
    VehicleAssistant();
    VehicleAssistant(const VehicleAssistant& other) = delete;
    VehicleAssistant& operator = (const VehicleAssistant& other) = delete;
    ~VehicleAssistant();

    Vehicle* allocateNewVehicle(const char* registration, const char* desctiption, std::size_t space);
};