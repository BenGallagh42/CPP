#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // for std::find
#include <exception>

// Finds an integer in any container
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
    {
        throw std::exception();
    }
    
    return it;
}

#endif