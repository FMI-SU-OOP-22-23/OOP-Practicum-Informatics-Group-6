#include <iostream>

enum Season
{
    S_UNKNOWN = -1,
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER,
    S_COUNTER
};

const char* seasons[] = {"Spring", "Summer", "Autumn", "Winter"};

void printSeason(Season season)
{
    if (season <= S_UNKNOWN || season >= S_COUNTER)
    {
        std::cout << "Unknown season" << std::endl;
        return;
    }

    std::cout << seasons[season] << std::endl;
}

void printSeasons()
{
    for (std::size_t i = S_UNKNOWN + 1; i < S_COUNTER; ++i)
    {
        printSeason((Season)i);
    }
}

enum Animal
{
    A_UNKNOWN = -1,
    BIRD,
    DOG,
    CAT,
    A_COUNTER
};

int main ()
{
    std::cout << S_UNKNOWN << std::endl;
    std::cout << SPRING << std::endl;
    std::cout << SUMMER << std::endl;
    std::cout << AUTUMN << std::endl;
    std::cout << WINTER << std::endl;
    std::cout << S_COUNTER << std::endl;

    printSeason(SUMMER);

    printSeasons();

    return 0;
}