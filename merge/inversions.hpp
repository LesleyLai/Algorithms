#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP

#include "merge_sort.hpp"

template<class RandomIt, class Compare=std::less<typename RandomIt::value_type>>
int count_inversions(RandomIt first, RandomIt last, Compare comp=std::less<typename RandomIt::value_type>{});

template<class Container>
int count_inversions(Container& c) {
    return count_inversions(c.begin(), c.end());
}

namespace details {
template<class RandomIt, class Compare>
int count_split_inversions(RandomIt first, RandomIt middle, RandomIt last, RandomIt scratch, Compare comp) {
    auto inversions = 0;

    auto itr1 = first, itr2 = middle;
    for (; itr1 != middle; ++scratch) {
        if (itr2 == last) {
            std::copy(itr1, middle, scratch);
            return inversions;
        }
        if (comp(*itr2, *itr1)) {
            *scratch = *itr2;
            inversions += (middle - itr1);
            ++itr2;
        } else {
            *scratch = *itr1;
            ++itr1;
        }
    }
    std::copy(itr2, last, scratch);
    return inversions;
}

template<class RandomIt, class Compare>
int count_inversions_helper(RandomIt first, RandomIt last, RandomIt scratch, Compare comp) {
    auto diff = last - first;
    if (diff <= 1) return 0;
    auto middle = first + diff / 2;

    auto inversions = 0;
    inversions += count_inversions_helper(first, middle, scratch, comp);
    inversions += count_inversions_helper(middle, last, scratch, comp);

    // Merge
    inversions += count_split_inversions(first, middle, last, scratch, comp);
    std::copy(scratch, scratch + diff, first);
    return inversions;
}
}



template<class RandomIt, class Compare>
int count_inversions(RandomIt first, RandomIt last, Compare comp) {
    std::vector<typename RandomIt::value_type> scratch;
    scratch.reserve(static_cast<size_t>(last - first));
    return details::count_inversions_helper(first, last, begin(scratch), comp);
}

#endif // INVERSIONS_HPP
