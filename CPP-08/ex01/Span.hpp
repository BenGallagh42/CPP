#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    // Add multiple numbers at once using iterators
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }
};

#endif