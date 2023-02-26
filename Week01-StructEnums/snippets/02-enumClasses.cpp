#include <iostream>

enum class Season
{
    UNKNOWN = -1,
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER,
    COUNTER
};

const char* seasons[] = {"Spring", "Summer", "Autumn", "Winter"};

void printSeason(Season season)
{
    if (season <= Season::UNKNOWN || season >= Season::COUNTER)
    {
        std::cout << "Unknown season" << std::endl;
        return;
    }

    std::cout << seasons[(int)season] << std::endl;
}

void printSeasons()
{
    for (std::size_t i = (int)Season::UNKNOWN + 1; i < (int)Season::COUNTER; ++i)
    {
        printSeason((Season)i);
    }
}

enum Animal
{
    UNKNOWN = -1,
    BIRD,
    DOG,
    CAT,
    COUNTER
};

int main ()
{
    std::cout << (int)Season::AUTUMN << std::endl;

    printSeasons();

    std::cout << (int)Season::COUNTER << " " << (int)Animal::COUNTER << std::endl;
}