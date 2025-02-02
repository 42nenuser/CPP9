#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.processInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << "this is Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}