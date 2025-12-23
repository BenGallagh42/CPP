#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>  // C++98 for uintptr_t, because it can stock any pointer
#include "Data.hpp"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
    // Convert pointer to unsigned integer
    static uintptr_t serialize(Data* ptr);
    
    // Convert unsigned integer back to pointer
    static Data* deserialize(uintptr_t raw);
};

#endif