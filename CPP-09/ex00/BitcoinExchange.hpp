#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, double> _database; // Stores date -> BTC price

    bool        _loadDatabase(const std::string& filename);
    bool        _isValidDate(const std::string& date) const;
    bool        _isValidValue(const std::string& valueStr, double& value) const;
    std::string _trim(const std::string& str) const;
    double      _findClosestPrice(const std::string& date) const;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInputFile(const std::string& filename);
};

#endif