#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <iostream>
#include <random>
#include <vector>

#include "merge_sort.hpp"
#include "inversions.hpp"

template<class Container>
void fill_random_ints(Container& c, int min, int max) {
    std::random_device rd;
    std::mt19937 genenator(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (auto& elem : c) {
        elem = dis(genenator);
    }
}

TEST_CASE("Merge sort") {
    SUBCASE("merge sort with empty vector") {
        std::vector<int> v;
        merge_sort(v);
        CHECK(is_sorted(v.cbegin(), v.cend()));
    }


    SUBCASE("merge sort with large vector") {
//        std::vector<int> v(200);
//        fill_random_ints(v, 0, 500);
        std::vector<int> v{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        merge_sort(v);
        CHECK(is_sorted(v.cbegin(), v.cend()));
    }
}

TEST_CASE("Count inversions") {
    SUBCASE("Inversions of empty vector should be zero") {
        std::vector<int> v;
        CHECK_EQ(count_inversions(v), 0);
    }

    SUBCASE("Inversions of ordered vector should be zero") {
        std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        CHECK_EQ(count_inversions(v), 0);
    }

    SUBCASE("Inversions of two numbers") {
        std::vector<int> v {2,1};
        CHECK_EQ(count_inversions(v), 1);
    }

    SUBCASE("Inversions of reversed vector is n(n-1)/2") {
        std::vector<int> v {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        CHECK_EQ(count_inversions(v), 45);
    }

}
