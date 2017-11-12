#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

template<class RandomIt>
void print_range(RandomIt first, RandomIt last) {
        for (auto k = first; k != last; ++k) {
            std::cout << *k << " ";
        }
        std::cout << '\n';
}


#endif // PRINT_HPP
