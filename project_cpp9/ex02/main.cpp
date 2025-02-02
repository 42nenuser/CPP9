#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive_integer1> <positive_integer2> ..." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}