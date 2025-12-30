#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
    {
        throw std::exception();
    }
    _numbers.push_back(number);
}

// Find smallest difference between two numbers
int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::exception();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 0; i < sorted.size() - 1; i++)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
        {
            minSpan = span;
        }
    }

    return (minSpan);
}

// Find largest difference between two numbers
int Span::longestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::exception();
    }

    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

    return (*max - *min);
}