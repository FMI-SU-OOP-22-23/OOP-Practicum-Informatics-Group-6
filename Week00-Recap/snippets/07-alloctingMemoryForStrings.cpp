#include <iostream>
#include <cstring>

const std::size_t MAX_SIZE = 256;

int main ()
{
    char buffer[256];
    std::cin >> buffer;

    char* str = new (std::nothrow) char[strlen(buffer) + 1];
    if (!str)
    {
        std::cout << "Memory problem" << std::endl;
        return 1;
    }
    strcpy(str, buffer);

    std::cout << str << std::endl;

    delete[] str;
    
    return 0;
}