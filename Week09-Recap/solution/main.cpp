#include <iostream>
#include "vehicleAssistant.h"
#include "garage.h"

int main ()
{
    VehicleAssistant assistant;

    Vehicle* v1 = assistant.allocateNewVehicle("V5385PK", "Peugeot 206 SW", 3);
    Vehicle* v2 = assistant.allocateNewVehicle("VT1234KN", "Fiat Punto", 1);
    Vehicle* v3 = assistant.allocateNewVehicle("SV6900SS", "KIA XCeed", 2);

    Garage g(5);

    g.insert(*v1);
    g.insert(*v2);

    try 
    {
        g.insert(*v3);
    }
    catch (std::overflow_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    for (std::size_t i = 0; i < g.size(); ++i)
    {
        std::cout << g[i].registration() << std::endl;
    }

    return 0;
}