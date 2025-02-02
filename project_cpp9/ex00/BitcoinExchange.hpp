#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, double> database;

    void loadDatabase(const std::string& filename);
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const double value) const;
    std::string findClosestDate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInputFile(const std::string& filename) const;
    double getExchangeRate(const std::string& date) const;
};

#endif // BITCOINEXCHANGE_HPP