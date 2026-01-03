#include "BitcoinExchange.hpp"
#include <fstream>      // std::ifstream
#include <iostream>     // std::cout, cerr, endl
#include <cstdlib>      // std::atof, atoi, strtod

BitcoinExchange::BitcoinExchange()
{
    _loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    _database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return (*this);
}

// Removes spaces from start and end of string & return substring
std::string BitcoinExchange::_trim(const std::string& str) const
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;
    return (str.substr(start, end - start));
}

// Loads CSV database into map (date -> price)
bool BitcoinExchange::_loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str()); // Casting string to const char* for C++98
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return (false);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t commaPosition = line.find(',');
        if (commaPosition == std::string::npos)
            continue;                               // If no ',' in line, continue to next line

        std::string date = line.substr(0, commaPosition);
        std::string priceStr = line.substr(commaPosition + 1); // No second parameter = till the end of the string

        double price = std::atof(priceStr.c_str()); // ascii to float
        _database[date] = price; // Stores in map container
    }

    file.close();
    return (true);
}

// Checks if date format is YYYY-MM-DD and values are valid
bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    // Check for format: YYYY-MM-DD
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);

    // Check that numbers are between 0 and 9
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return (false);
    }

    // Convert ascii to int
    int year = std::atoi(date.substr(0, 4).c_str()); // Substract 4 char from position 0
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    // Final checks
    if (year < 1000 || year > 9999)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);

    return (true);
}

// Validates value: must be float/int between 0 and 1000
bool BitcoinExchange::_isValidValue(const std::string& valueStr, double& value) const
{
    char* endPtr;
    value = std::strtod(valueStr.c_str(), &endPtr); // Convert string to double

    // Check for invalid characters in the string
    if (*endPtr != '\0' && *endPtr != ' ' && *endPtr != '\t')
        return (false);

    // Check value makes sense
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }
    
    return (true);
}

// Finds closest LOWER date in database using lower_bound
double BitcoinExchange::_findClosestPrice(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    // Return an iterator to the first element with a key >= (date), or .end() if no element found

    // If exact date in database
    if (it != _database.end() && it->first == date)
        return (it->second);

    // Return error if (date)is inferior to all dates in database
    if (it == _database.begin())
        return (-1.0);

    --it; // Move to previous (lower) date
    return (it->second);
}

// Processes input file line by line
void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header of csv file

    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = _trim(line.substr(0, pipePos));
        std::string valueStr = _trim(line.substr(pipePos + 1));

        if (!_isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        if (!_isValidValue(valueStr, value))
            continue;

        double price = _findClosestPrice(date);
        if (price < 0)
        {
            std::cerr << "Error: date too early." << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * price) << std::endl;
    }

    file.close();
}