#include <iostream>

struct F32
{
    union
    {
        float value;
        struct
        {
            unsigned int mantisa : 23, exponent : 8, sign : 1;
        };
    };
    
    static F32 NaN()
    {
        F32 fl;
        fl.mantisa = 1;
        fl.exponent = -1;
        
        return fl;
    }
    
    static F32 plusINF()
    {
        F32 fl;
        fl.mantisa = 0;
        fl.exponent = -1;
        fl.sign = 0;
        
        return fl;
    }
    
    static F32 minusINF()
    {
        F32 fl;
        fl.mantisa = 0;
        fl.exponent = -1;
        fl.sign = 1;
        
        return fl;
    }
    
};

int main ()
{
}
