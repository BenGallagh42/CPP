#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T*              _elements;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    // Subscript operator: access element (modifiable)
    T& operator[](unsigned int index);
    
    // Subscript operator: access element (const)
    const T& operator[](unsigned int index) const;
    
    // Returns number of elements
    unsigned int size() const;
};

#include "Array.tpp"

#endif