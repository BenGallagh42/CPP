#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Apply function to each element of array (modifiable version)
template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
	{
        func(array[i]);
    }
}

// Apply function to each element of array (const version)
template <typename T, typename F>
void iter(const T* array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
	{
        func(array[i]);
    }
}

#endif