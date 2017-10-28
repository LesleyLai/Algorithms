#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <iterator>
#include <vector>

template<class RandomIt, class Compare=std::less<typename RandomIt::value_type>>
void merge_sort(RandomIt first, RandomIt last, Compare comp=std::less<typename RandomIt::value_type>{});

template<class Container>
void merge_sort(Container& c) {
    merge_sort(c.begin(), c.end());
}

namespace details {
template<class RandomIt, class Compare>
void merge(RandomIt first, RandomIt middle, RandomIt last, RandomIt scratch, Compare comp) {
    auto itr1 = first, itr2 = middle;
    for (; itr1 != middle; ++scratch) {
        if (itr2 == last) {
            std::copy(itr1, middle, scratch);
            return;
        }
        if (comp(*itr2, *itr1)) {
            *scratch = *itr2;
            ++itr2;
        } else {
            *scratch = *itr1;
            ++itr1;
        }
    }
    std::copy(itr2, last, scratch);
}

template<class RandomIt, class Compare>
void merge_sort_helper(RandomIt first, RandomIt last, RandomIt scratch, Compare comp) {
    auto diff = last - first;
    if (diff <= 1) return;
    auto middle = first + diff / 2;
    merge_sort_helper(first, middle, scratch, comp);
    merge_sort_helper(middle, last, scratch, comp);

    // Merge
    merge(first, middle, last, scratch, comp);
    std::copy(scratch, scratch + diff, first);
}
}



template<class RandomIt, class Compare>
void merge_sort(RandomIt first, RandomIt last, Compare comp) {
    std::vector<typename RandomIt::value_type> scratch;
    scratch.reserve(static_cast<size_t>(last - first));
    details::merge_sort_helper(first, last, begin(scratch), comp);
}


#endif // MERGE_SORT_HPP
