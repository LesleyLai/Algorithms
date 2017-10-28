add_executable(${PROJECT_NAME}_merge_sort
    "merge_sort.hpp"
    "main.cpp")

target_link_libraries(${PROJECT_NAME}_merge_sort UnitTest)
