#include <fstream>
#include <stdexcept>
#include "file2ints.hpp"

std::vector<int> file2ints(std::string& filename) {
    std::ifstream file {filename};
    if (!file.is_open()) throw std::runtime_error{"Cannot open file " + filename};

    std::vector<int> ints;
    std::string line;
    while (std::getline(file, line)) {
        ints.push_back(std::stoi(line));
    }
    return ints;
}
