#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <limits>

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database(other.database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;

        if (std::getline(iss, date, ',') && std::getline(iss, value)) {
            database[date] = std::atof(value.c_str());
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    return true;
}

bool BitcoinExchange::isValidValue(const double value) const {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);
    if (it == database.begin()) {
        return it->first;
    } else if (it == database.end() || it->first != date) {
        --it;
    }
    return it->first;
}

void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string valueStr;

        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

            if (!isValidDate(date)) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }

            double value;
            std::istringstream(valueStr) >> value;

            if (!isValidValue(value)) {
                if (value < 0) {
                    std::cout << "Error: not a positive number." << std::endl;
                } else {
                    std::cout << "Error: too large a number." << std::endl;
                }
                continue;
            }

            std::string closestDate = findClosestDate(date);
            double exchangeRate = getExchangeRate(closestDate);
            double result = value * exchangeRate;

            std::cout << date << " => " << value << " = " << result << std::endl;
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = database.find(date);
    if (it != database.end()) {
        return it->second;
    }
    return 0.0;
}