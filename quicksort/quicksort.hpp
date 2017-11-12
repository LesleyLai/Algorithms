#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <functional>
#include <random>

namespace detail {

// Partitioning around the nth term
// Return the pivot location after partition
template<class RandomIt, class Compare=std::less<typename RandomIt::value_type>>
RandomIt partition(RandomIt first, RandomIt pivot, RandomIt last, Compare comp=std::less<typename RandomIt::value_type>{}) {
    const auto pivot_value = *pivot;

    std::iter_swap(first, pivot);

    auto i = first + 1;
    for (auto j = first + 1; j < last; ++j) {
        if (comp(*j, pivot_value)) {
            std::swap(*i, *j);
            ++i;
        }
    }

    std::iter_swap(first, i-1);
    return i-1;
}

}

template<class RandomIt, class Compare=std::less<typename RandomIt::value_type>>
void quicksort(RandomIt first, RandomIt last, Compare comp=std::less<typename RandomIt::value_type>{}) {

    // Base case
    auto size = last - first;
    if (size <= 1) {
        return;
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size-1);

    // Recursive case
    RandomIt pivot = first + dis(gen);
    pivot = detail::partition(first, pivot, last, comp);

    quicksort(first, pivot, comp);
    quicksort(pivot+1, last, comp);
}

#endif // QUICKSORT_HPP
