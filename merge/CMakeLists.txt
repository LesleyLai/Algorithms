add_executable(merge_sort
    "merge_sort.hpp"
    "inversions.hpp"
    "main.cpp")

target_link_libraries(merge_sort UnitTest Utilities)
