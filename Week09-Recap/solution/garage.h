#pragma once

#include "vehicle.h"

class Garage
{
private:
    std::size_t maxCapacity;
    std::size_t currentCapacity;
    std::size_t numberOfCars;
    Vehicle** vehicles;

    void copy(const Garage& other);
    void deallocate();

public:
    Garage(std::size_t size);

    Garage(const Garage& other);
    Garage& operator = (const Garage& other);
    ~Garage();

    void insert(Vehicle& v);
    void erase(const char* registration);

    const Vehicle& at(std::size_t pos) const;
    const Vehicle& operator[](std::size_t pos) const;

    bool empty() const;
    std::size_t size() const;
    void clear();

    const Vehicle* find(const char* registration) const;
};