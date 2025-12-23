#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;

}
ScalarConverter::~ScalarConverter() {}

// Check if string is a char literal ('a')
bool ScalarConverter::isChar(const std::string& str)
{
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

// Check if string is an integer
bool ScalarConverter::isInt(const std::string& str)
{
    if (str.empty())
        return false;
    
    size_t i = 0;
    
    // Handle optional sign
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    // Must have at least one digit
    if (i >= str.length())
        return false;
    
    // Check all remaining characters are digits
    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    return true;
}

// Check if string is a float
bool ScalarConverter::isFloat(const std::string& str)
{
    if (str.empty() || str.length() < 2)
        return false;
    
    if (str[str.length() - 1] != 'f')
        return false;
    
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;
    
	// Must contain exactly one dot
    size_t dotCount = 0;
    size_t dotPos = std::string::npos;
    for (size_t i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            dotPos = i;
        }
    }
    
    if (dotCount != 1)
        return false;
    
    // Check format: [+/-]digits.digits[f]
    size_t i = 0;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    // Must have at least one digit before dot
    if (i >= dotPos)
        return false;
    
    // Check digits before dot
    while (i < dotPos)
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    // Skip dot
    i++;
    
    // Must have at least one digit after dot
    if (i >= str.length() - 1)
        return false;
    
    // Check digits after dot (before 'f')
    while (i < str.length() - 1)
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    return true;
}

// Check if string is a double
bool ScalarConverter::isDouble(const std::string& str)
{
    if (str.empty())
        return false;
    
    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
        return true;
    
    // Must contain exactly one dot
    size_t dotCount = 0;
    size_t dotPos = std::string::npos;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            dotPos = i;
        }
    }
    
    if (dotCount != 1)
        return false;
    
    // Check format: [+/-]digits.digits
    size_t i = 0;
    
    // Optional sign
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    // Must have at least one digit before dot
    if (i >= dotPos)
        return false;
    
    // Check digits before dot
    while (i < dotPos)
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    // Skip dot
    i++;
    
    // Must have at least one digit after dot
    if (i >= str.length())
        return false;
    
    // Check digits after dot
    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    return true;
}

// Check if string is a pseudo-literal
bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff" ||
            str == "inf" || str == "inff");
}

// Print conversion to char
void ScalarConverter::printChar(double value, bool impossible)
{
    std::cout << "char: ";
    
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

// Print conversion to int
void ScalarConverter::printInt(double value, bool impossible)
{
    std::cout << "int: ";
    
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() || 
             value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

// Print conversion to float
void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) 
                  << static_cast<float>(value) << "f" << std::endl;
}

// Print conversion to double
void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) 
                  << value << std::endl;
}

// Main conversion method: detect type, convert to double, print all conversions
void ScalarConverter::convert(const std::string& literal)
{
    double value = 0;
    bool impossible = false;
    
    if (isChar(literal))
        value = static_cast<double>(literal[1]);

    else if (isPseudoLiteral(literal))
    {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf" || literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
    }

    else if (isInt(literal))
    {
        char* end;
        errno = 0;
        long l = std::strtol(literal.c_str(), &end, 10);
        
        if (*end != '\0' || errno == ERANGE)
            impossible = true;
        else
            value = static_cast<double>(l);
    }

    else if (isFloat(literal))
    {
        char* end;
        errno = 0;
        float f = std::strtof(literal.c_str(), &end);
        
        if (end == literal.c_str() || (*end != 'f' && *end != '\0') || errno == ERANGE)
            impossible = true;
        else
            value = static_cast<double>(f);
    }

    else if (isDouble(literal))
    {
        char* end;
        errno = 0;
        value = std::strtod(literal.c_str(), &end);
        
        if (end == literal.c_str() || *end != '\0' || errno == ERANGE)
            impossible = true;
    }
	
    else
        impossible = true;
    
    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value);
    printDouble(value);
}