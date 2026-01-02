#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm> // sort, min_element and max_element
#include <exception>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers; // Vector for dynamic size + fast sorting

public:
    Span(unsigned int N); // Unsigned as cannot be negative
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    // Add multiple numbers at once using iterators
	// Template function = must be in header
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