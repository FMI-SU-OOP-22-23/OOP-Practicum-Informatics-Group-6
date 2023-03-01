#include <iostream>

enum CustomFlags : unsigned char
{
    FLAG1 = 1,
    FLAG2 = (1<<1),
    FLAG3 = (1<<2),
    FLAG4 = (1<<3),
    FLAG5 = (1<<4),
    FLAG6 = (1<<5),
    FLAG7 = (1<<6),
    FLAG8 = (1<<7),
};


struct CustomMode
{
    union
    {
        unsigned char value;
        struct
        {
            unsigned char f1 : 1, f2 : 1, f3 : 1, f4 : 1, f5 : 1, f6 : 1, f7 : 1, f8 : 1;
        };
    };
};

int main ()
{
}
