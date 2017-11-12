#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <algorithm>
#include <vector>

#include "quicksort.hpp"

TEST_CASE("Quick sort") {
    SUBCASE("Sort a small list") {
        std::vector<int> v {5, 43, 43, 21, 31, 12};
        quicksort(v.begin(), v.end());
        CHECK(is_sorted(v.cbegin(), v.cend()));
    }

    SUBCASE("Sort a reversed list") {
        std::vector<int> v {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        quicksort(v.begin(), v.end());
        CHECK(is_sorted(v.cbegin(), v.cend()));
    }
}
