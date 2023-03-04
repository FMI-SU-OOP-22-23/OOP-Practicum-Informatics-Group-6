#include <iostream>

struct RGB
{
    unsigned int red: 8;
    unsigned int green: 8;
    unsigned int blue: 8;
};

void printRGB(const RGB& rgb);

int main ()
{
    RGB yellow{255, 255, 0};

    printRGB(yellow);

    return 0;
}

void printRGB(const RGB& rgb)
{
    std::cout << "(" << rgb.red << ", " << rgb.green 
        << ", " << rgb.blue << ")" << std::endl;
}