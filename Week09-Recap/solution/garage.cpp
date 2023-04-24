#include "garage.h"
#include <cstring>
#include <cassert>

Garage::Garage(std::size_t size)
    : maxCapacity(size), numberOfCars(0), currentCapacity(0)
{
    this->vehicles = new Vehicle*[size]{};
}

void Garage::copy(const Garage& other)
{
    this->maxCapacity = other.maxCapacity;
    this->numberOfCars = other.numberOfCars;
    this->currentCapacity = other.currentCapacity;

    this->vehicles = new Vehicle*[other.maxCapacity];
    for (std::size_t i = 0; i < other.numberOfCars; ++i)
    {
        this->vehicles[i] = other.vehicles[i];
    }
}

void Garage::deallocate()
{
    delete[] this->vehicles;
}

Garage::Garage(const Garage& other)
{
    this->copy(other);
}

Garage& Garage::Garage::operator = (const Garage& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Garage::~Garage()
{
    this->deallocate();
}

void Garage::insert(Vehicle& v)
{
    if (this->currentCapacity + v.space() > this->maxCapacity)
    {
        throw std::overflow_error("Not enough capacity!");
    }

    if (this->find(v.registration()))
    {
        throw std::invalid_argument("Vehicle with such registration already exists!");
    }

    this->vehicles[this->numberOfCars++] = &v;
    this->currentCapacity += v.space();
}

void Garage::erase(const char* registration)
{
    const Vehicle* vehicle = this->find(registration);

    if (!vehicle)
    {
        return;
    }

    this->currentCapacity -= vehicle->space();
    vehicle = this->vehicles[this->numberOfCars - 1];
    this->vehicles[--this->numberOfCars] = nullptr;
}

const Vehicle& Garage::at(std::size_t pos) const
{
    if (this->numberOfCars <= pos)
    {
        throw std::out_of_range("Invalid index!");
    }

    return *this->vehicles[pos];
}

const Vehicle& Garage::operator[](std::size_t pos) const
{
    assert(this->numberOfCars > pos);

    return *this->vehicles[pos];
}

bool Garage::empty() const
{
    return this->numberOfCars == 0;
}

std::size_t Garage::size() const
{
    return this->numberOfCars;
}

void Garage::clear()
{
    this->numberOfCars = 0;
    this->currentCapacity = 0;
}

const Vehicle* Garage::find(const char* registration) const
{
    for (std::size_t i = 0; i < this->numberOfCars; ++i)
    {
        if (strcmp(this->vehicles[i]->registration(), registration) == 0)
        {
            return this->vehicles[i];
        }
    }

    return nullptr;
}

