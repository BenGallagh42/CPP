#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "=== Basic tests ===" << std::endl;
    Fixed a(5.5f);
    std::cout << "a = " << a << " (Expected result : 5.5)" << std::endl;
    Fixed b(2);
    std::cout << "b = " << b << " (Expected result : 2.0)" << std::endl;
    Fixed c(a);
    std::cout << "c = " << c << " (Expected result : 5.5)" << std::endl;
    std::cout << std::endl;

    std::cout << "===  Comparison operators tests ===" << std::endl;
    std::cout << "a > b : " << (a > b) << " (Expected result : 1)" << std::endl;
    std::cout << "a < b : " << (a < b) << " (Expected result : 0)" << std::endl;
    std::cout << "a >= b : " << (a >= b) << " (Expected result : 1)" << std::endl;
    std::cout << "a <= b : " << (a <= b) << " (Expected result : 0)" << std::endl;
    std::cout << "a == c : " << (a == c) << " (Expected result : 1)" << std::endl;
    std::cout << "a != b : " << (a != b) << " (Expected result : 1)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Arithmetic operators tests ===" << std::endl;
    Fixed d = a + b;
    std::cout << "a + b = " << d << " (Expected result : 7.5)" << std::endl;
    Fixed e = a - b;
    std::cout << "a - b = " << e << " (Expected result : 3.5)" << std::endl;
    Fixed f = a * b;
    std::cout << "a * b = " << f << " (Expected result : 11.0)" << std::endl;
    Fixed g = a / b;
    std::cout << "a / b = " << g << " (Expected result : 2.75)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Increment/decrement tests ===" << std::endl;
    Fixed i(0.0f);
    std::cout << "i = 0" << std::endl;
    std::cout << "++i = " << ++i << " (Expected result : 0.00390625)" << std::endl;
    std::cout << "i = " << i << " (Expected result : 0.00390625)" << std::endl;
    std::cout << "i++ = " << i++ << " (Expected result : 0.00390625)" << std::endl;
    std::cout << "i = " << i << " (Expected result : 0.0078125)" << std::endl;
    std::cout << "--i = " << --i << " (Expected result : 0.00390625)" << std::endl;
    std::cout << "i-- = " << i-- << " (Expected result : 0.00390625)" << std::endl;
    std::cout << "i = " << i << " (Expected result : 0.0)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Static functions tests ===" << std::endl;
    Fixed j(3.0f);
    std::cout << "j = 3" << std::endl;
    Fixed k(1.5f);
    std::cout << "k = 1.5" << std::endl;
    std::cout << "min(j, k) = " << Fixed::min(j, k) << " (Expected result : 1.5)" << std::endl;
    std::cout << "max(j, k) = " << Fixed::max(j, k) << " (Expected result : 3.0)" << std::endl;

    return 0;
}